class_name VehicleCameraRig
extends Node3D
## Port of UCaddyVehicleCameraComponent + its SpringArm rig.
##
## In Unreal the boom used SetUsingAbsoluteRotation(true), so the camera yaw is
## world-fixed and never follows the car. That matters beyond the visuals: move
## intent is camera-relative, so this node's Y rotation defines which way "up on
## the stick" points. Keep it at 0 to match the Unreal build.
##
## Everything else keys off speed_alpha = planar_speed / max_speed_for_effects.

## Single-target convenience. Ignored once set_targets has been given a list.
@export var vehicle: ArcadeVehicle

## Every car the shot has to contain. With one entry the rig behaves exactly as
## the single-player version did: spread is zero, so look-ahead and lateral roll
## stay on. With more than one it frames the group instead, and both of those
## turn off — they are statements about one car's motion and read as noise when
## the focus is a centroid.
var targets: Array[ArcadeVehicle] = []

@export_group("Base")
## UE BaseArmLength 1400 cm.
@export var base_arm_length: float = 14.0
## UE BasePitchDeg -72.
@export var base_pitch_deg: float = -72.0
## UE BaseFOV 90.
@export var base_fov: float = 90.0

@export_group("Speed")
## UE MaxSpeedForEffects 2200 cm/s.
@export var max_speed_for_effects: float = 22.0
## UE MaxSpeedPitchOffsetDeg 6.5 - the view flattens out as you gain speed.
@export var max_speed_pitch_offset_deg: float = 6.5
## UE MaxSpeedArmLengthOffset 120 cm.
@export var max_speed_arm_length_offset: float = 1.2
## UE MaxSpeedFOVOffset 8.
@export var max_speed_fov_offset: float = 8.0

@export_group("Look Ahead")
## UE LookAheadDistance 180 cm. Scaled by speed alpha.
@export var look_ahead_distance: float = 1.8
## UE LookAheadInterpSpeed 4.
@export var look_ahead_interp_speed: float = 4.0

@export_group("Roll")
## UE MaxLateralRollDeg 7.5 - banks the view into a slide.
@export var max_lateral_roll_deg: float = 7.5
## UE LateralSpeedForMaxRoll 900 cm/s.
@export var lateral_speed_for_max_roll: float = 9.0
## UE RollInterpSpeed 6.
@export var roll_interp_speed: float = 6.0

@export_group("Lag")
@export var enable_camera_lag: bool = true
## UE CameraLagSpeedAtLowSpeed 12. Higher tracks tighter.
@export var camera_lag_speed_at_low_speed: float = 12.0
## UE CameraLagSpeedAtHighSpeed 7 - the rig loosens as you go faster.
@export var camera_lag_speed_at_high_speed: float = 7.0
## UE CameraLagMaxDistance 340 cm.
@export var camera_lag_max_distance: float = 3.4

@export_group("Anchor")
## Point the shot holds on, normally the arena. Blended in by center_bias.
@export var center_anchor: Node3D
## 0 chases the cars, 1 locks the shot to center_anchor. Anything above 0 also
## fades out look-ahead, which is a chase behaviour and fights a steady frame.
@export_range(0.0, 1.0) var center_bias: float = 0.0
## When > 0, arm length is solved to fit this ground radius in view instead of
## using base_arm_length plus the speed and spread offsets. Keeps the shot
## perfectly steady, and means changing the arena size reframes it automatically.
@export var fit_ground_radius: float = 0.0

@export_group("Group framing")
## Extra arm length per metre the players are spread apart. Local multiplayer only.
@export var spread_zoom_scale: float = 0.55
## Ceiling on that pull-back, so a corner-to-corner match stays readable.
@export var max_spread_arm_length: float = 22.0

@export_group("Smoothing")
## UE TransformInterpSpeed 4.
@export var transform_interp_speed: float = 4.0

var speed_alpha := 0.0
var current_arm_length := 0.0
var current_pitch_deg := 0.0
var current_roll_deg := 0.0
var current_fov := 0.0
var current_lag_speed := 0.0
var current_look_ahead := Vector3.ZERO

var _lagged_focus := Vector3.ZERO
var _camera: Camera3D


