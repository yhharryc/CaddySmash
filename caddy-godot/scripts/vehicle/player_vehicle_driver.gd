class_name PlayerVehicleDriver
extends Node
## Reads one input device and pushes it into an ArcadeVehicle.
##
## Split out from the vehicle the same way ACaddyVehiclePawn was split from
## UArcadeVehicleMovementComponent, so AI or replayed input can drive the same
## car by calling the same setters.
##
## Input comes from an InputDevice rather than the InputMap: InputMap actions
## aggregate every connected pad, so they cannot tell one local player from
## another. See InputDevice for the full reasoning.

## Runs ahead of the vehicle's own _physics_process so input lands the same frame.
const _INPUT_PRIORITY := -10

@export var vehicle: ArcadeVehicle
@export var skill: BrakeDashSkill
## Off for AI or dummy cars that share the vehicle scene.
@export var enabled: bool = true
## Cleared by MatchManager, which resets the whole field instead. A per-car
## respawn there would only revive whoever was still alive to press the key.
@export var handles_reset: bool = true

## The grip input is a tuning aid: the car's shipping feel is the drifty resting
## state, and this binding exists to A/B the two friction values. The button is
## earmarked for another mechanic later.
@export var enable_grip_input: bool = true

## Assigned by the match. Defaults to the keyboard so single-car scenes just run.
## Left null for a car driven from the network instead of a local pad.
var device: InputDevice = null
## Last input applied, whatever its source. The record prediction will replay.
var last_input: VehicleInput = null

var _spawn_transform := Transform3D.IDENTITY


func _ready() -> void:
	process_physics_priority = _INPUT_PRIORITY
	if vehicle == null:
		vehicle = get_parent() as ArcadeVehicle
	if device == null:
		device = InputDevice.keyboard()
	if vehicle != null:
		_spawn_transform = vehicle.global_transform


func set_device(new_device: InputDevice) -> void:
	device = new_device


## Called on respawn or when the match resets the field.
func set_spawn_transform(transform: Transform3D) -> void:
	_spawn_transform = transform


func respawn() -> void:
	if vehicle == null:
		return
	if skill != null:
		skill.abort_to_ready()
		skill.cooldown_remaining = 0.0
	vehicle.velocity = Vector3.ZERO
	vehicle.reverse_steering_active = false
	vehicle.set_external_velocity_control_enabled(false)
	vehicle.set_control_lock_enabled(false)
	vehicle.global_transform = _spawn_transform


func _physics_process(_delta: float) -> void:
	if vehicle == null or not enabled:
		return
	var input := sample_input()
	if input != null:
		apply_input(input)


## Reads the assigned device into a value. Returns null when there is nothing to
## read, e.g. a car driven from the network rather than from a local pad.
func sample_input() -> VehicleInput:
	if device == null:
		return null
	return VehicleInput.make(
		Engine.get_physics_frames(),
		device.get_move_vector(),
		device.get_throttle(),
		device.get_brake(),
		device.get_grip() if enable_grip_input else 0.0,
		device.is_skill_pressed()
	)


## The single point where input reaches the car, whether it came from a local
## pad, over the wire, or out of a replay buffer during prediction. Keeping this
## separate from sample_input is what makes those three cases the same code path.
func apply_input(input: VehicleInput) -> void:
	if vehicle == null or input == null:
		return
	last_input = input
	vehicle.set_move_intent_from_stick(input.move_stick)
	vehicle.set_throttle_input(input.throttle)
	vehicle.set_brake_reverse_input(input.brake)
	vehicle.set_grip_input(input.grip)
	if skill != null:
		skill.set_skill_input_pressed(input.skill_pressed)


func _unhandled_input(event: InputEvent) -> void:
	# Not marked handled: with several drivers in the scene, consuming the event
	# here would reset only the first one.
	if vehicle != null and handles_reset and event.is_action_pressed("caddy_reset"):
		respawn()
