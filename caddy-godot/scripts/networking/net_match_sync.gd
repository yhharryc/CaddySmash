class_name NetMatchSync
extends Node
## Keeps one online match in step across Steam peers.
##
## Host-authoritative. The host simulates every car, fed by each owner's input,
## and broadcasts a snapshot of all of them every physics tick. On a client:
##
##   - **Your own car is predicted.** It runs the full local simulation from your
##     input the same tick you press it, so steering never waits on the network.
##     When a snapshot disagrees with what the client predicted for that same
##     input tick, the car is eased toward the host's answer rather than snapped,
##     unless it is far enough out that a snap is the lesser evil.
##   - **Everyone else's car is a puppet.** Its simulation is switched off and it
##     is interpolated between snapshots a few ticks in the past, which is what
##     keeps it smooth through jitter and the odd lost packet.
##
## Contests, damage, knockback and eliminations are decided only on the host
## (ClashArbiter refuses to score on a client) and broadcast as reliable events.
## A client replays knockback and stagger on its own predicted car so a hit lands
## the moment the event arrives, and takes health from the snapshots.
##
## Added by MatchManager as its child, after the cars exist, so it has the same
## node path on every machine and RPCs resolve.

## Ahead of the drivers (-10): a client must have its puppets in place, and the
## host must record which input each remote car is about to consume, before any
## car moves. Behind ClashArbiter (-100), which only snapshots velocities.
const _SYNC_PRIORITY := -11
## Snapshots held for interpolation. ~0.5 s at 60 Hz, far more than needed.
const _SNAPSHOT_BUFFER := 32
## Predicted states kept for reconciliation. Must cover the worst round trip.
const _HISTORY_TICKS := 120

## How far behind the newest snapshot puppets are drawn. Each tick is ~16.7 ms;
## 3 absorbs normal relay jitter. Raise it if remote cars stutter, lower it if
## they feel late.
@export_range(1, 12) var interpolation_delay_ticks: int = 3
## When snapshots stop arriving, puppets coast on their last velocity this long
## before freezing, so a short gap reads as smooth motion rather than a hitch.
@export_range(0, 30) var extrapolation_limit_ticks: int = 6
## Share of a prediction error corrected per snapshot. Lower is smoother, higher
## converges faster.
@export_range(0.05, 1.0) var correction_rate: float = 0.3
## Position error (m) ignored entirely. Float drift between machines lives here.
@export var correction_deadband: float = 0.03
## Position error (m) past which the car snaps instead of easing, e.g. respawn.
@export var snap_distance: float = 4.0
## Host waits this long for slow loaders before starting without them.
@export var ready_timeout_seconds: float = 10.0

var match_manager: MatchManager
var started := false
## Seat of this machine's player, or -1 if it has none.
var local_slot_index := -1

# Host
var _ready_peers: Dictionary = {}
## Slot index -> the owner's input tick the car consumed last physics frame.
var _applied_ticks: Dictionary = {}
var _wait_elapsed := 0.0

# Client
## [{"tick": int, "cars": {slot_index: PackedFloat32Array}}], oldest first.
var _snapshots: Array[Dictionary] = []
var _newest_snapshot_tick := -1
## Estimated host tick minus local tick.
var _tick_offset := 0.0
var _has_tick_offset := false
## Local tick -> own car's state after that tick: [x, z, yaw, vel_x, vel_z].
var _history: Dictionary = {}
var _ping_ms := -1
var _ping_elapsed := 0.0

var _overlay: Label


