class_name MatchManager
extends Node
## Spawns the roster into the arena and owns the match lifecycle.

signal player_spawned(slot: PlayerSlot, vehicle: ArcadeVehicle)
signal player_eliminated(slot: PlayerSlot)
signal match_finished(winner: PlayerSlot)
## Everyone revived and back on their spawn.
signal match_reset

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
			# The match resets the whole field; a per-car respawn would only bring
			# back whoever was still alive to press the key.
			driver.handles_reset = false

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


func _unhandled_input(event: InputEvent) -> void:
	if event.is_action_pressed("caddy_reset"):
		reset_match()
		get_viewport().set_input_as_handled()


## Revives everyone, alive or not, and puts the field back on its spawns. The
## old behaviour reset only cars whose driver was still enabled, which excluded
## exactly the players most likely to want a reset.
func reset_match() -> void:
	eliminated.clear()
	finished = false

	for i in slots.size():
		var slot := slots[i]
		var vehicle: ArcadeVehicle = vehicles.get(slot.index)
		if vehicle == null:
			continue

		var combat: VehicleCombat = combats.get(slot.index)
		if combat != null:
			combat.revive()

		var driver := _find_driver(vehicle)
		if driver != null:
			driver.enabled = true
			# Spawns are recomputed rather than reused: the arena may have been
			# resized in the debug menu since the match began.
			driver.set_spawn_transform(arena.get_spawn_transform(i, slots.size()))
			driver.respawn()

		_tint(vehicle, slot.color())

	_refresh_camera_targets()
	match_reset.emit()


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


func is_alive(slot_index: int) -> bool:
	return not eliminated.has(slot_index)


func _find_driver(vehicle: ArcadeVehicle) -> PlayerVehicleDriver:
	for child in vehicle.get_children():
		if child is PlayerVehicleDriver:
			return child
	return null
