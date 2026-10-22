extends Node3D
## Diagnostic: where does the leftover velocity actually point after you stop
## accelerating?
##
##   godot --headless --path caddy-godot res://tests/coast_probe.tscn
##
## Tracks the angle between the car's velocity and its nose while coasting. If
## that angle grows, the car is sliding somewhere other than where it points.

const TICK := 1.0 / 60.0
const LANE_X := 9000.0

var _log: PackedStringArray = []
var _vehicle: ArcadeVehicle


func _ready() -> void:
	Engine.physics_ticks_per_second = 60
	_vehicle = ArcadeVehicle.new()
	_vehicle.tuning = load("res://resources/tuning/tuning_default.tres")
	var shape := CollisionShape3D.new()
	var box := BoxShape3D.new()
	box.size = Vector3(1.4, 0.875, 2.3)
	shape.shape = box
	_vehicle.add_child(shape)
	add_child(_vehicle)
	await get_tree().physics_frame
	await get_tree().process_frame

	var t: VehicleTuning = _vehicle.tuning
	_log.append(
		"coast %.0f  drift_friction %.1f  grip_friction %.1f  stop_threshold %.2f"
		% [t.coast_deceleration, t.drift_lateral_friction, t.grip_lateral_friction,
		   t.stop_speed_threshold]
	)

	_case("A. straight, release throttle, keep holding forward", Vector3.FORWARD, Vector3.FORWARD, 0.0)
	_case("B. straight, release throttle AND stick", Vector3.FORWARD, Vector3.ZERO, 0.0)
	_case("C. straight, release throttle, then steer right", Vector3.FORWARD, Vector3.RIGHT, 0.0)
	_case("D. straight, then brake while holding forward", Vector3.FORWARD, Vector3.FORWARD, 1.0)
	_sideways_brake()

	for line in _log:
		print(line)
	get_tree().quit()


## The decisive test: get the car sliding sideways, then stamp on the brake.
func _sideways_brake() -> void:
	_reset()
	for i in 150:
		_drive(1.0, 0.0, Vector3.FORWARD)
	# Snap the nose 90 degrees off the velocity without touching the velocity.
	_vehicle.rotation.y = PI * 0.5
	_log.append("")
	_log.append("--- E. sliding sideways, then FULL BRAKE (and stick held) ---")
	_log.append("  %6s %8s %9s %9s %12s %14s" % ["t","speed","forward","lateral","vel vs nose","moving"])
	_sample(0.0)
	var elapsed := 0.0
	for step in 10:
		for i in 12:
			_drive(0.0, 1.0, Vector3.FORWARD)
			elapsed += TICK
		_sample(elapsed)


func _case(label: String, accel_intent: Vector3, coast_intent: Vector3, brake: float) -> void:
	_reset()
	# Accelerate holding exactly the stated intent, so each case is what it says.
	for i in 150:
		_drive(1.0, 0.0, accel_intent)

	_log.append("")
	_log.append("--- %s ---" % label)
	_log.append(
		"  %6s %8s %9s %9s %12s %14s"
		% ["t", "speed", "forward", "lateral", "vel vs nose", "moving"]
	)
	_sample(0.0)

	var elapsed := 0.0
	for step in 10:
		for i in 12:
			_drive(0.0, brake, coast_intent)
			elapsed += TICK
		_sample(elapsed)
		if _vehicle.get_planar_speed() <= 0.01:
			break


func _sample(t: float) -> void:
	var speed := _vehicle.get_planar_speed()
	var fwd := _vehicle.get_forward_speed()
	var lat := _vehicle.get_lateral_speed()
	var angle := 0.0
	var moving := "stopped"
	if speed > 0.01:
		var dir := Vector3(_vehicle.velocity.x, 0.0, _vehicle.velocity.z).normalized()
		angle = rad_to_deg(acos(clampf(dir.dot(_vehicle.planar_forward()), -1.0, 1.0)))
		if angle < 30.0:
			moving = "forward"
		elif angle < 60.0:
			moving = "diagonal"
		elif angle < 120.0:
			moving = "SIDEWAYS"
		else:
			moving = "BACKWARD"
	_log.append(
		"  %5.2fs %7.2f %8.2f %8.2f %10.0f deg %14s" % [t, speed, fwd, lat, angle, moving]
	)


func _drive(throttle: float, brake: float, intent: Vector3) -> void:
	_vehicle.set_move_intent(intent)
	_vehicle.set_throttle_input(throttle)
	_vehicle.set_brake_reverse_input(brake)
	_vehicle.set_grip_input(0.0)
	_vehicle._physics_process(TICK)


func _reset() -> void:
	_vehicle.velocity = Vector3.ZERO
	_vehicle.rotation = Vector3.ZERO
	_vehicle.global_position = Vector3(LANE_X, 0.44, 0.0)
	_vehicle.reverse_steering_active = false
	_vehicle.set_control_lock_enabled(false)
	_vehicle.set_external_velocity_control_enabled(false)
	_vehicle.set_throttle_input(0.0)
	_vehicle.set_brake_reverse_input(0.0)