func _ready() -> void:
	process_physics_priority = _SYNC_PRIORITY
	_build_overlay()

	var my_peer := multiplayer.get_unique_id()
	for slot in match_manager.slots:
		if slot.peer_id == my_peer:
			local_slot_index = slot.index

	for slot in match_manager.slots:
		_configure_car(slot)

	NetworkManager.peer_left.connect(_on_peer_left)
	match_manager.player_eliminated.connect(_on_player_eliminated)
	match_manager.match_finished.connect(_on_match_finished)

	if multiplayer.is_server():
		ClashArbiter.contest_resolved.connect(_on_contest_resolved)
		for slot_index in match_manager.combats:
			var combat: VehicleCombat = match_manager.combats[slot_index]
			combat.damage_taken.connect(_on_damage_taken.bind(combat))
		_ready_peers[1] = true
		_try_start()
	else:
		_rpc_client_ready.rpc_id(1)

	_refresh_overlay()


## Nothing drives until every machine has loaded. On a client, cars that belong
## to someone else stop simulating and become puppets.
func _configure_car(slot: PlayerSlot) -> void:
	var vehicle: ArcadeVehicle = match_manager.vehicles.get(slot.index)
	if vehicle == null:
		return

	var driver := _driver_for(vehicle)
	if driver != null:
		driver.enabled = false

	if multiplayer.is_server() or slot.index == local_slot_index:
		return

	# Puppet: the host owns its motion and its state. Feel, trails and impact FX
	# keep running, since they only read what the snapshots write.
	vehicle.set_physics_process(false)
	for child in vehicle.get_children():
		if (
			child is PlayerVehicleDriver
			or child is BrakeDashSkill
			or child is VehicleCombat
			or child is VehicleMomentum
			or child is ImpactAdjudicator
		):
			child.set_physics_process(false)


func _physics_process(delta: float) -> void:
	if not started:
		if multiplayer.is_server():
			_wait_elapsed += delta
			if _wait_elapsed >= ready_timeout_seconds:
				_rpc_go.rpc()
		return

	if multiplayer.is_server():
		_host_tick()
	else:
		_client_tick()


func _process(delta: float) -> void:
	if multiplayer.is_server() or not started:
		return
	_ping_elapsed += delta
	if _ping_elapsed >= 1.0:
		_ping_elapsed = 0.0
		_rpc_ping.rpc_id(1, Time.get_ticks_msec())


func _unhandled_input(event: InputEvent) -> void:
	var key := event as InputEventKey
	if key != null and key.pressed and not key.echo and key.physical_keycode == KEY_BACKSPACE:
		NetworkManager.return_to_lobby()


# ---------------------------------------------------------------------------
# Start barrier
# ---------------------------------------------------------------------------

@rpc("any_peer", "call_remote", "reliable")
func _rpc_client_ready() -> void:
	if not multiplayer.is_server():
		return
	_ready_peers[multiplayer.get_remote_sender_id()] = true
	_try_start()


func _try_start() -> void:
	if started:
		return
	for slot in match_manager.slots:
		if not _ready_peers.has(slot.peer_id):
			_refresh_overlay()
			return
	_rpc_go.rpc()


@rpc("authority", "call_local", "reliable")
func _rpc_go() -> void:
	if started:
		return
	started = true
	for slot in match_manager.slots:
		var vehicle: ArcadeVehicle = match_manager.vehicles.get(slot.index)
		var driver := _driver_for(vehicle) if vehicle != null else null
		if driver == null or not match_manager.is_alive(slot.index):
			continue
		# The host drives every car, remote ones through their NetworkInputDevice.
		# A client drives only its own.
		driver.enabled = multiplayer.is_server() or slot.index == local_slot_index
	_refresh_overlay()


# ---------------------------------------------------------------------------
# Host
# ---------------------------------------------------------------------------

## Runs before anything moves, so the state it sends is the result of last tick,
## and the acks are the inputs last tick consumed. Then it notes which input each
## remote car is about to consume this tick, for the next snapshot to report.
func _host_tick() -> void:
	var data := PackedFloat32Array()
	var acks := PackedInt32Array()
	for slot in match_manager.slots:
		var vehicle: ArcadeVehicle = match_manager.vehicles.get(slot.index)
		if vehicle == null:
			continue
		NetVehicleState.write_vehicle(
			data,
			slot.index,
			vehicle,
			match_manager.combats.get(slot.index),
			match_manager.skills.get(slot.index),
			ClashArbiter.momentum_for(vehicle)
		)
		acks.append(_applied_ticks.get(slot.index, -1))

	_rpc_snapshot.rpc(Engine.get_physics_frames(), acks, data)

	for slot in match_manager.slots:
		if slot.device is NetworkInputDevice:
			_applied_ticks[slot.index] = (slot.device as NetworkInputDevice).latest_tick


