class_name VehicleFeel
extends Node
## Cosmetic squash, stretch and kick. Port of UCaddyVehicleFeelComponent.
##
## Everything is applied to `visual_root`, a plain Node3D holding the meshes, so
## the collision body and all the physics above it are untouched. Nothing here
## can change where the car actually is.
##
## Two continuous layers (acceleration deform, lateral lean, engine idle) are
## interpolated toward a target every frame. Two one-shot layers (impact, dash)
## run an eased envelope over a fixed duration and add on top. No effect is
## linear — see Easing for why.

@export var vehicle: ArcadeVehicle
## Node holding the meshes. Never the collision body.
@export var visual_root: Node3D
@export var tuning: FeelTuning
@export var skill: BrakeDashSkill

## Local-space axes of the car mesh: X width, Y height, Z length.
const _LENGTH_AXIS := Vector3(0.0, 0.0, 1.0)

var _base_scale := Vector3.ONE
var _base_position := Vector3.ZERO

var _current_scale_offset := Vector3.ZERO
var _current_position_offset := Vector3.ZERO
var _current_rotation_offset := Vector3.ZERO

var _impact_elapsed := -1.0
var _impact_strength := 0.0
## Impact direction in the car's local space at the moment of the hit.
var _impact_local_dir := Vector3.ZERO

var _dash_elapsed := -1.0
var _dash_strength := 0.0

var _engine_phase := 0.0
var _previous_forward_speed := 0.0
## Sampled once per frame from the change in forward speed.
var _acceleration := 0.0


func _ready() -> void:
	if vehicle == null:
		vehicle = get_parent() as ArcadeVehicle
	if tuning == null:
		tuning = FeelTuning.new()
	if visual_root != null:
		_base_scale = visual_root.scale
		_base_position = visual_root.position

	if vehicle != null:
		vehicle.blocking_collision.connect(_on_blocking_collision)
	if skill != null:
		skill.dash_started.connect(_on_dash_started)


## Fired for walls as well as cars, so scraping a wall still registers physically.
func _on_blocking_collision(event: VehicleCollisionEvent) -> void:
	play_impact(event.normal_impact_speed, event.normal)


## Public so the combat layer can trigger a stronger pulse than the raw collision.
func play_impact(normal_impact_speed: float, world_normal: Vector3) -> void:
	if not tuning.enable_impact_pulse or visual_root == null or vehicle == null:
		return

	var strength := clampf(
		normal_impact_speed / maxf(0.01, tuning.impact_speed_for_max_pulse), 0.0, 1.0
	)
	if strength <= 0.001:
		return
	# A harder hit landing mid-pulse restarts it; a softer one does not stomp it.
	if _impact_elapsed >= 0.0 and strength < _impact_strength:
		return

	_impact_strength = strength
	_impact_elapsed = 0.0

	# Store the hit direction in local space so the squash axis follows the body
	# as it spins out, rather than staying stuck to a world direction.
	var planar_normal := Vector3(world_normal.x, 0.0, world_normal.z).normalized()
	if planar_normal.is_zero_approx():
		planar_normal = -vehicle.planar_forward()
	_impact_local_dir = vehicle.global_transform.basis.inverse() * (-planar_normal)
	_impact_local_dir.y = 0.0
	_impact_local_dir = _impact_local_dir.normalized()


func _on_dash_started(_direction: Vector3, charge_alpha: float, _peak_speed: float) -> void:
	if not tuning.enable_dash_pulse:
		return
	# A short-charge dash pops less than a full one.
	_dash_strength = lerpf(0.55, 1.0, clampf(charge_alpha, 0.0, 1.0))
	_dash_elapsed = 0.0


func _process(delta: float) -> void:
	if vehicle == null or visual_root == null:
		return

	_sample_acceleration(delta)

	var target_scale := Vector3.ZERO
	var target_position := Vector3.ZERO
	var target_rotation := Vector3.ZERO

	target_scale += _acceleration_deform()
	target_scale += _engine_vibration(delta)
	target_scale += _charge_anticipation()
	target_rotation.z += _lateral_lean()

	# Continuous layers ease toward their target; one-shots are added raw so
	# their own envelope controls the attack rather than the smoothing.
	_current_scale_offset = UeMath.vinterp_to(
		_current_scale_offset, target_scale, delta, tuning.scale_interp_speed
	)
	_current_position_offset = UeMath.vinterp_to(
		_current_position_offset, target_position, delta, tuning.offset_interp_speed
	)
	_current_rotation_offset = UeMath.vinterp_to(
		_current_rotation_offset, target_rotation, delta, tuning.offset_interp_speed
	)

	var scale_offset := _current_scale_offset
	var position_offset := _current_position_offset
	var rotation_offset := _current_rotation_offset

	scale_offset += _impact_scale(delta)
	position_offset += _impact_position()
	rotation_offset += _impact_rotation()
	scale_offset += _dash_scale(delta)

	visual_root.scale = _base_scale + scale_offset
	visual_root.position = _base_position + position_offset
	visual_root.rotation = rotation_offset


## Kept separate so the speed sample advances exactly once per frame.
func _sample_acceleration(delta: float) -> void:
	var forward_speed := vehicle.get_forward_speed()
	_acceleration = (forward_speed - _previous_forward_speed) / maxf(0.0001, delta)
	_previous_forward_speed = forward_speed


