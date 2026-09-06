class_name BrakeDashSkill
extends Node
## Port of UCaddyVehicleSkillComponent's brake-dash state machine.
##
## Unreal ran this twice over: once in the component tick and once inside
## UCaddyVehicleBrakeDashAbility on a 120 Hz GAS timer. The two were the same
## logic, so this is a single state machine ticked at the physics rate.
##
## Ready -> Braking -> Charging -> Dashing. While active it takes the car over
## entirely through ArcadeVehicle.external_velocity_control, which stops the car
## computing its own velocity but leaves collision resolution running, so a dash
## still hits walls and cars properly.

## Ticks ahead of the vehicle so the override velocity lands the same frame.
const _SKILL_PRIORITY := -5

enum State {
	READY,
	BRAKING,
	CHARGING,
	DASHING,
}

signal state_changed(new_state: State, previous_state: State)
signal dash_started(direction: Vector3, charge_alpha: float, peak_speed: float)
signal dash_finished(carry_speed: float)

@export var vehicle: ArcadeVehicle
@export var tuning: SkillTuning

var state := State.READY
var state_elapsed := 0.0
var cooldown_remaining := 0.0
var trigger_hold_seconds := 0.0
var skill_input_pressed := false

var current_aim := Vector3.FORWARD
var dash_direction := Vector3.FORWARD
var current_override_speed := 0.0
var current_charge_seconds := 0.0
var current_charge_alpha := 0.0
var active_dash_duration := 0.0
var active_dash_peak_speed := 0.0

var current_target: Node3D = null
var using_target_aim := false

var _trigger_latch := false
var _braking_start_speed := 0.0
var _braking_direction := Vector3.FORWARD
var _shape_cast: ShapeCast3D


func _ready() -> void:
	process_physics_priority = _SKILL_PRIORITY
	if vehicle == null:
		vehicle = get_parent() as ArcadeVehicle
	if tuning == null:
		tuning = SkillTuning.new()


## Rewind support for client prediction. Easy to overlook and fatal if missed: a
## rewind that restores the car's position but not the dash phase resimulates
## from the wrong state machine and diverges immediately.
func capture_state() -> Dictionary:
	return {
		"state": state,
		"elapsed": state_elapsed,
		"cooldown": cooldown_remaining,
		"hold": trigger_hold_seconds,
		"pressed": skill_input_pressed,
		"latch": _trigger_latch,
		"aim": current_aim,
		"dash_dir": dash_direction,
		"override": current_override_speed,
		"charge_s": current_charge_seconds,
		"charge_a": current_charge_alpha,
		"dash_duration": active_dash_duration,
		"dash_peak": active_dash_peak_speed,
		"brake_speed": _braking_start_speed,
		"brake_dir": _braking_direction,
	}


func apply_state(snapshot: Dictionary) -> void:
	state = snapshot.get("state", state)
	state_elapsed = snapshot.get("elapsed", state_elapsed)
	cooldown_remaining = snapshot.get("cooldown", cooldown_remaining)
	trigger_hold_seconds = snapshot.get("hold", trigger_hold_seconds)
	skill_input_pressed = snapshot.get("pressed", skill_input_pressed)
	_trigger_latch = snapshot.get("latch", _trigger_latch)
	current_aim = snapshot.get("aim", current_aim)
	dash_direction = snapshot.get("dash_dir", dash_direction)
	current_override_speed = snapshot.get("override", current_override_speed)
	current_charge_seconds = snapshot.get("charge_s", current_charge_seconds)
	current_charge_alpha = snapshot.get("charge_a", current_charge_alpha)
	active_dash_duration = snapshot.get("dash_duration", active_dash_duration)
	active_dash_peak_speed = snapshot.get("dash_peak", active_dash_peak_speed)
	_braking_start_speed = snapshot.get("brake_speed", _braking_start_speed)
	_braking_direction = snapshot.get("brake_dir", _braking_direction)


func is_active() -> bool:
	return state != State.READY