## A client's input for one of its ticks. Unreliable: a lost frame is replaced by
## the next one a tick later, which is sooner than any resend could arrive.
@rpc("any_peer", "call_remote", "unreliable")
func _rpc_input(tick: int, frame: PackedFloat32Array) -> void:
	if not multiplayer.is_server():
		return
	# Keyed on the sender, so a client can only ever drive its own seat.
	var slot := _slot_for_peer(multiplayer.get_remote_sender_id())
	if slot != null and slot.device is NetworkInputDevice:
		(slot.device as NetworkInputDevice).push_frame(tick, frame)


func _on_damage_taken(_amount: float, impact: ImpactEvent, combat: VehicleCombat) -> void:
	if impact == null:
		return
	var target_index := _slot_index_of(combat.vehicle)
	if target_index < 0:
		return
	_rpc_impact.rpc(
		target_index,
		_slot_index_of(impact.attacker),
		impact.tier,
		impact.normal,
		impact.position,
		impact.apply_knockback and combat.is_alive(),
		impact.apply_stagger and combat.is_alive()
	)


func _on_contest_resolved(
	first: ArcadeVehicle,
	second: ArcadeVehicle,
	winner: ArcadeVehicle,
	outcome: ClashArbiter.Outcome,
	closing_speed: float,
	position: Vector3
) -> void:
	_rpc_contest.rpc(
		_slot_index_of(first),
		_slot_index_of(second),
		_slot_index_of(winner) if winner != null else -1,
		outcome,
		closing_speed,
		position
	)


func _on_player_eliminated(slot: PlayerSlot) -> void:
	if multiplayer.is_server():
		_rpc_eliminated.rpc(slot.index)


## A client quit or lost connection mid-match: park their car as a wreck.
func _on_peer_left(peer_id: int) -> void:
	_ready_peers.erase(peer_id)
	var slot := _slot_for_peer(peer_id)
	if slot == null:
		return
	if slot.device is NetworkInputDevice:
		(slot.device as NetworkInputDevice).clear()
	if multiplayer.is_server():
		match_manager.eliminate(slot.index)
		_try_start()


@rpc("any_peer", "call_remote", "unreliable")
func _rpc_ping(sent_msec: int) -> void:
	if multiplayer.is_server():
		_rpc_pong.rpc_id(multiplayer.get_remote_sender_id(), sent_msec)


# ---------------------------------------------------------------------------
# Client
# ---------------------------------------------------------------------------

func _client_tick() -> void:
	var tick := Engine.get_physics_frames()
	var own: ArcadeVehicle = match_manager.vehicles.get(local_slot_index)

	if own != null and match_manager.is_alive(local_slot_index):
		# Nothing has moved yet this tick, so this is the state after last tick.
		_history[tick - 1] = PackedFloat32Array([
			own.global_position.x,
			own.global_position.z,
			own.rotation.y,
			own.velocity.x,
			own.velocity.z,
		])
		_history.erase(tick - 1 - _HISTORY_TICKS)

		var slot := _slot_for_index(local_slot_index)
		_rpc_input.rpc_id(1, tick, NetVehicleState.encode_input(slot.device))

	_render_puppets(tick)


