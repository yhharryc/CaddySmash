class_name VehicleCameraRig
extends Node3D
## Port of UCaddyVehicleCameraComponent + its SpringArm rig.
##
## In Unreal the boom used SetUsingAbsoluteRotation(true), so the camera yaw is
## world-fixed and never follows the car. That matters beyond the visuals: move
## intent is camera-relative, so this node's Y rotation defines which way "up on
## the stick" points. Keep it at 0 to match the Unreal build.
##
## Two modes. Chase (center_bias 0, fit_ground_radius 0) is the original
## single-player camera: speed-driven arm/pitch/FOV, look-ahead, lateral roll.
## Anchored (center_bias 1, fit_ground_radius > 0) holds the arena and solves the
## arm length to fit it, suppressing everything that would make the shot breathe.

## Any rig in this group can be shaken by an impact anywhere in the match.
const CAMERA_RIG_GROUP := &"camera_rig"

## Single-target convenience. Ignored once set_targets has been given a list.
@export var vehicle: ArcadeVehicle
@export var tuning: CameraTuning
## Point the shot holds on, normally the arena. Blended in by tuning.center_bias.
@export var center_anchor: Node3D

## Every car the shot has to contain. With one entry look-ahead and lateral roll
## stay on; with more they switch off, since both describe one car's motion and
## read as noise when the focus is a group centroid.
var targets: Array[ArcadeVehicle] = []

var speed_alpha := 0.0
var current_arm_length := 0.0
var current_pitch_deg := 0.0
var current_roll_deg := 0.0
var current_fov := 0.0
var current_lag_speed := 0.0
var current_look_ahead := Vector3.ZERO
## 0..1. Squared before use so small knocks stay subtle and big ones spike.
var trauma := 0.0

var _lagged_focus := Vector3.ZERO
var _camera: Camera3D
var _noise := FastNoiseLite.new()
var _shake_time := 0.0


func _ready() -> void:
	add_to_group(CAMERA_RIG_GROUP)
	_camera = $Camera3D
	if tuning == null:
		tuning = CameraTuning.new()
	_noise.noise_type = FastNoiseLite.TYPE_SIMPLEX
	_noise.frequency = 1.0

	current_arm_length = tuning.base_arm_length
	current_pitch_deg = tuning.base_pitch_deg
	current_fov = tuning.base_fov
	_lagged_focus = _focus_point()
	_apply_transform()


## Adds camera shake. Callers pass 0..1; it accumulates and decays on its own.
func add_trauma(amount: float) -> void:
	if not tuning.enable_shake:
		return
	trauma = clampf(trauma + amount, 0.0, 1.0)


## Replaces the framed group. Pass the cars still in play.
func set_targets(new_targets: Array[ArcadeVehicle]) -> void:
	targets = new_targets.duplicate()
	if not targets.is_empty():
		vehicle = targets[0]


func active_targets() -> Array[ArcadeVehicle]:
	var active: Array[ArcadeVehicle] = []
	for target in targets:
		if is_instance_valid(target):
			active.append(target)
	if active.is_empty() and is_instance_valid(vehicle):
		active.append(vehicle)
	return active


func _focus_point() -> Vector3:
	var active := active_targets()
	var centroid := _lagged_focus
	if not active.is_empty():
		var sum := Vector3.ZERO
		for target in active:
			sum += target.global_position
		centroid = sum / float(active.size())

	if center_anchor != null and tuning.center_bias > 0.0:
		return centroid.lerp(center_anchor.global_position, tuning.center_bias)
	return centroid


## Widest gap between any two framed cars, which is what the pull-back tracks.
func _target_spread() -> float:
	var active := active_targets()
	if active.size() < 2:
		return 0.0
	var widest := 0.0
	for i in active.size():
		for j in range(i + 1, active.size()):
			widest = maxf(widest, active[i].global_position.distance_to(active[j].global_position))
	return widest


## Arm length that puts `fit_ground_radius` of ground inside the vertical FOV.
## Camera height is arm * sin(pitch); half the visible ground height at that
## height is height * tan(fov / 2). Solved from the base values rather than the
## interpolated ones so the result cannot drift or feed back on itself.
func _fitted_arm_length() -> float:
	var pitch := deg_to_rad(absf(tuning.base_pitch_deg))
	var half_fov := deg_to_rad(clampf(tuning.base_fov, 1.0, 179.0) * 0.5)
	var coverage := maxf(0.05, sin(pitch) * tan(half_fov))
	return tuning.fit_ground_radius / coverage


