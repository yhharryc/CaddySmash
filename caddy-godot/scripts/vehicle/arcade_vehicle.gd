class_name ArcadeVehicle
extends CharacterBody3D
## Port of UArcadeVehicleMovementComponent (CaddySmash / Unreal 5.7).
##
## Kinematic arcade car. There is no rigidbody, no suspension and no gravity:
## motion is entirely planar and velocity.y is pinned to zero every frame.
##
## The drift model is the whole point of this class. Steering rotates the body
## but never rotates the velocity vector, so yawing instantly converts forward
## speed into lateral speed, which then bleeds off at a friction rate. High
## friction reads as grippy, low friction as a slide. The car rests in the
## low-friction state; holding grip is what makes it bite.

const _DEAD_SMALL := 0.0001

## Emitted for each blocking collision resolved during a movement tick.
signal blocking_collision(event: VehicleCollisionEvent)

@export var tuning: VehicleTuning
## Node whose Y rotation defines "up" for move intent. Usually the camera rig.
## Leave null to treat raw input as world-space.
@export var intent_yaw_source: Node3D

# --- Input state (world space, set from a driver node) ---
var move_intent := Vector3.ZERO
var has_move_intent := false
var throttle_input := 0.0
var brake_reverse_input := 0.0
var grip_input := 0.0

# --- Derived state ---
var is_drifting := true
var reverse_steering_active := false

# --- External overrides ---
## While true the car keeps colliding but stops computing its own velocity.
## Skills (brake-dash, knockback) drive velocity directly through this.
var external_velocity_control := false
## Stagger and similar effects zero all input through this.
var control_locked := false

## Set by the skill layer so collision events can be tagged as dash impacts.
var skill_dashing := false

var last_collision: VehicleCollisionEvent = null
var last_collision_time := -1.0


func _ready() -> void:
	# No floor, no gravity: every surface is a wall.
	motion_mode = CharacterBody3D.MOTION_MODE_FLOATING
	if tuning == null:
		tuning = VehicleTuning.new()
	# ClashArbiter snapshots every car in this group before anything moves.
	add_to_group(ClashArbiter.VEHICLE_GROUP)


func _physics_process(delta: float) -> void:
	if delta <= _DEAD_SMALL:
		return

	if not external_velocity_control:
		_update_velocity(delta)
		_update_steering(delta)

	_perform_movement(delta)


# ---------------------------------------------------------------------------
# Input API (mirrors the UE SetX functions, including the control-lock gate)
# ---------------------------------------------------------------------------

## Takes a world-space planar direction; magnitude below the dead zone clears intent.
func set_move_intent(world_direction: Vector3) -> void:
	if control_locked:
		has_move_intent = false
		move_intent = Vector3.ZERO
		return

	var planar := Vector3(world_direction.x, 0.0, world_direction.z)
	var size := planar.length()
	if size < tuning.move_intent_dead_zone:
		has_move_intent = false
		move_intent = Vector3.ZERO
		return

	has_move_intent = true
	move_intent = planar / size


## Convenience for driver nodes: converts a raw 2D stick vector (x = right,
## y = forward) into world space through intent_yaw_source, then applies it.
##
## The dead zone is tested here, on the raw stick. UE normalized in
## ComputeWorldMoveIntent before SetMoveIntent could test it, so
## MoveIntentDeadZone never fired for a player and Enhanced Input's own dead
## zone did the work instead. Same pipeline shape, one fewer dead config field.
func set_move_intent_from_stick(stick: Vector2) -> void:
	if stick.length() < tuning.move_intent_dead_zone:
		set_move_intent(Vector3.ZERO)
		return

	var yaw: float = intent_yaw_source.global_rotation.y if intent_yaw_source != null else 0.0
	var forward := UeMath.yaw_to_heading(yaw)
	var right := forward.cross(Vector3.UP)
	set_move_intent((forward * stick.y + right * stick.x).normalized())


func set_throttle_input(value: float) -> void:
	throttle_input = 0.0 if control_locked else clampf(value, 0.0, 1.0)


func set_brake_reverse_input(value: float) -> void:
	brake_reverse_input = 0.0 if control_locked else clampf(value, 0.0, 1.0)


## 0 = the car's default loose/drifty state, 1 = full grip.
func set_grip_input(value: float) -> void:
	grip_input = 0.0 if control_locked else clampf(value, 0.0, 1.0)
	is_drifting = grip_input < tuning.grip_input_threshold