@rpc("authority", "call_remote", "unreliable")
func _rpc_snapshot(host_tick: int, acks: PackedInt32Array, data: PackedFloat32Array) -> void:
	if host_tick <= _newest_snapshot_tick:
		return
	_newest_snapshot_tick = host_tick
	_update_tick_offset(host_tick)

	var cars := {}
	var count := mini(data.size() / NetVehicleState.STRIDE, acks.size())
	for i in count:
		var entry := data.slice(i * NetVehicleState.STRIDE, (i + 1) * NetVehicleState.STRIDE)
		var slot_index := int(entry[NetVehicleState.Field.SLOT])
		cars[slot_index] = entry

		var combat: VehicleCombat = match_manager.combats.get(slot_index)
		if combat != null:
			combat.set_network_health(entry[NetVehicleState.Field.HEALTH])

		if slot_index == local_slot_index:
			_reconcile(acks[i], entry)
		else:
			_apply_puppet_state(slot_index, entry)

	_snapshots.append({"tick": host_tick, "cars": cars})
	while _snapshots.size() > _SNAPSHOT_BUFFER:
		_snapshots.pop_front()


## Smoothed, because single samples carry the jitter. A big jump (a hit stop on
## one side only, a stall) is adopted outright rather than eased through.
func _update_tick_offset(host_tick: int) -> void:
	var sample := float(host_tick - Engine.get_physics_frames())
	if not _has_tick_offset or absf(sample - _tick_offset) > 30.0:
		_tick_offset = sample
		_has_tick_offset = true
	else:
		_tick_offset = lerpf(_tick_offset, sample, 0.05)


## The host's state for our car is the result of input tick `ack_tick`. Compare it
## with what we predicted after that same tick; the gap is our prediction error.
##
## The correction is applied to the live car and to every newer history entry,
## since those were all built on the same wrong starting point. Without shifting
## history the next snapshot would measure the same error again and correct it
## twice.
func _reconcile(ack_tick: int, entry: PackedFloat32Array) -> void:
	if ack_tick < 0 or not _history.has(ack_tick):
		return
	var own: ArcadeVehicle = match_manager.vehicles.get(local_slot_index)
	if own == null or not match_manager.is_alive(local_slot_index):
		return

	var predicted: PackedFloat32Array = _history[ack_tick]
	var pos_error := Vector2(
		entry[NetVehicleState.Field.POS_X] - predicted[0],
		entry[NetVehicleState.Field.POS_Z] - predicted[1]
	)
	var yaw_error := angle_difference(predicted[2], entry[NetVehicleState.Field.YAW])
	var vel_error := Vector2(
		entry[NetVehicleState.Field.VEL_X] - predicted[3],
		entry[NetVehicleState.Field.VEL_Z] - predicted[4]
	)

	var distance := pos_error.length()
	if distance < correction_deadband and absf(yaw_error) < 0.02 and vel_error.length() < 0.25:
		return

	var rate := 1.0 if distance >= snap_distance else correction_rate
	var pos_shift := pos_error * rate
	var yaw_shift := yaw_error * rate
	var vel_shift := vel_error * rate

	own.global_position += Vector3(pos_shift.x, 0.0, pos_shift.y)
	own.rotation.y = wrapf(own.rotation.y + yaw_shift, -PI, PI)
	own.velocity += Vector3(vel_shift.x, 0.0, vel_shift.y)

	for tick in _history:
		if tick < ack_tick:
			continue
		var state: PackedFloat32Array = _history[tick]
		state[0] += pos_shift.x
		state[1] += pos_shift.y
		state[2] = wrapf(state[2] + yaw_shift, -PI, PI)
		state[3] += vel_shift.x
		state[4] += vel_shift.y
		_history[tick] = state


