class_name MatchManager
extends Node
## Spawns the roster into the arena and owns the match lifecycle.

signal player_spawned(slot: PlayerSlot, vehicle: ArcadeVehicle)
signal player_eliminated(slot: PlayerSlot)
signal match_finished(winner: PlayerSlot)

## Loaded by path rather than named as a class: NetMatchSync holds a typed
## reference back to MatchManager, and a class_name cycle between the two is
## exactly what makes the GDScript resolver spin (see PORTING.md).
const _NET_SYNC_SCRIPT := "res://scripts/networking/net_match_sync.gd"

@export var vehicle_scene: PackedScene
@export var arena: CircularArena
@export var camera_rig: VehicleCameraRig
@export var vehicle_parent: Node3D

## Slot index -> spawned vehicle.
var vehicles: Dictionary = {}
## Slot index -> VehicleCombat.
var combats: Dictionary = {}
## Slot index -> BrakeDashSkill.
var skills: Dictionary = {}
var slots: Array[PlayerSlot] = []
var eliminated: Array[int] = []
var finished := false


func _ready() -> void:
	# Running the arena scene directly (no join screen) still gives one player.
	PlayerRoster.ensure_at_least_one()
	slots = PlayerRoster.players.duplicate()
	# Deferred: while _ready runs the rest of the scene is still being built, so
	# add_child on a sibling fails and exported node paths have not resolved yet.
	# It also lets the HUD connect to player_spawned before the first car exists.
	_spawn_all.call_deferred()


func _spawn_all() -> void:
	var targets: Array[ArcadeVehicle] = []
	# Only needs to be somewhere in the tree; MatchManager itself is a plain Node.
	var parent: Node = vehicle_parent if vehicle_parent != null else get_parent()

	for i in slots.size():
		var slot := slots[i]
		var vehicle := vehicle_scene.instantiate() as ArcadeVehicle
		parent.add_child(vehicle)
		vehicle.name = "Vehicle_%s" % slot.label()
		vehicle.global_transform = arena.get_spawn_transform(i, slots.size())
		vehicle.intent_yaw_source = camera_rig

		_tint(vehicle, slot.color())

		var driver := _find_driver(vehicle)
		if driver != null:
			driver.set_device(slot.device)
			driver.set_spawn_transform(vehicle.global_transform)

		for child in vehicle.get_children():
			if child is BrakeDashSkill:
				skills[slot.index] = child
				break

		var combat := VehicleCombat.find_for(vehicle)
		if combat != null:
			combats[slot.index] = combat
			combat.destroyed.connect(_on_player_destroyed.bind(slot))

		vehicles[slot.index] = vehicle
		targets.append(vehicle)
		player_spawned.emit(slot, vehicle)

	camera_rig.set_targets(targets)

	# Online: one node keeps this match in step with the other machines. Added
	# after the cars exist and at the same path everywhere, so its RPCs resolve.
	if NetworkManager.is_online():
		var sync: Node = load(_NET_SYNC_SCRIPT).new()
		sync.name = "NetMatchSync"
		sync.set("match_manager", self)
		add_child(sync)


## Gives each car its player colour. The scene ships a shared material, so this
## has to be a per-instance override or every car would change together.
func _tint(vehicle: ArcadeVehicle, color: Color) -> void:
	var body := vehicle.get_node_or_null("Visual/Body") as MeshInstance3D
	if body != null:
		var material := StandardMaterial3D.new()
		material.albedo_color = color
		body.set_surface_override_material(0, material)

	# Skid ribbons and won-contest shockwaves take the player colour too, so both
	# identify their owner at a glance.
	for child in vehicle.get_children():
		if child is DriftTrail:
			(child as DriftTrail).color = color
		elif child is ImpactFx:
			(child as ImpactFx).color = color


func _on_player_destroyed(slot: PlayerSlot) -> void:
	if finished or eliminated.has(slot.index):
		return

	eliminated.append(slot.index)

	var vehicle: ArcadeVehicle = vehicles.get(slot.index)
	if vehicle != null:
		# Park the wreck: input off, and it stops being framed by the camera.
		var driver := _find_driver(vehicle)
		if driver != null:
			driver.enabled = false
		vehicle.set_control_lock_enabled(true)
		vehicle.velocity = Vector3.ZERO
		_tint(vehicle, Color(0.25, 0.25, 0.28))

	player_eliminated.emit(slot)
	_refresh_camera_targets()
	_check_for_winner()


func _refresh_camera_targets() -> void:
	var alive: Array[ArcadeVehicle] = []
	for slot in slots:
		if not eliminated.has(slot.index) and vehicles.has(slot.index):
			alive.append(vehicles[slot.index])
	if not alive.is_empty():
		camera_rig.set_targets(alive)


## Only meaningful with two or more players; a solo test run never ends.
func _check_for_winner() -> void:
	if slots.size() < 2 or eliminated.size() < slots.size() - 1:
		return
	for slot in slots:
		if not eliminated.has(slot.index):
			finished = true
			match_finished.emit(slot)
			return


## Wrecks a seat by index. Online, only the host decides who is destroyed; it
## announces each elimination and clients apply it through here.
func eliminate(slot_index: int) -> void:
	for slot in slots:
		if slot.index == slot_index:
			_on_player_destroyed(slot)
			return


func is_alive(slot_index: int) -> bool:
	return not eliminated.has(slot_index)


func _find_driver(vehicle: ArcadeVehicle) -> PlayerVehicleDriver:
	for child in vehicle.get_children():
		if child is PlayerVehicleDriver:
			return child
	return null