func set_control_lock_enabled(enabled: bool) -> void:
	control_locked = enabled
	if not control_locked:
		return
	throttle_input = 0.0
	brake_reverse_input = 0.0
	grip_input = 0.0
	is_drifting = true
	has_move_intent = false
	move_intent = Vector3.ZERO
	reverse_steering_active = false


func set_external_velocity_control_enabled(enabled: bool) -> void:
	external_velocity_control = enabled


func set_external_planar_velocity(world_velocity: Vector3) -> void:
	velocity = Vector3(world_velocity.x, 0.0, world_velocity.z)


# ---------------------------------------------------------------------------
# Telemetry
# ---------------------------------------------------------------------------

func planar_forward() -> Vector3:
	return -global_transform.basis.z.slide(Vector3.UP).normalized()


func planar_right() -> Vector3:
	return global_transform.basis.x.slide(Vector3.UP).normalized()


## Signed speed along the nose. Negative while reversing.
func get_forward_speed() -> float:
	return velocity.dot(planar_forward())


## Signed sideways slip. This is the number that reads as "drift".
func get_lateral_speed() -> float:
	return velocity.dot(planar_right())


func get_planar_speed() -> float:
	return Vector2(velocity.x, velocity.z).length()


func get_max_speed() -> float:
	return tuning.max_forward_speed


## Seconds since the last blocking collision, or -1 if there has not been one.
func get_time_since_last_collision() -> float:
	if last_collision_time < 0.0:
		return -1.0
	return float(Time.get_ticks_msec()) * 0.001 - last_collision_time


# ---------------------------------------------------------------------------
# Movement
# ---------------------------------------------------------------------------

func _update_velocity(delta: float) -> void:
	var forward := planar_forward()
	var right := planar_right()

	var local_forward := velocity.dot(forward)
	var local_lateral := velocity.dot(right)
	var previous_forward := local_forward

	var has_throttle := throttle_input > _DEAD_SMALL
	var has_brake := brake_reverse_input > _DEAD_SMALL
	var wants_reverse := has_brake and not has_throttle

	if has_throttle and not has_brake:
		local_forward += throttle_input * tuning.forward_acceleration * delta

	if has_brake:
		if local_forward > 0.0:
			# Braking is a constant-rate bite, not an exponential ease.
			local_forward = UeMath.finterp_constant_to(
				local_forward, 0.0, delta, tuning.brake_deceleration * brake_reverse_input
			)
		else:
			local_forward -= brake_reverse_input * tuning.reverse_acceleration * delta
			local_forward = maxf(local_forward, -tuning.max_reverse_speed)

	if not has_throttle and not has_brake:
		local_forward = UeMath.finterp_constant_to(
			local_forward, 0.0, delta, tuning.coast_deceleration
		)

	# Drag deliberately touches only the forward axis, so a slide keeps its speed.
	local_forward *= maxf(0.0, 1.0 - tuning.linear_drag * delta)
	local_forward = clampf(local_forward, -tuning.max_reverse_speed, tuning.max_forward_speed)

	_update_reverse_steering_latch(previous_forward, local_forward, has_throttle, wants_reverse)

	var lateral_friction := (
		tuning.drift_lateral_friction if is_drifting else tuning.grip_lateral_friction
	)
	local_lateral = UeMath.finterp_to(local_lateral, 0.0, delta, lateral_friction)

	velocity = forward * local_forward + right * local_lateral
	velocity.y = 0.0


## Latches input-relative reverse steering once the car is genuinely accelerating
## backwards, with separate enter/exit speeds so it does not chatter.
func _update_reverse_steering_latch(
	previous_forward: float, local_forward: float, has_throttle: bool, wants_reverse: bool
) -> void:
	if not tuning.enable_input_relative_reverse_steering:
		reverse_steering_active = false
		return

	var enter_speed := maxf(0.0, tuning.reverse_steering_enter_speed)
	var exit_speed := clampf(tuning.reverse_steering_exit_speed, 0.0, enter_speed)

	if not reverse_steering_active:
		var accelerating_backwards := (
			wants_reverse
			and previous_forward <= 0.0
			and local_forward < previous_forward - _DEAD_SMALL
		)
		if accelerating_backwards and local_forward <= -enter_speed:
			reverse_steering_active = true
		return

	var wants_forward_drive := has_throttle and not wants_reverse
	if wants_forward_drive or local_forward >= -exit_speed:
		reverse_steering_active = false