## Everything about a puppet except where it is, which _render_puppets owns.
func _apply_puppet_state(slot_index: int, entry: PackedFloat32Array) -> void:
	var vehicle: ArcadeVehicle = match_manager.vehicles.get(slot_index)
	if vehicle == null:
		return

	vehicle.external_velocity_control = NetVehicleState.has_flag(
		entry, NetVehicleState.FLAG_EXTERNAL_VELOCITY
	)
	vehicle.control_locked = NetVehicleState.has_flag(entry, NetVehicleState.FLAG_CONTROL_LOCKED)
	vehicle.skill_dashing = NetVehicleState.has_flag(entry, NetVehicleState.FLAG_SKILL_DASHING)

	var skill: BrakeDashSkill = match_manager.skills.get(slot_index)
	if skill != null:
		skill.apply_network_state(
			int(entry[NetVehicleState.Field.SKILL_STATE]) as BrakeDashSkill.State,
			entry[NetVehicleState.Field.SKILL_CHARGE],
			entry[NetVehicleState.Field.SKILL_COOLDOWN]
		)

	var momentum := ClashArbiter.momentum_for(vehicle)
	var tier := int(entry[NetVehicleState.Field.TIER]) as MomentumTier.Value
	if momentum != null and momentum.tier != tier:
		var previous := momentum.tier
		momentum.tier = tier
		momentum.tier_changed.emit(tier, previous)


## Draws puppets at a point slightly in the host's past, between the two
## snapshots that bracket it. Past the newest snapshot they coast briefly on its
## velocity instead of stopping dead.
func _render_puppets(tick: int) -> void:
	if _snapshots.is_empty():
		return

	var render_tick := float(tick) + _tick_offset - float(interpolation_delay_ticks)
	var older: Dictionary = _snapshots[0]
	var newer: Dictionary = {}
	for snapshot in _snapshots:
		if float(snapshot["tick"]) <= render_tick:
			older = snapshot
		else:
			newer = snapshot
			break

	var span := float(newer["tick"] - older["tick"]) if not newer.is_empty() else 0.0
	var t := clampf((render_tick - float(older["tick"])) / span, 0.0, 1.0) if span > 0.0 else 0.0
	var overshoot := (
		clampf(render_tick - float(older["tick"]), 0.0, float(extrapolation_limit_ticks))
		/ float(Engine.physics_ticks_per_second)
	)

	for slot_index in older["cars"]:
		if slot_index == local_slot_index:
			continue
		var vehicle: ArcadeVehicle = match_manager.vehicles.get(slot_index)
		if vehicle == null:
			continue

		var a: PackedFloat32Array = older["cars"][slot_index]
		var position := Vector2(a[NetVehicleState.Field.POS_X], a[NetVehicleState.Field.POS_Z])
		var velocity := Vector2(a[NetVehicleState.Field.VEL_X], a[NetVehicleState.Field.VEL_Z])
		var yaw: float = a[NetVehicleState.Field.YAW]

		if not newer.is_empty() and newer["cars"].has(slot_index):
			var b: PackedFloat32Array = newer["cars"][slot_index]
			position = position.lerp(
				Vector2(b[NetVehicleState.Field.POS_X], b[NetVehicleState.Field.POS_Z]), t
			)
			velocity = velocity.lerp(
				Vector2(b[NetVehicleState.Field.VEL_X], b[NetVehicleState.Field.VEL_Z]), t
			)
			yaw = lerp_angle(yaw, b[NetVehicleState.Field.YAW], t)
		else:
			position += velocity * overshoot

		vehicle.global_position = Vector3(position.x, vehicle.global_position.y, position.y)
		vehicle.rotation.y = yaw
		# Written so the feel layer's lean and trails, and our own car's collision
		# events against this one, all see real motion.
		vehicle.velocity = Vector3(velocity.x, 0.0, velocity.y)

	# Drop what can no longer be bracketed, keeping one at or before render time.
	while _snapshots.size() > 2 and float(_snapshots[1]["tick"]) <= render_tick:
		_snapshots.pop_front()


@rpc("authority", "call_remote", "reliable")
func _rpc_impact(
	target_index: int,
	attacker_index: int,
	tier: int,
	normal: Vector3,
	position: Vector3,
	knockback: bool,
	stagger: bool
) -> void:
	# Only our own car simulates here; puppets get the result via snapshots.
	if target_index != local_slot_index or not (knockback or stagger):
		return
	var combat: VehicleCombat = match_manager.combats.get(target_index)
	if combat == null:
		return

	var impact := ImpactEvent.new()
	impact.attacker = match_manager.vehicles.get(attacker_index)
	impact.target = combat.vehicle
	impact.tier = tier as ImpactTier.Value
	impact.normal = normal
	impact.position = position
	impact.apply_knockback = knockback
	impact.apply_stagger = stagger
	combat.apply_reactions(impact)