## Stretches along the length under power, squashes under braking.
func _acceleration_deform() -> Vector3:
	if not tuning.enable_acceleration_deform:
		return Vector3.ZERO

	var accel_alpha := clampf(
		_acceleration / maxf(0.01, tuning.max_forward_accel_for_deform), -1.0, 1.0
	)
	# Eased, so a small throttle blip does not deform as much as its raw ratio.
	var eased := signf(accel_alpha) * Easing.in_out_cubic(absf(accel_alpha))
	var stretch := eased * tuning.max_accel_squash_stretch

	var speed_alpha := clampf(
		absf(vehicle.get_forward_speed()) / maxf(0.01, tuning.max_speed_for_stretch), 0.0, 1.0
	)
	stretch += Easing.in_out_cubic(speed_alpha) * tuning.max_speed_stretch

	# Volume-ish preservation: what the length gains, width and height give up.
	return Vector3(-stretch * 0.5, -stretch * 0.5, stretch)


func _lateral_lean() -> float:
	if not tuning.enable_lateral_lean:
		return 0.0
	var lateral_alpha := clampf(
		vehicle.get_lateral_speed() / maxf(0.01, tuning.lateral_speed_for_max_lean), -1.0, 1.0
	)
	var eased := signf(lateral_alpha) * Easing.in_out_cubic(absf(lateral_alpha))
	return deg_to_rad(-eased * tuning.max_lateral_lean_roll_deg)


## Idle shake, expressed only as scale. Rises with speed and throttle.
func _engine_vibration(delta: float) -> Vector3:
	if not tuning.enable_engine_vibration:
		return Vector3.ZERO

	var speed_alpha := clampf(
		vehicle.get_planar_speed() / maxf(0.01, tuning.engine_speed_for_normalization), 0.0, 1.0
	)
	var input_load := maxf(vehicle.throttle_input, vehicle.brake_reverse_input)

	var variance := tuning.engine_base_variance * (1.0 + speed_alpha)
	variance += tuning.engine_throttle_variance_boost * input_load
	variance = minf(variance, tuning.engine_max_variance)

	var frequency := tuning.engine_base_frequency_hz * (1.0 + speed_alpha)
	frequency += tuning.engine_throttle_frequency_boost_hz * input_load

	_engine_phase += delta * frequency * TAU
	# Two frequencies so it reads as an engine rather than a clean sine.
	var wobble := sin(_engine_phase) * 0.7 + sin(_engine_phase * 1.7) * 0.3
	return Vector3(-wobble, wobble, -wobble * 0.5) * variance


## Anticipation while the dash charges: the car compresses before it fires.
func _charge_anticipation() -> Vector3:
	if skill == null or not tuning.enable_dash_pulse:
		return Vector3.ZERO
	if skill.state != BrakeDashSkill.State.CHARGING:
		return Vector3.ZERO

	var squash := Easing.in_out_cubic(skill.current_charge_alpha) * tuning.dash_charge_squash
	return Vector3(squash * 0.5, squash * 0.35, -squash)


func _impact_envelope(delta: float) -> float:
	if _impact_elapsed < 0.0:
		return 0.0
	_impact_elapsed += delta
	var duration := maxf(0.01, tuning.impact_pulse_duration)
	var t := _impact_elapsed / duration
	if t >= 1.0:
		_impact_elapsed = -1.0
		_impact_strength = 0.0
		return 0.0
	if tuning.impact_pulse_curve != null:
		return tuning.impact_pulse_curve.sample(t) * _impact_strength
	# Overshoots on the way in: this is the one that should read as a hit.
	return Easing.pulse_back(t, tuning.impact_attack) * _impact_strength


func _impact_scale(delta: float) -> Vector3:
	var amount := _impact_envelope(delta) * tuning.impact_pulse_scale
	if is_zero_approx(amount):
		return Vector3.ZERO

	# Squash along whichever local axis took the hit, bulge across the other.
	var along_length := absf(_impact_local_dir.z)
	var along_width := absf(_impact_local_dir.x)
	return Vector3(
		-along_width * amount + along_length * amount * 0.5,
		amount * 0.35,
		-along_length * amount + along_width * amount * 0.5
	)


func _impact_position() -> Vector3:
	if _impact_elapsed < 0.0:
		return Vector3.ZERO
	var duration := maxf(0.01, tuning.impact_pulse_duration)
	var envelope := Easing.pulse(_impact_elapsed / duration, tuning.impact_attack)
	var amount := envelope * _impact_strength * tuning.impact_pulse_location_kick
	# Shoved back the way it came from.
	return -_impact_local_dir * amount


func _impact_rotation() -> Vector3:
	if _impact_elapsed < 0.0:
		return Vector3.ZERO
	var duration := maxf(0.01, tuning.impact_pulse_duration)
	var envelope := Easing.pulse(_impact_elapsed / duration, tuning.impact_attack)
	var amount := deg_to_rad(envelope * _impact_strength * tuning.impact_pulse_rotation_kick_deg)
	# Hit from the side rolls the body; hit head-on pitches it.
	return Vector3(_impact_local_dir.z * amount, 0.0, -_impact_local_dir.x * amount)


func _dash_scale(delta: float) -> Vector3:
	if _dash_elapsed < 0.0:
		return Vector3.ZERO

	_dash_elapsed += delta
	var duration := maxf(0.01, tuning.dash_pulse_duration)
	var t := _dash_elapsed / duration
	if t >= 1.0:
		_dash_elapsed = -1.0
		_dash_strength = 0.0
		return Vector3.ZERO

	var envelope := (
		tuning.dash_pulse_curve.sample(t)
		if tuning.dash_pulse_curve != null
		else Easing.pulse_back(t, tuning.dash_attack)
	)
	var stretch := envelope * _dash_strength * tuning.dash_pulse_stretch
	return Vector3(-stretch * 0.5, -stretch * 0.4, stretch)