func _update_steering(delta: float) -> void:
	if not has_move_intent:
		return

	var planar_speed_sq := velocity.x * velocity.x + velocity.z * velocity.z
	if planar_speed_sq < tuning.min_speed_for_steering * tuning.min_speed_for_steering:
		return

	var rate := deg_to_rad(tuning.steering_rate_deg)
	if is_drifting:
		rate *= tuning.drift_steering_rate_multiplier

	var input_yaw := UeMath.heading_to_yaw(move_intent)
	# Reversing aims the tail at the stick instead of the nose.
	var target_yaw := (input_yaw + PI) if reverse_steering_active else input_yaw
	rotation.y = rotate_toward(rotation.y, wrapf(target_yaw, -PI, PI), rate * delta)


## Sweep-resolve loop from UE PerformMovement. move_and_slide is deliberately not
## used: it runs its own slide resolution and rewrites velocity, which would
## fight the arcade glide response below.
func _perform_movement(delta: float) -> void:
	var stop_sq := tuning.stop_speed_threshold * tuning.stop_speed_threshold
	if velocity.length_squared() <= stop_sq:
		velocity = Vector3.ZERO
		return

	velocity.y = 0.0
	var remaining := velocity * delta
	var min_step_sq := pow(tuning.stop_speed_threshold * delta, 2.0)

	for _iteration in maxi(1, tuning.max_collision_iterations):
		if remaining.length_squared() <= min_step_sq:
			break

		var attempted := remaining
		var pre_impact_velocity := velocity
		var collision := move_and_collide(attempted)
		if collision == null:
			break

		_handle_blocking_collision(pre_impact_velocity, collision, delta)

		# UE's 1 - Hit.Time: the fraction of the step that was left unspent.
		var remaining_ratio := clampf(
			collision.get_remainder().length() / maxf(0.0001, attempted.length()), 0.0, 1.0
		)
		if remaining_ratio <= 0.0001:
			break
		remaining = velocity * delta * remaining_ratio

	velocity.y = 0.0
	if velocity.length_squared() <= stop_sq:
		velocity = Vector3.ZERO


func _handle_blocking_collision(
	pre_impact_velocity: Vector3, collision: KinematicCollision3D, delta: float
) -> void:
	var normal := collision.get_normal()
	var planar_normal := Vector3(normal.x, 0.0, normal.z).normalized()

	# UE slides the component along the wall with the leftover delta before it
	# rewrites velocity, so the car keeps travelling on the impact frame.
	var remainder := collision.get_remainder()
	if remainder.length_squared() > 0.0 and not planar_normal.is_zero_approx():
		move_and_collide(remainder.slide(planar_normal))

	var planar_velocity := Vector3(pre_impact_velocity.x, 0.0, pre_impact_velocity.z)
	var normal_impact_speed := 0.0
	var tangent := Vector3.ZERO
	var resolved := Vector3.ZERO

	if planar_normal.is_zero_approx():
		# Purely vertical surface normal has no planar component to glide along.
		resolved = Vector3.ZERO
	elif tuning.collision_response_mode == VehicleTuning.ResponseMode.ARCADE_WALL_GLIDE:
		resolved = _compute_arcade_wall_glide_velocity(planar_velocity, planar_normal, delta)
		normal_impact_speed = _glide_normal_impact_speed
		tangent = _glide_tangent
	else:
		normal_impact_speed = maxf(0.0, -planar_velocity.dot(planar_normal))
		tangent = planar_velocity.slide(planar_normal).normalized()
		resolved = planar_velocity.slide(planar_normal) * clampf(tuning.speed_retain_ratio, 0.0, 1.0)

	velocity = Vector3(resolved.x, 0.0, resolved.z)

	_record_collision(collision, planar_velocity, planar_normal, tangent, normal_impact_speed)

	if tuning.push_out_distance > 0.0 and not planar_normal.is_zero_approx():
		move_and_collide(planar_normal * tuning.push_out_distance)


# Scratch outputs for _compute_arcade_wall_glide_velocity, which needs to return
# three values (UE used out-params).
var _glide_normal_impact_speed := 0.0
var _glide_tangent := Vector3.ZERO


