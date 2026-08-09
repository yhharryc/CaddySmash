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
## Drives the always-on outline colour, so a player can read who wins a contest
## before the crash rather than after it.
@export var momentum: VehicleMomentum

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
## Advances faster the closer the charge gets to firing.
var _charge_phase := 0.0
## Inverted-hull copies of each mesh, shown only while an impact is playing.
var _outlines: Array[MeshInstance3D] = []
var _outline_materials: Array[StandardMaterial3D] = []


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

	_build_outlines()


## Inverted-hull outline: a copy of each mesh with front faces culled and the
## surface grown along its normals, so it renders as a shell behind the car.
## Built as separate nodes rather than a next_pass on the body material, because
## MatchManager replaces that material to tint each player and would drop it.
func _build_outlines() -> void:
	if visual_root == null or not tuning.enable_impact_outline:
		return

	for child in visual_root.get_children():
		var mesh_instance := child as MeshInstance3D
		if mesh_instance == null or mesh_instance.mesh == null:
			continue

		var material := StandardMaterial3D.new()
		material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
		material.cull_mode = BaseMaterial3D.CULL_FRONT
		material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
		material.albedo_color = tuning.impact_outline_color
		material.grow = true
		material.grow_amount = 0.0

		var outline := MeshInstance3D.new()
		outline.mesh = mesh_instance.mesh
		outline.transform = mesh_instance.transform
		outline.material_override = material
		outline.visible = false
		visual_root.add_child(outline)

		_outlines.append(outline)
		_outline_materials.append(material)


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
	target_scale += _charge_anticipation(delta)
	target_rotation.z += _lateral_lean()

	var swing: Dictionary = _charge_swing()
	target_rotation.y += swing["yaw"]
	target_position += swing["offset"]

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


## Anticipation while the dash charges. Three things build together, all keyed
## off charge alpha through an ease so they load late rather than linearly:
## the body compresses, it shudders in time with the wiggle, and the wiggle
## itself speeds up — which is what reads as the car straining to be let go.
func _charge_anticipation(delta: float) -> Vector3:
	if skill == null or not tuning.enable_dash_pulse:
		_charge_phase = 0.0
		return Vector3.ZERO
	if skill.state != BrakeDashSkill.State.CHARGING:
		_charge_phase = 0.0
		return Vector3.ZERO

	var alpha := Easing.in_out_cubic(clampf(skill.current_charge_alpha, 0.0, 1.0))
	var frequency := lerpf(tuning.charge_wiggle_base_hz, tuning.charge_wiggle_max_hz, alpha)
	_charge_phase += delta * frequency * TAU

	var squash := alpha * tuning.dash_charge_squash
	# Pumped in time with the wiggle so the compression visibly throbs.
	squash += sin(_charge_phase * 2.0) * alpha * tuning.charge_shudder
	return Vector3(squash * 0.5, squash * 0.35, -squash)


## Tail swing: yaw the body, then shove it laterally against that yaw so the
## nose stays roughly planted and the back end does the swinging.
func _charge_swing() -> Dictionary:
	if skill == null or skill.state != BrakeDashSkill.State.CHARGING:
		return {"yaw": 0.0, "offset": Vector3.ZERO}

	var alpha := Easing.in_out_cubic(clampf(skill.current_charge_alpha, 0.0, 1.0))
	var wave := sin(_charge_phase)
	var yaw := deg_to_rad(wave * alpha * tuning.charge_wiggle_max_deg)
	var offset := Vector3(-wave * alpha * tuning.charge_tail_swing, 0.0, 0.0)
	return {"yaw": yaw, "offset": offset}


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


## The car swells on impact rather than shrinking. A hit that makes your car
## smaller reads as your car losing; a sudden bulge reads as force delivered.
## The bias keeps it from being a plain balloon: the axis that took the hit
## grows least, the axis across it grows most, so the direction still reads.
func _impact_scale(delta: float) -> Vector3:
	var envelope := _impact_envelope(delta)
	_drive_outline(envelope)
	var amount := envelope * tuning.impact_inflate
	if is_zero_approx(amount):
		return Vector3.ZERO

	var along_length := absf(_impact_local_dir.z)
	var along_width := absf(_impact_local_dir.x)
	var bias := tuning.impact_directional_bias
	return Vector3(
		amount * (1.0 - bias * along_width + bias * along_length),
		amount * (1.0 + bias * 0.5),
		amount * (1.0 - bias * along_length + bias * along_width)
	)


## The outline serves two jobs at once: it is always on, showing momentum tier by
## colour and thickness, and an impact flashes it white on top. The two are
## combined by taking whichever is stronger, so a hit always reads even at low
## momentum, and momentum never masks a hit.
func _drive_outline(impact_envelope: float) -> void:
	if _outlines.is_empty():
		return

	var momentum_color := MomentumTier.COLORS[0]
	var momentum_weight := 0.0
	if momentum != null:
		momentum_color = MomentumTier.color_of(momentum.tier)
		# Eased so the step between tiers is a swell rather than a jump.
		momentum_weight = _momentum_outline_weight()

	var impact_weight := clampf(impact_envelope, 0.0, 1.0)
	var strength := maxf(momentum_weight, impact_weight)
	var visible_now := strength > 0.001

	# The impact flash wins the colour only while it is the stronger of the two.
	var color := (
		tuning.impact_outline_color if impact_weight >= momentum_weight else momentum_color
	)
	color.a = strength

	for i in _outlines.size():
		_outlines[i].visible = visible_now
		if visible_now:
			_outline_materials[i].grow_amount = strength * tuning.impact_outline_grow
			_outline_materials[i].albedo_color = color


## How present the momentum outline is: none at LOW, growing through MID, full at
## HIGH. LOW is deliberately invisible so "no outline" itself reads as a state.
func _momentum_outline_weight() -> float:
	match momentum.tier:
		MomentumTier.Value.HIGH:
			return 1.0
		MomentumTier.Value.MID:
			return lerpf(0.45, 0.75, Easing.in_out_cubic(momentum.charge))
		_:
			return 0.0


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