## Replays the host's contest locally so hit stop, shake, deformation and the
## shockwave all fire here too, through the same ImpactFx path as offline.
@rpc("authority", "call_remote", "reliable")
func _rpc_contest(
	first_index: int,
	second_index: int,
	winner_index: int,
	outcome: int,
	closing_speed: float,
	position: Vector3
) -> void:
	var first: ArcadeVehicle = match_manager.vehicles.get(first_index)
	var second: ArcadeVehicle = match_manager.vehicles.get(second_index)
	if first == null or second == null:
		return
	ClashArbiter.contest_resolved.emit(
		first,
		second,
		match_manager.vehicles.get(winner_index) if winner_index >= 0 else null,
		outcome as ClashArbiter.Outcome,
		closing_speed,
		position
	)


@rpc("authority", "call_remote", "reliable")
func _rpc_eliminated(slot_index: int) -> void:
	match_manager.eliminate(slot_index)


@rpc("authority", "call_remote", "unreliable")
func _rpc_pong(sent_msec: int) -> void:
	_ping_ms = Time.get_ticks_msec() - sent_msec
	_refresh_overlay()


# ---------------------------------------------------------------------------
# Overlay
# ---------------------------------------------------------------------------

func _build_overlay() -> void:
	var layer := CanvasLayer.new()
	layer.layer = 5
	add_child(layer)

	_overlay = Label.new()
	_overlay.anchor_left = 1.0
	_overlay.anchor_right = 1.0
	_overlay.offset_left = -360.0
	_overlay.offset_right = -16.0
	_overlay.offset_top = 16.0
	_overlay.horizontal_alignment = HORIZONTAL_ALIGNMENT_RIGHT
	_overlay.add_theme_font_size_override("font_size", 14)
	_overlay.add_theme_color_override("font_color", Color(0.75, 0.8, 0.9))
	layer.add_child(_overlay)


func _refresh_overlay() -> void:
	if _overlay == null:
		return
	var lines: Array[String] = []
	if multiplayer.is_server():
		lines.append("ONLINE  host  %d players" % match_manager.slots.size())
	else:
		lines.append("ONLINE  ping %s" % ("%d ms" % _ping_ms if _ping_ms >= 0 else "..."))
	if not started:
		lines.append("Waiting for %d player(s) to load..." % _players_not_ready())
	if multiplayer.is_server():
		lines.append("Backspace: back to lobby")
	_overlay.text = "\n".join(lines)


func _players_not_ready() -> int:
	if not multiplayer.is_server():
		return 0
	var waiting := 0
	for slot in match_manager.slots:
		if not _ready_peers.has(slot.peer_id):
			waiting += 1
	return waiting


func _on_match_finished(_winner: PlayerSlot) -> void:
	_refresh_overlay()


# ---------------------------------------------------------------------------
# Lookups
# ---------------------------------------------------------------------------

func _slot_for_peer(peer_id: int) -> PlayerSlot:
	for slot in match_manager.slots:
		if slot.peer_id == peer_id:
			return slot
	return null


func _slot_for_index(slot_index: int) -> PlayerSlot:
	for slot in match_manager.slots:
		if slot.index == slot_index:
			return slot
	return null


func _slot_index_of(vehicle: ArcadeVehicle) -> int:
	if vehicle == null:
		return -1
	for slot_index in match_manager.vehicles:
		if match_manager.vehicles[slot_index] == vehicle:
			return slot_index
	return -1


func _driver_for(vehicle: ArcadeVehicle) -> PlayerVehicleDriver:
	for child in vehicle.get_children():
		if child is PlayerVehicleDriver:
			return child
	return null