## Port of ComputeArcadeWallGlideVelocity. Throws away the physical bounce and
## builds a steerable slide along the wall instead.
func _compute_arcade_wall_glide_velocity(
	planar_velocity: Vector3, planar_normal: Vector3, delta: float
) -> Vector3:
	var projected := planar_velocity.slide(planar_normal)
	var projected_speed := projected.length()

	_glide_normal_impact_speed = maxf(0.0, -planar_velocity.dot(planar_normal))
	_glide_tangent = projected.normalized() if projected_speed > 0.0001 else Vector3.ZERO

	var hard_impact := _glide_normal_impact_speed >= tuning.min_normal_impact_speed_for_glide
	var target_speed := projected_speed
	if hard_impact:
		# A square-on hit converts its head-on speed into slide instead of stopping.
		target_speed = maxf(
			target_speed, _glide_normal_impact_speed * tuning.head_on_glide_speed_scale
		)
		target_speed = maxf(target_speed, tuning.min_wall_glide_speed)

	if _glide_tangent.is_zero_approx():
		# Dead-on hit leaves no tangent: pick the side the driver is asking for.
		var preferred := move_intent if has_move_intent else planar_forward()
		var tangent_a := Vector3.UP.cross(planar_normal).normalized()
		_glide_tangent = tangent_a if tangent_a.dot(preferred) >= (-tangent_a).dot(preferred) else -tangent_a

	var desired := _glide_tangent * target_speed

	if has_move_intent:
		var intent_along_wall := move_intent.slide(planar_normal).normalized()
		if not intent_along_wall.is_zero_approx():
			desired = desired.lerp(
				intent_along_wall * target_speed, clampf(tuning.wall_glide_input_assist, 0.0, 1.0)
			)
			_glide_tangent = desired.normalized()

	var retain := clampf(tuning.speed_retain_ratio, 0.0, 1.0)
	desired *= retain

	var interp_speed := maxf(0.0, tuning.wall_glide_velocity_interp_speed)
	var result := (
		desired
		if interp_speed <= 0.0001
		else UeMath.vinterp_to(projected, desired, delta, interp_speed)
	)
	result.y = 0.0

	# The interp can undershoot on a hard hit; keep a guaranteed minimum glide.
	var floor_speed := tuning.min_wall_glide_speed * retain
	if (
		hard_impact
		and result.length_squared() < pow(floor_speed * 0.5, 2.0)
		and not _glide_tangent.is_zero_approx()
	):
		result = _glide_tangent * floor_speed

	return result


func _record_collision(
	collision: KinematicCollision3D,
	planar_velocity: Vector3,
	planar_normal: Vector3,
	tangent: Vector3,
	normal_impact_speed: float
) -> void:
	var event := VehicleCollisionEvent.new()
	event.collider = collision.get_collider()
	event.position = collision.get_position()
	event.normal = planar_normal
	event.tangent = tangent
	event.total_speed = planar_velocity.length()
	event.normal_impact_speed = normal_impact_speed
	# Real slip, not the is_drifting flag. With grip unheld — the default and the
	# shipping feel — is_drifting is always true, so it would mark every single
	# hit as a drift hit and the drift bonus would be a constant, not a bonus.
	event.is_drifting = absf(get_lateral_speed()) >= tuning.slip_for_drift_bonus
	event.is_skill_dashing = skill_dashing
	event.target_is_vehicle = event.collider is ArcadeVehicle

	var target_velocity := _resolve_collider_velocity(event.collider)
	event.target_speed = target_velocity.length()
	event.relative_normal_speed = (
		maxf(0.0, -(planar_velocity - target_velocity).dot(planar_normal))
		if not planar_normal.is_zero_approx()
		else normal_impact_speed
	)

	last_collision = event
	last_collision_time = float(Time.get_ticks_msec()) * 0.001
	blocking_collision.emit(event)


func _resolve_collider_velocity(collider: Object) -> Vector3:
	var target_velocity := Vector3.ZERO
	if collider is ArcadeVehicle:
		target_velocity = (collider as ArcadeVehicle).velocity
	elif collider is RigidBody3D:
		target_velocity = (collider as RigidBody3D).linear_velocity
	elif collider is CharacterBody3D:
		target_velocity = (collider as CharacterBody3D).velocity
	target_velocity.y = 0.0
	return target_velocity