func can_trigger_now() -> bool:
	return (
		tuning.enable_brake_dash and state == State.READY and cooldown_remaining <= 0.0001
	)


func set_skill_input_pressed(pressed: bool) -> void:
	skill_input_pressed = pressed


func _physics_process(delta: float) -> void:
	if vehicle == null or delta <= 0.0001:
		return

	cooldown_remaining = maxf(0.0, cooldown_remaining - delta)

	var trigger_held := _is_trigger_source_held()
	if not trigger_held:
		trigger_hold_seconds = 0.0
		_trigger_latch = false

	if not tuning.enable_brake_dash:
		if state != State.READY:
			abort_to_ready()
		return

	if state == State.READY and cooldown_remaining <= 0.0001 and trigger_held and not _trigger_latch:
		trigger_hold_seconds += delta
		if trigger_hold_seconds >= tuning.trigger_input_hold_seconds:
			_trigger_latch = true
			_enter_brake_phase()

	if state == State.READY:
		_clear_target()
		return

	state_elapsed += delta

	match state:
		State.BRAKING:
			_tick_braking(delta)
		State.CHARGING:
			_tick_charging(delta, trigger_held)
		State.DASHING:
			_tick_dashing()


func _tick_braking(delta: float) -> void:
	_update_aim_direction()
	_rotate_toward_aim(delta)

	var duration := maxf(0.01, tuning.brake_duration)
	var t := clampf(state_elapsed / duration, 0.0, 1.0)
	current_override_speed = _braking_start_speed * clampf(_evaluate_brake_alpha(t), 0.0, 1.0)
	_apply_override_velocity(_braking_direction * current_override_speed)

	if t >= 1.0:
		_apply_override_velocity(Vector3.ZERO)
		_enter_charging_phase()


func _tick_charging(delta: float, trigger_held: bool) -> void:
	_update_aim_direction()
	_rotate_toward_aim(delta)

	current_charge_seconds = clampf(state_elapsed, 0.0, maxf(0.01, tuning.max_charge_seconds))
	current_charge_alpha = _evaluate_charge_alpha(current_charge_seconds)

	current_override_speed = 0.0
	_apply_override_velocity(Vector3.ZERO)

	var reached_max := current_charge_seconds >= tuning.max_charge_seconds
	var can_release := current_charge_seconds >= tuning.min_charge_seconds
	if reached_max or (not trigger_held and can_release):
		_enter_dash_phase()


func _tick_dashing() -> void:
	var duration := maxf(0.01, active_dash_duration)
	var t := clampf(state_elapsed / duration, 0.0, 1.0)
	current_override_speed = active_dash_peak_speed * clampf(_evaluate_dash_alpha(t), 0.0, 1.0)
	_apply_override_velocity(dash_direction * current_override_speed)

	if t >= 1.0:
		_exit_dash_phase()


# ---------------------------------------------------------------------------
# Phase transitions
# ---------------------------------------------------------------------------

func _enter_brake_phase() -> void:
	_set_state(State.BRAKING)
	current_override_speed = 0.0
	current_charge_seconds = 0.0
	current_charge_alpha = 0.0
	active_dash_duration = 0.0
	active_dash_peak_speed = 0.0

	_update_aim_direction()
	if current_aim.is_zero_approx():
		current_aim = _fallback_aim_direction()

	# Braking decays along the direction the car is actually travelling, not
	# where it is pointing, so a drift entry keeps sliding as it slows.
	var planar_velocity := Vector3(vehicle.velocity.x, 0.0, vehicle.velocity.z)
	_braking_start_speed = planar_velocity.length()
	_braking_direction = (
		planar_velocity.normalized() if _braking_start_speed > 0.0001 else current_aim
	)

	vehicle.set_external_velocity_control_enabled(true)


func _enter_charging_phase() -> void:
	_set_state(State.CHARGING)
	current_override_speed = 0.0
	current_charge_seconds = 0.0
	current_charge_alpha = 0.0