func _process(delta: float) -> void:
	var active := active_targets()
	if active.is_empty() or _camera == null:
		return

	# Fastest car drives the speed effects; for one target this is just its speed.
	var fastest := 0.0
	for target in active:
		fastest = maxf(fastest, target.get_planar_speed())
	speed_alpha = clampf(fastest / maxf(0.01, tuning.max_speed_for_effects), 0.0, 1.0)

	_update_look_ahead(delta, active)
	_update_focus(delta)

	var target_arm := 0.0
	if tuning.fit_ground_radius > 0.0:
		# Fixed framing: speed and spread offsets are deliberately ignored, since
		# both make the shot breathe and the point here is that it does not.
		target_arm = _fitted_arm_length()
	else:
		var spread_arm := minf(_target_spread() * tuning.spread_zoom_scale, tuning.max_spread_arm_length)
		target_arm = (
			tuning.base_arm_length + tuning.max_speed_arm_length_offset * speed_alpha + spread_arm
		)
	current_arm_length = UeMath.finterp_to(
		current_arm_length, target_arm, delta, tuning.transform_interp_speed
	)

	var target_pitch := tuning.base_pitch_deg
	var target_fov := tuning.base_fov
	if tuning.fit_ground_radius <= 0.0:
		target_pitch += tuning.max_speed_pitch_offset_deg * speed_alpha
		target_fov += tuning.max_speed_fov_offset * speed_alpha
	current_pitch_deg = UeMath.finterp_to(
		current_pitch_deg, target_pitch, delta, tuning.transform_interp_speed
	)
	current_fov = UeMath.finterp_to(
		current_fov, target_fov, delta, tuning.transform_interp_speed
	)

	var target_roll := 0.0
	if active.size() == 1 and tuning.center_bias < 1.0:
		var lateral_alpha := clampf(
			active[0].get_lateral_speed() / maxf(0.01, tuning.lateral_speed_for_max_roll), -1.0, 1.0
		)
		target_roll = lateral_alpha * tuning.max_lateral_roll_deg
	current_roll_deg = UeMath.finterp_to(
		current_roll_deg, target_roll, delta, tuning.roll_interp_speed
	)

	_update_shake(delta)
	_apply_transform()


func _update_look_ahead(delta: float, active: Array[ArcadeVehicle]) -> void:
	var target_offset := Vector3.ZERO
	if active.size() == 1:
		var direction := active[0].velocity
		direction.y = 0.0
		if direction.length_squared() < 0.0001:
			direction = active[0].planar_forward()
		else:
			direction = direction.normalized()
		# Fades out as the shot anchors: leading the car is a chase behaviour.
		target_offset = (
			direction
			* tuning.look_ahead_distance
			* speed_alpha
			* (1.0 - tuning.center_bias)
		)

	current_look_ahead = UeMath.vinterp_to(
		current_look_ahead, target_offset, delta, tuning.look_ahead_interp_speed
	)


## Spring-arm position lag: ease the focus point toward the cars, then clamp how
## far behind it is allowed to fall.
func _update_focus(delta: float) -> void:
	var desired := _focus_point() + current_look_ahead
	if not tuning.enable_camera_lag:
		_lagged_focus = desired
		current_lag_speed = 0.0
		return

	current_lag_speed = lerpf(
		maxf(0.0, tuning.camera_lag_speed_at_low_speed),
		maxf(0.0, tuning.camera_lag_speed_at_high_speed),
		speed_alpha
	)
	_lagged_focus = UeMath.vinterp_to(_lagged_focus, desired, delta, current_lag_speed)

	var offset := _lagged_focus - desired
	if offset.length() > tuning.camera_lag_max_distance:
		_lagged_focus = desired + offset.normalized() * tuning.camera_lag_max_distance


func _update_shake(delta: float) -> void:
	if trauma <= 0.0:
		return
	trauma = maxf(0.0, trauma - tuning.trauma_decay * delta)
	_shake_time += delta * tuning.shake_frequency


## Squared trauma: small knocks stay subtle, big ones spike hard.
func _shake_offset() -> Vector3:
	if trauma <= 0.0 or not tuning.enable_shake:
		return Vector3.ZERO
	var magnitude := trauma * trauma * tuning.max_shake_offset
	# Three noise channels rather than random per frame, so it sways instead of
	# strobing - random jitter reads as a broken frame, not an impact.
	return Vector3(
		_noise.get_noise_2d(_shake_time, 0.0),
		_noise.get_noise_2d(_shake_time, 137.0),
		_noise.get_noise_2d(_shake_time, 311.0)
	) * magnitude


func _shake_roll() -> float:
	if trauma <= 0.0 or not tuning.enable_shake:
		return 0.0
	return (
		_noise.get_noise_2d(_shake_time, 613.0)
		* trauma
		* trauma
		* deg_to_rad(tuning.max_shake_roll_deg)
	)


func _apply_transform() -> void:
	global_position = _lagged_focus
	if _camera == null:
		return
	# Pitch and pull-back live on the camera; the rig keeps its world-fixed yaw.
	var pitch := deg_to_rad(current_pitch_deg)
	_camera.rotation = Vector3(pitch, 0.0, deg_to_rad(current_roll_deg) + _shake_roll())
	_camera.position = (
		Vector3(0.0, 0.0, current_arm_length).rotated(Vector3.RIGHT, pitch) + _shake_offset()
	)
	_camera.fov = current_fov