func _ready() -> void:
	_camera = $Camera3D
	current_arm_length = base_arm_length
	current_pitch_deg = base_pitch_deg
	current_fov = base_fov
	_lagged_focus = _focus_point()
	_apply_transform()


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

	if center_anchor != null and center_bias > 0.0:
		return centroid.lerp(center_anchor.global_position, center_bias)
	return centroid


## Arm length that puts `fit_ground_radius` of ground inside the vertical FOV.
## Camera height is arm * sin(pitch); half the visible ground height at that
## height is height * tan(fov / 2). Solved from the base values rather than the
## interpolated ones so the result cannot drift or feed back on itself.
func _fitted_arm_length() -> float:
	var pitch := deg_to_rad(absf(base_pitch_deg))
	var half_fov := deg_to_rad(clampf(base_fov, 1.0, 179.0) * 0.5)
	var coverage := maxf(0.05, sin(pitch) * tan(half_fov))
	return fit_ground_radius / coverage


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


func _process(delta: float) -> void:
	var active := active_targets()
	if active.is_empty() or _camera == null:
		return

	# Fastest car drives the speed effects; for one target this is just its speed.
	var fastest := 0.0
	for target in active:
		fastest = maxf(fastest, target.get_planar_speed())
	speed_alpha = clampf(fastest / maxf(0.01, max_speed_for_effects), 0.0, 1.0)

	_update_look_ahead(delta, active)
	_update_focus(delta)

	var target_arm := 0.0
	if fit_ground_radius > 0.0:
		# Fixed framing: speed and spread offsets are deliberately ignored, since
		# both make the shot breathe and the point here is that it does not.
		target_arm = _fitted_arm_length()
	else:
		var spread_arm := minf(_target_spread() * spread_zoom_scale, max_spread_arm_length)
		target_arm = base_arm_length + max_speed_arm_length_offset * speed_alpha + spread_arm
	current_arm_length = UeMath.finterp_to(
		current_arm_length, target_arm, delta, transform_interp_speed
	)
	current_pitch_deg = UeMath.finterp_to(
		current_pitch_deg,
		base_pitch_deg + max_speed_pitch_offset_deg * speed_alpha,
		delta,
		transform_interp_speed
	)
	current_fov = UeMath.finterp_to(
		current_fov, base_fov + max_speed_fov_offset * speed_alpha, delta, transform_interp_speed
	)

	var target_roll := 0.0
	if active.size() == 1:
		var lateral_alpha := clampf(
			active[0].get_lateral_speed() / maxf(0.01, lateral_speed_for_max_roll), -1.0, 1.0
		)
		target_roll = lateral_alpha * max_lateral_roll_deg
	current_roll_deg = UeMath.finterp_to(
		current_roll_deg, target_roll, delta, roll_interp_speed
	)

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
		target_offset = direction * look_ahead_distance * speed_alpha * (1.0 - center_bias)

	current_look_ahead = UeMath.vinterp_to(
		current_look_ahead, target_offset, delta, look_ahead_interp_speed
	)


## Spring-arm position lag: ease the focus point toward the car, then clamp how
## far behind it is allowed to fall.
func _update_focus(delta: float) -> void:
	var desired := _focus_point() + current_look_ahead
	if not enable_camera_lag:
		_lagged_focus = desired
		current_lag_speed = 0.0
		return

	current_lag_speed = lerpf(
		maxf(0.0, camera_lag_speed_at_low_speed),
		maxf(0.0, camera_lag_speed_at_high_speed),
		speed_alpha
	)
	_lagged_focus = UeMath.vinterp_to(_lagged_focus, desired, delta, current_lag_speed)

	var offset := _lagged_focus - desired
	if offset.length() > camera_lag_max_distance:
		_lagged_focus = desired + offset.normalized() * camera_lag_max_distance


func _apply_transform() -> void:
	global_position = _lagged_focus
	if _camera == null:
		return
	# Pitch and pull-back live on the camera; the rig keeps its world-fixed yaw.
	_camera.rotation = Vector3(deg_to_rad(current_pitch_deg), 0.0, deg_to_rad(current_roll_deg))
	_camera.position = Vector3(0.0, 0.0, current_arm_length).rotated(
		Vector3.RIGHT, deg_to_rad(current_pitch_deg)
	)
	_camera.fov = current_fov