func _enter_dash_phase() -> void:
	_update_aim_direction()
	dash_direction = current_aim if not current_aim.is_zero_approx() else _fallback_aim_direction()
	if dash_direction.is_zero_approx():
		dash_direction = Vector3.FORWARD

	current_charge_seconds = clampf(
		current_charge_seconds, 0.0, maxf(0.01, tuning.max_charge_seconds)
	)
	current_charge_alpha = _evaluate_charge_alpha(current_charge_seconds)

	active_dash_duration = maxf(
		0.01,
		lerpf(
			tuning.dash_duration_at_min_charge,
			tuning.dash_duration_at_max_charge,
			current_charge_alpha
		)
	)
	active_dash_peak_speed = maxf(
		0.0,
		lerpf(
			tuning.dash_peak_speed_at_min_charge,
			tuning.dash_peak_speed_at_max_charge,
			current_charge_alpha
		)
	)

	_set_state(State.DASHING)
	current_override_speed = 0.0
	vehicle.set_external_velocity_control_enabled(true)
	vehicle.skill_dashing = true
	dash_started.emit(dash_direction, current_charge_alpha, active_dash_peak_speed)


func _exit_dash_phase() -> void:
	vehicle.set_external_velocity_control_enabled(false)
	vehicle.skill_dashing = false

	# Exit still rolling rather than dropping to a standstill.
	var carry_speed := active_dash_peak_speed * clampf(tuning.post_dash_carry_ratio, 0.0, 1.0)
	vehicle.set_external_planar_velocity(dash_direction.normalized() * carry_speed)

	_set_state(State.READY)
	current_override_speed = 0.0
	_braking_start_speed = 0.0
	cooldown_remaining = maxf(0.0, tuning.cooldown_seconds)
	_clear_target()
	dash_finished.emit(carry_speed)


func abort_to_ready() -> void:
	if vehicle != null:
		vehicle.set_external_velocity_control_enabled(false)
		vehicle.skill_dashing = false

	_set_state(State.READY)
	current_override_speed = 0.0
	_braking_start_speed = 0.0
	current_charge_seconds = 0.0
	current_charge_alpha = 0.0
	active_dash_duration = 0.0
	active_dash_peak_speed = 0.0
	_clear_target()


func _set_state(new_state: State) -> void:
	var previous := state
	state = new_state
	state_elapsed = 0.0
	if previous != new_state:
		state_changed.emit(new_state, previous)


# ---------------------------------------------------------------------------
# Curves
# ---------------------------------------------------------------------------

func _evaluate_brake_alpha(normalized_time: float) -> float:
	if tuning.brake_speed_alpha_curve != null:
		return tuning.brake_speed_alpha_curve.sample(normalized_time)
	return pow(1.0 - clampf(normalized_time, 0.0, 1.0), 2.2)


func _evaluate_dash_alpha(normalized_time: float) -> float:
	if tuning.dash_speed_alpha_curve != null:
		return tuning.dash_speed_alpha_curve.sample(normalized_time)
	return UeMath.interp_ease_in_out(1.0, 0.0, normalized_time, 1.6)


func _evaluate_charge_alpha(charge_seconds: float) -> float:
	var hold_alpha := clampf(charge_seconds / maxf(0.01, tuning.max_charge_seconds), 0.0, 1.0)
	if tuning.charge_alpha_curve != null:
		return clampf(tuning.charge_alpha_curve.sample(hold_alpha), 0.0, 1.0)
	return hold_alpha


# ---------------------------------------------------------------------------
# Aim
# ---------------------------------------------------------------------------

func _is_trigger_source_held() -> bool:
	if tuning.trigger_mode == SkillTuning.TriggerMode.BRAKE_THROTTLE_COMBO:
		return (
			vehicle.throttle_input >= tuning.trigger_throttle_threshold
			and vehicle.brake_reverse_input >= tuning.trigger_brake_threshold
		)
	return skill_input_pressed


func _fallback_aim_direction() -> Vector3:
	var forward := vehicle.planar_forward()
	return forward if not forward.is_zero_approx() else Vector3.FORWARD


func _input_aim_direction() -> Vector3:
	if (
		vehicle.has_move_intent
		and vehicle.move_intent.length_squared() >= pow(tuning.aim_input_dead_zone, 2.0)
	):
		return vehicle.move_intent.normalized()
	return Vector3.ZERO


func _update_aim_direction() -> void:
	_clear_target()

	var input_aim := _input_aim_direction()
	var target_aim := _resolve_target_aim()
	var has_input_aim := not input_aim.is_zero_approx()
	var has_target_aim := not target_aim.is_zero_approx()

	var selected := current_aim
	var selected_target := false

	match tuning.aim_selection_mode:
		SkillTuning.AimSelectionMode.INPUT_ONLY:
			if has_input_aim:
				selected = input_aim
		SkillTuning.AimSelectionMode.TARGET_ONLY:
			if has_target_aim:
				selected = target_aim
				selected_target = true
		_:
			if has_target_aim:
				selected = target_aim
				selected_target = true
			elif has_input_aim:
				selected = input_aim

	if selected.is_zero_approx():
		selected = _fallback_aim_direction()

	current_aim = selected.normalized()
	if current_aim.is_zero_approx():
		current_aim = Vector3.FORWARD

	if not selected_target:
		_clear_target()


## Rotates the body toward the aim direction. Unlike normal steering this works
## at zero velocity, which is what lets the car pivot on the spot while charging.
func _rotate_toward_aim(delta: float) -> void:
	if not tuning.rotate_to_aim_during_charge or current_aim.is_zero_approx():
		return
	vehicle.rotation.y = rotate_toward(
		vehicle.rotation.y,
		UeMath.heading_to_yaw(current_aim),
		deg_to_rad(tuning.aim_rotation_rate_deg) * delta
	)


## Sphere-sweeps for a lock-on target ahead of the car. Stands in for UE's
## GAS target actor plus HitRegisterTargetingProfile filtering.
func _resolve_target_aim() -> Vector3:
	if not tuning.enable_targeting:
		return Vector3.ZERO

	var direction := _input_aim_direction()
	if direction.is_zero_approx():
		direction = _fallback_aim_direction()
	if direction.is_zero_approx():
		return Vector3.ZERO

	var cast := _ensure_shape_cast()
	cast.global_position = vehicle.global_position
	cast.target_position = cast.to_local(
		vehicle.global_position + direction * maxf(0.1, tuning.trace_distance)
	)
	cast.force_shapecast_update()

	var best: Node3D = null
	var best_distance := INF
	for i in cast.get_collision_count():
		var collider := cast.get_collider(i) as Node3D
		if collider == null or collider == vehicle:
			continue
		if tuning.target_group != &"" and not collider.is_in_group(tuning.target_group):
			continue
		var distance := vehicle.global_position.distance_to(cast.get_collision_point(i))
		if distance < best_distance:
			best_distance = distance
			best = collider

	if best == null:
		return Vector3.ZERO

	var to_target := best.global_position - vehicle.global_position
	to_target.y = 0.0
	if to_target.is_zero_approx():
		return Vector3.ZERO

	current_target = best
	using_target_aim = true
	return to_target.normalized()


func _ensure_shape_cast() -> ShapeCast3D:
	if _shape_cast != null:
		return _shape_cast

	_shape_cast = ShapeCast3D.new()
	_shape_cast.top_level = true
	_shape_cast.enabled = false
	_shape_cast.max_results = 16
	var sphere := SphereShape3D.new()
	sphere.radius = maxf(0.01, tuning.trace_radius)
	_shape_cast.shape = sphere
	_shape_cast.collision_mask = tuning.trace_mask
	_shape_cast.add_exception(vehicle)
	add_child(_shape_cast)
	return _shape_cast


func _clear_target() -> void:
	current_target = null
	using_target_aim = false


func _apply_override_velocity(world_velocity: Vector3) -> void:
	vehicle.set_external_planar_velocity(world_velocity)
