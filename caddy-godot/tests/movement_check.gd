extends Node3D
## Headless verification that the ported movement reproduces the Unreal numbers.
##
##   godot --headless --path caddy-godot tests/movement_check.tscn
##
## Drives an ArcadeVehicle through scripted inputs and checks the values the UE
## tuning implies: top speed, steering rate, lateral friction retention, and the
## reverse-steering latch hysteresis.

const TICK := 1.0 / 60.0
## The wall sits far from the origin so the speed and friction checks, which run
## from (0,0,0), can never reach it. Geometry is built up front because the suite
## steps physics by hand and cannot add colliders mid-run.
const WALL_Z := -5000.0
## Same idea for the arena: far enough that no other check can drive into it.
const ARENA_CENTER := Vector3(0.0, 0.0, 8000.0)

## Pass --verbose-checks to log each check to user://check_progress.log as it
## starts. Written to a file rather than stdout because Godot's stdout is
## block-buffered when piped, so nothing appears until the process exits — which
## is useless for locating a hang.
@onready var verbose: bool = OS.get_cmdline_user_args().has("--verbose-checks")

var _progress_log: FileAccess = null

var _vehicle: ArcadeVehicle
## Stand-in opponent for the combat checks.
var _target: ArcadeVehicle
var _wall: StaticBody3D
var _arena: CircularArena
var _failures: PackedStringArray = []
var _results: PackedStringArray = []


func _ready() -> void:
	Engine.physics_ticks_per_second = 60
	_vehicle = _make_vehicle()
	add_child(_vehicle)
	_target = _make_vehicle()
	_target.name = "TargetVehicle"
	add_child(_target)
	# Parked out of the way; the combat checks move it where they need it.
	_target.global_position = Vector3(0.0, 0.35, 3000.0)
	_wall = _make_wall()
	add_child(_wall)
	_arena = CircularArena.new()
	_arena.position = ARENA_CENTER
	add_child(_arena)
	# One physics frame registers the bodies, then resume at idle time so
	# stepping _physics_process by hand does not fight the server's query flush.
	await get_tree().physics_frame
	await get_tree().process_frame
	_run()
	_report()
	get_tree().quit(1 if _failures.size() > 0 else 0)


func _make_wall() -> StaticBody3D:
	var body := StaticBody3D.new()
	body.position = Vector3(0.0, 0.35, WALL_Z)
	var shape := CollisionShape3D.new()
	var box := BoxShape3D.new()
	box.size = Vector3(400.0, 2.0, 1.0)
	shape.shape = box
	body.add_child(shape)
	return body


## Parks the car 20 m short of the wall, pointing at it.
func _approach_wall() -> void:
	_reset()
	_vehicle.global_position = Vector3(0.0, 0.35, WALL_Z + 20.0)


func _make_vehicle() -> ArcadeVehicle:
	var vehicle := ArcadeVehicle.new()
	vehicle.tuning = load("res://resources/tuning/tuning_default.tres")
	var shape := CollisionShape3D.new()
	var box := BoxShape3D.new()
	box.size = Vector3(1.12, 0.7, 1.84)
	shape.shape = box
	vehicle.add_child(shape)
	return vehicle


## Steps the vehicle for a duration with fixed inputs. Returns seconds elapsed.
func _drive(seconds: float, throttle: float, brake: float, intent: Vector3, grip := 0.0) -> void:
	var steps := int(round(seconds / TICK))
	for i in steps:
		_vehicle.set_move_intent(intent)
		_vehicle.set_throttle_input(throttle)
		_vehicle.set_brake_reverse_input(brake)
		_vehicle.set_grip_input(grip)
		_vehicle._physics_process(TICK)


func _reset() -> void:
	_vehicle.velocity = Vector3.ZERO
	_vehicle.rotation = Vector3.ZERO
	_vehicle.global_position = Vector3(0.0, 0.35, 0.0)
	_vehicle.reverse_steering_active = false
	_vehicle.set_control_lock_enabled(false)
	# A check that leaves an effect mid-flight (a knockback interrupted by death,
	# an aborted dash) would otherwise hand the next check a car that cannot drive.
	_vehicle.set_external_velocity_control_enabled(false)
	_vehicle.skill_dashing = false
	# Must be cleared, or checks that wait for the next collision see the previous
	# one still latched and skip their approach entirely.
	_vehicle.last_collision = null
	_vehicle.last_collision_time = -1.0


func _run() -> void:
	for check in [
		"_check_stick_to_world_intent",
		"_check_top_speed",
		"_check_acceleration_time",
		"_check_steering_rate",
		"_check_lateral_friction",
		"_check_reverse_steering_latch",
		"_check_control_lock",
		"_check_wall_glide",
		"_check_brake_dash",
		"_check_impact_adjudication",
		"_check_combat_reactions",
		"_check_arena",
		"_check_player_roster",
		"_check_scene_wiring",
		"_check_camera_framing",
		"_check_easing",
		"_check_feel",
	]:
		_log_progress("start %s" % check)
		call(check)
		_log_progress("done  %s" % check)


func _log_progress(message: String) -> void:
	if not verbose:
		return
	if _progress_log == null:
		_progress_log = FileAccess.open("user://check_progress.log", FileAccess.WRITE)
	if _progress_log != null:
		_progress_log.store_line(message)
		_progress_log.flush()


# ---------------------------------------------------------------------------
# Combat
# ---------------------------------------------------------------------------

## Builds the raw collision payload the movement layer would hand to the
## adjudicator, so scoring can be checked without staging a real crash.
func _make_collision(
	normal_speed: float, target_is_vehicle := true, drifting := false, dashing := false
) -> VehicleCollisionEvent:
	var collision := VehicleCollisionEvent.new()
	collision.collider = _target
	collision.normal = Vector3.BACK
	collision.total_speed = maxf(normal_speed, 10.0)
	collision.normal_impact_speed = normal_speed
	collision.relative_normal_speed = normal_speed
	collision.target_is_vehicle = target_is_vehicle
	collision.is_drifting = drifting
	collision.is_skill_dashing = dashing
	return collision


func _check_impact_adjudication() -> void:
	var adjudicator := ImpactAdjudicator.new()
	adjudicator.vehicle = _vehicle
	adjudicator.tuning = load("res://resources/tuning/impact_default.tres")

	# Tier boundaries. Score equals effective normal speed at scale 1.
	_expect(
		adjudicator.adjudicate(_make_collision(2.0)) == null,
		"a 2.0 m/s tap scores below the light threshold and is dropped"
	)
	var light := adjudicator.adjudicate(_make_collision(3.0))
	_expect(
		light != null and light.tier == ImpactTier.Value.LIGHT,
		"3.0 m/s scores light"
	)
	adjudicator._cooldown_remaining = 0.0
	var medium := adjudicator.adjudicate(_make_collision(7.0))
	_expect(
		medium != null and medium.tier == ImpactTier.Value.MEDIUM,
		"7.0 m/s scores medium"
	)
	var heavy := adjudicator.adjudicate(_make_collision(12.0))
	_expect(
		heavy != null and heavy.tier == ImpactTier.Value.HEAVY,
		"12.0 m/s scores heavy"
	)

	# Damage: (bias + speed * 1.2) * tier multiplier.
	if heavy != null:
		_record("heavy impact damage at 12 m/s", heavy.damage, "hp", 12.0 * 1.2 * 1.55, 0.001)
	if light != null:
		_record("light impact damage at 3 m/s", light.damage, "hp", 3.0 * 1.2 * 0.65, 0.001)

	# Multipliers stack onto the score, which can promote a tier.
	var drift_hit := adjudicator.adjudicate(_make_collision(6.0, true, true, false))
	if drift_hit != null:
		_record("drift impact score at 6 m/s", drift_hit.impact_score, "", 6.0 * 1.1, 0.001)
		_expect(
			drift_hit.tier == ImpactTier.Value.MEDIUM,
			"the drift multiplier promotes a 6.0 m/s hit from light to medium"
		)
	var dash_hit := adjudicator.adjudicate(_make_collision(6.5, true, false, true))
	if dash_hit != null:
		_record("dash impact score at 6.5 m/s", dash_hit.impact_score, "", 6.5 * 1.6, 0.001)
		_expect(
			dash_hit.tier == ImpactTier.Value.HEAVY,
			"the dash multiplier promotes a 6.5 m/s hit to heavy"
		)

	# Gates.
	_expect(
		adjudicator.adjudicate(_make_collision(12.0, false)) == null,
		"hitting a wall scores nothing when a vehicle target is required"
	)
	var slow := _make_collision(12.0)
	slow.total_speed = 1.0
	_expect(
		adjudicator.adjudicate(slow) == null,
		"a hit below min_speed_for_event is dropped"
	)

	# Stagger gating follows the attacker's tuning, not the target's.
	_expect(
		light != null and not light.apply_stagger, "light impacts do not stagger by default"
	)
	_expect(medium != null and medium.apply_stagger, "medium impacts stagger")
	_expect(heavy != null and heavy.apply_stagger, "heavy impacts stagger")
	_expect(heavy != null and heavy.apply_knockback, "heavy impacts knock back")

	# The cooldown gate only closes on a hit that actually goes through.
	adjudicator._cooldown_remaining = 0.0
	adjudicator._on_blocking_collision(_make_collision(12.0))
	_expect(
		adjudicator.adjudicate(_make_collision(12.0)) == null,
		"the event cooldown suppresses a second hit"
	)

	adjudicator.free()


func _check_combat_reactions() -> void:
	var combat := VehicleCombat.new()
	combat.vehicle = _vehicle
	combat.tuning = load("res://resources/tuning/combat_default.tres")
	_vehicle.add_child(combat)

	_reset()
	_vehicle.global_position = Vector3.ZERO
	_target.global_position = Vector3(0.0, 0.35, -6.0)

	var impact := ImpactEvent.new()
	impact.attacker = _target
	impact.target = _vehicle
	impact.tier = ImpactTier.Value.HEAVY
	impact.damage = 20.0
	impact.normal = Vector3.BACK
	impact.apply_knockback = true
	impact.apply_stagger = true

	var start_health := combat.health
	combat.receive_impact(impact)

	_record("health after a 20 hp hit", combat.health, "hp", start_health - 20.0, 0.001)
	_expect(combat.is_knocked_back(), "a heavy impact starts knockback")
	_expect(combat.is_staggered(), "a heavy impact starts stagger")
	_expect(_vehicle.control_locked, "stagger locks out input")
	_expect(
		_vehicle.external_velocity_control, "knockback takes velocity control"
	)

	# Shoved directly away from the attacker, which is 6 m in front (-Z).
	var ticks := 0
	combat._physics_process(TICK)
	ticks += 1
	_expect(
		_vehicle.velocity.z > 0.0 and absf(_vehicle.velocity.x) < 0.001,
		"knockback shoves straight away from the attacker (%v)" % _vehicle.velocity
	)
	_record("heavy knockback speed", _vehicle.get_planar_speed(), "m/s", 13.2, 0.001)

	# Hold for the whole window, then hand back with the carry ratio.
	while combat.is_knocked_back() and ticks < 200:
		combat._physics_process(TICK)
		ticks += 1
	_record("knockback window", float(ticks) * TICK, "s", 0.22, 0.1)
	_expect(
		not _vehicle.external_velocity_control, "knockback hands velocity control back"
	)
	_record("knockback carry speed", _vehicle.get_planar_speed(), "m/s", 13.2 * 0.2, 0.001)

	# Stagger runs longer than knockback and keeps input locked until it ends.
	_expect(combat.is_staggered(), "stagger outlasts the knockback")
	while combat.is_staggered() and ticks < 400:
		combat._physics_process(TICK)
		ticks += 1
	_record("heavy stagger input lock", float(ticks) * TICK, "s", 0.8, 0.05)
	_expect(not _vehicle.control_locked, "input unlocks when the stagger ends")

	# Knockback must cancel an active dash rather than fight it for control.
	var skill := _make_skill()
	combat.skill = skill
	_reset()
	_drive(3.0, 1.0, 0.0, Vector3.FORWARD)
	_step_skill(skill, 0.4, true, Vector3.FORWARD)
	_expect(skill.is_active(), "skill is active before the interrupting hit")
	combat.receive_impact(impact)
	_expect(
		not skill.is_active(), "knockback cancels an in-progress dash"
	)
	_expect(
		_vehicle.external_velocity_control,
		"knockback still owns velocity control after cancelling the skill"
	)

	# Damage floors at zero and fires destroyed exactly once.
	var destroyed_count := [0]
	combat.destroyed.connect(func() -> void: destroyed_count[0] += 1)
	combat.apply_damage(10000.0)
	_record("health floors at zero", combat.health, "hp", 0.0, 0.001)
	combat.apply_damage(10.0)
	_expect(
		destroyed_count[0] == 1,
		"destroyed fires once and a dead car takes no more damage (%d)" % destroyed_count[0]
	)

	skill.queue_free()
	combat.queue_free()


# ---------------------------------------------------------------------------
# Collision response
# ---------------------------------------------------------------------------

func _check_wall_glide() -> void:
	# Head-on into a flat wall. The arcade response must convert the impact into
	# a slide rather than stopping the car, and pick the side move intent asks for.
	_approach_wall()
	var events: Array[VehicleCollisionEvent] = []
	_vehicle.blocking_collision.connect(func(e: VehicleCollisionEvent) -> void: events.append(e))

	var guard := 0
	while _vehicle.last_collision == null and guard < 600:
		_drive(TICK, 1.0, 0.0, Vector3.FORWARD)
		guard += 1
	_expect(_vehicle.last_collision != null, "head-on impact produces a collision event")

	var hit: VehicleCollisionEvent = _vehicle.last_collision
	if hit != null:
		_expect(
			hit.collider == _wall, "collision event reports the wall as collider"
		)
		_expect(
			hit.normal_impact_speed > _vehicle.tuning.min_normal_impact_speed_for_glide,
			"head-on impact registers a hard normal impact (%.2f)" % hit.normal_impact_speed
		)
		_expect(
			absf(hit.normal.y) < 0.001,
			"collision normal is flattened to the ground plane (y %.4f)" % hit.normal.y
		)

	# One tick later the car must still be moving, and moving sideways.
	_drive(TICK, 1.0, 0.0, Vector3.FORWARD)
	var glide_speed := _vehicle.get_planar_speed()
	_expect(
		glide_speed >= _vehicle.tuning.min_wall_glide_speed * _vehicle.tuning.speed_retain_ratio * 0.5,
		"head-on hit keeps a minimum glide instead of stopping dead (%.2f m/s)" % glide_speed
	)
	_expect(
		absf(_vehicle.velocity.x) > absf(_vehicle.velocity.z),
		"post-impact travel is along the wall, not into it (%v)" % _vehicle.velocity
	)

	# Move intent must be able to choose which way it glides off a dead-on hit.
	var right_x := _glide_direction_for_intent(Vector3.RIGHT)
	var left_x := _glide_direction_for_intent(Vector3.LEFT)
	_expect(
		right_x > 0.0 and left_x < 0.0,
		"wall glide input assist steers the slide (right %.2f, left %.2f)" % [right_x, left_x]
	)
	_expect(
		is_equal_approx(absf(right_x), absf(left_x)),
		"the glide is symmetric either way (%.3f vs %.3f)" % [absf(right_x), absf(left_x)]
	)

	_expect(events.size() >= 1, "blocking_collision fired %d time(s)" % events.size())


## A dead-on hit leaves no tangent to slide along, so the response picks a side
## from move intent. Exercised directly rather than through a staged crash: the
## side intent has to be held on the exact contact tick, and a car steering that
## way would have turned off the wall before reaching it. With forward intent the
## two candidate tangents tie exactly, which is what made the staged version
## always resolve to +X regardless of the side asked for.
func _glide_direction_for_intent(intent: Vector3) -> float:
	_reset()
	_vehicle.set_move_intent(intent)
	var head_on_velocity := Vector3(0.0, 0.0, -_vehicle.tuning.max_forward_speed)
	var wall_normal := Vector3(0.0, 0.0, 1.0)
	return _vehicle._compute_arcade_wall_glide_velocity(head_on_velocity, wall_normal, TICK).x


# ---------------------------------------------------------------------------
# Brake-dash skill
# ---------------------------------------------------------------------------

func _make_skill() -> BrakeDashSkill:
	var skill := BrakeDashSkill.new()
	skill.vehicle = _vehicle
	skill.tuning = load("res://resources/tuning/skill_default.tres")
	_vehicle.add_child(skill)
	return skill


## Steps skill then vehicle, matching the physics priority ordering in-game.
## Throttle defaults to 0 so post-dash measurements are not contaminated by the
## car accelerating again the moment velocity control is handed back.
func _step_skill(
	skill: BrakeDashSkill, seconds: float, held: bool, intent := Vector3.ZERO, throttle := 0.0
) -> void:
	for i in int(round(seconds / TICK)):
		_step_skill_once(skill, held, intent, throttle)


func _step_skill_once(
	skill: BrakeDashSkill, held: bool, intent := Vector3.ZERO, throttle := 0.0
) -> void:
	skill.set_skill_input_pressed(held)
	_vehicle.set_move_intent(intent)
	_vehicle.set_throttle_input(throttle)
	_vehicle.set_brake_reverse_input(0.0)
	skill._physics_process(TICK)
	_vehicle._physics_process(TICK)


## Steps until the skill leaves the given state, so values can be read exactly at
## the transition rather than several ticks later.
func _step_skill_until_leaves(
	skill: BrakeDashSkill, from_state: BrakeDashSkill.State, held: bool, intent := Vector3.ZERO
) -> void:
	var guard := 0
	while skill.state == from_state and guard < 600:
		_step_skill_once(skill, held, intent)
		guard += 1


func _check_brake_dash() -> void:
	var skill := _make_skill()

	# Full-charge dash: brake 0.34s, charge 1.0s, then auto-fire at max.
	_reset()
	_drive(3.0, 1.0, 0.0, Vector3.FORWARD)
	var entry_speed := _vehicle.get_planar_speed()

	_step_skill(skill, 0.05, true, Vector3.FORWARD)
	_expect(skill.state == BrakeDashSkill.State.BRAKING, "hold enters the brake phase")
	_expect(
		_vehicle.external_velocity_control,
		"skill takes velocity control while active"
	)
	_expect(
		_vehicle.get_planar_speed() < entry_speed,
		"brake phase sheds speed (%.2f -> %.2f)" % [entry_speed, _vehicle.get_planar_speed()]
	)

	_step_skill(skill, 0.35, true, Vector3.FORWARD)
	_expect(skill.state == BrakeDashSkill.State.CHARGING, "brake phase hands off to charging")
	_expect(
		_vehicle.velocity.is_zero_approx(),
		"charging pins the car at a standstill (%.3f m/s)" % _vehicle.get_planar_speed()
	)

	# Charging must be able to pivot on the spot, which normal steering cannot.
	_step_skill(skill, 0.2, true, Vector3.RIGHT)
	_expect(
		absf(_vehicle.rotation.y) > 0.1,
		"charging rotates the car at zero velocity (yaw %.3f)" % _vehicle.rotation.y
	)

	_step_skill(skill, 0.85, true, Vector3.RIGHT)
	_expect(skill.state == BrakeDashSkill.State.DASHING, "max charge auto-fires the dash")
	_record("full-charge dash peak speed", skill.active_dash_peak_speed, "m/s", 42.0, 0.01)
	_record("full-charge dash duration", skill.active_dash_duration, "s", 0.42, 0.01)
	_expect(
		_vehicle.skill_dashing, "vehicle is tagged as dashing for collision events"
	)

	# Boxed: GDScript lambdas capture locals by value, so a plain float would
	# never see the signal's write.
	var carry_box := [0.0]
	skill.dash_finished.connect(func(speed: float) -> void: carry_box[0] = speed)
	_step_skill_until_leaves(skill, BrakeDashSkill.State.DASHING, false, Vector3.RIGHT)
	var carry_speed: float = carry_box[0]
	_expect(skill.state == BrakeDashSkill.State.READY, "dash completes back to ready")
	_expect(
		not _vehicle.external_velocity_control,
		"velocity control is handed back after the dash"
	)
	_record("post-dash carry speed", carry_speed, "m/s", 42.0 * 0.3, 0.01)
	# The vehicle's own velocity update runs the same tick control is handed back,
	# so one tick of coast deceleration and drag lands before anything can read it.
	var settled := carry_speed * (1.0 - _vehicle.tuning.linear_drag * TICK)
	settled -= _vehicle.tuning.coast_deceleration * TICK * (1.0 - _vehicle.tuning.linear_drag * TICK)
	_record("carry speed after one coast tick", _vehicle.get_planar_speed(), "m/s", settled, 0.01)
	_record("cooldown after dash", skill.cooldown_remaining, "s", 2.0, 0.01)

	# Cooldown must actually gate a retrigger.
	_step_skill(skill, 0.1, true, Vector3.FORWARD)
	_expect(
		skill.state == BrakeDashSkill.State.READY,
		"cooldown blocks retrigger (%.2f s left)" % skill.cooldown_remaining
	)

	# Minimum charge: release immediately after braking ends.
	skill.cooldown_remaining = 0.0
	_reset()
	_drive(3.0, 1.0, 0.0, Vector3.FORWARD)
	_step_skill(skill, 0.4, true, Vector3.FORWARD)
	_expect(skill.state == BrakeDashSkill.State.CHARGING, "second activation reaches charging")
	_step_skill(skill, TICK, false, Vector3.FORWARD)
	_expect(skill.state == BrakeDashSkill.State.DASHING, "release fires the dash")
	_record("min-charge dash peak speed", skill.active_dash_peak_speed, "m/s", 26.0, 0.05)
	_record("min-charge dash duration", skill.active_dash_duration, "s", 0.22, 0.05)

	skill.abort_to_ready()
	_expect(
		not _vehicle.external_velocity_control,
		"abort releases velocity control"
	)
	skill.queue_free()


## With a world-fixed camera yaw of 0 (how the UE boom was configured), stick up
## must point at -Z and stick right at +X. A sign flip here steers the car the
## wrong way without failing any of the speed or friction checks.
func _check_stick_to_world_intent() -> void:
	_reset()
	_vehicle.intent_yaw_source = null

	_vehicle.set_move_intent_from_stick(Vector2(0.0, 1.0))
	_expect(
		_vehicle.move_intent.is_equal_approx(Vector3.FORWARD),
		"stick up -> world forward (got %v)" % _vehicle.move_intent
	)
	_vehicle.set_move_intent_from_stick(Vector2(1.0, 0.0))
	_expect(
		_vehicle.move_intent.is_equal_approx(Vector3.RIGHT),
		"stick right -> world right (got %v)" % _vehicle.move_intent
	)
	_vehicle.set_move_intent_from_stick(Vector2(0.05, 0.0))
	_expect(not _vehicle.has_move_intent, "sub-dead-zone stick clears intent")


func _check_top_speed() -> void:
	_reset()
	_drive(6.0, 1.0, 0.0, Vector3.FORWARD)
	var speed := _vehicle.get_planar_speed()
	_record("top speed (full throttle, 6s)", speed, "m/s", 22.0, 0.05)
	_expect(
		_vehicle.get_forward_speed() <= _vehicle.tuning.max_forward_speed + 0.01,
		"forward speed must stay clamped to max_forward_speed"
	)


func _check_acceleration_time() -> void:
	_reset()
	var elapsed := 0.0
	while _vehicle.get_forward_speed() < 20.0 and elapsed < 5.0:
		_drive(TICK, 1.0, 0.0, Vector3.FORWARD)
		elapsed += TICK
	# Closed form for v <- (v + 62*dt) * (1 - 0.3*dt) at 60 Hz reaches 20 m/s on
	# tick 21, so anything other than 0.350s means the gas model drifted.
	_record("0 -> 20 m/s", elapsed, "s", 21.0 * TICK, 0.02)


func _check_steering_rate() -> void:
	# Drifting steering is 540 * 1.35 = 729 deg/s.
	_reset()
	_drive(2.0, 1.0, 0.0, Vector3.FORWARD)
	var start_yaw := _vehicle.rotation.y
	_drive(0.1, 1.0, 0.0, Vector3.LEFT)
	var rate := rad_to_deg(absf(angle_difference(start_yaw, _vehicle.rotation.y))) / 0.1
	_record("drift steering rate", rate, "deg/s", 729.0, 0.02)

	_reset()
	_drive(2.0, 1.0, 0.0, Vector3.FORWARD, 1.0)
	start_yaw = _vehicle.rotation.y
	_drive(0.1, 1.0, 0.0, Vector3.LEFT, 1.0)
	rate = rad_to_deg(absf(angle_difference(start_yaw, _vehicle.rotation.y))) / 0.1
	_record("grip steering rate", rate, "deg/s", 540.0, 0.02)

	# Below min_speed_for_steering the body must not rotate at all.
	_reset()
	_drive(0.5, 0.0, 0.0, Vector3.LEFT)
	_expect(
		is_zero_approx(_vehicle.rotation.y),
		"must not steer below min_speed_for_steering (got yaw %.4f)" % _vehicle.rotation.y
	)


func _check_lateral_friction() -> void:
	# Spin the car 90 degrees off its velocity, then watch the slip decay.
	# The window is 0.3s deliberately: by ~0.7s grip has pulled total speed under
	# stop_speed_threshold and _perform_movement snaps to rest, which would
	# measure the stop threshold instead of the friction curve.
	# Retention is (1 - friction/60)^18: 0.9583^18 and 0.875^18.
	var drift_retained := _measure_slip_retention(0.0)
	var grip_retained := _measure_slip_retention(1.0)
	_record("slip retained after 0.3s (drift)", drift_retained * 100.0, "%", 46.48, 0.03)
	_record("slip retained after 0.3s (grip)", grip_retained * 100.0, "%", 9.04, 0.03)
	_expect(
		drift_retained > grip_retained * 4.0,
		"drift must hold slip far longer than grip (%.4f vs %.4f)" % [drift_retained, grip_retained]
	)

	# And grip must fully arrest the slide within a second.
	_reset()
	_drive(3.0, 1.0, 0.0, Vector3.FORWARD, 1.0)
	_vehicle.rotation.y = PI * 0.5
	_drive(1.0, 0.0, 0.0, Vector3.ZERO, 1.0)
	_expect(
		_vehicle.velocity.is_zero_approx(),
		"grip must bring a pure slide to rest within 1s (left %.4f m/s)"
		% _vehicle.get_planar_speed()
	)


func _measure_slip_retention(grip: float) -> float:
	_reset()
	_drive(3.0, 1.0, 0.0, Vector3.FORWARD, grip)
	# Rotate the body without touching velocity: pure lateral slip, no input.
	_vehicle.rotation.y = PI * 0.5
	var initial := absf(_vehicle.get_lateral_speed())
	_drive(18.0 * TICK, 0.0, 0.0, Vector3.ZERO, grip)
	return absf(_vehicle.get_lateral_speed()) / maxf(0.0001, initial)


func _check_reverse_steering_latch() -> void:
	_reset()
	_expect(not _vehicle.reverse_steering_active, "latch starts off")

	# Braking from rest accelerates backwards at 36 m/s^2, so a single tick is
	# all the room there is below the 1.2 m/s enter speed.
	_drive(TICK, 0.0, 1.0, Vector3.FORWARD)
	_expect(
		-_vehicle.get_forward_speed() < _vehicle.tuning.reverse_steering_enter_speed,
		"one tick of reverse stays under enter speed (rev %.2f)" % -_vehicle.get_forward_speed()
	)
	_expect(
		not _vehicle.reverse_steering_active,
		"latch must stay off below enter speed (rev %.2f)" % -_vehicle.get_forward_speed()
	)
	_drive(1.0, 0.0, 1.0, Vector3.FORWARD)
	_expect(
		_vehicle.reverse_steering_active,
		"latch must arm once reversing past enter speed (rev %.2f)" % -_vehicle.get_forward_speed()
	)
	_record("reverse top speed", absf(_vehicle.get_forward_speed()), "m/s", 9.2, 0.05)

	# Coasting back toward the exit speed (0.7) releases it.
	_drive(0.5, 0.0, 0.0, Vector3.FORWARD)
	_expect(
		not _vehicle.reverse_steering_active,
		"latch must release below exit speed (rev %.2f)" % -_vehicle.get_forward_speed()
	)


func _check_control_lock() -> void:
	_reset()
	_drive(2.0, 1.0, 0.0, Vector3.FORWARD)
	_vehicle.set_control_lock_enabled(true)
	_drive(0.5, 1.0, 1.0, Vector3.LEFT, 1.0)
	_expect(
		is_zero_approx(_vehicle.throttle_input) and not _vehicle.has_move_intent,
		"control lock must swallow all input"
	)
	_expect(
		_vehicle.is_drifting,
		"control lock must fall back to the drifty resting state"
	)


# ---------------------------------------------------------------------------
# Arena and roster
# ---------------------------------------------------------------------------

func _check_arena() -> void:
	var segments := _arena.wall_segments
	var wall := _arena.get_node_or_null("Wall")
	_expect(wall != null, "arena builds a wall body")
	if wall != null:
		# One CollisionShape3D plus one MeshInstance3D per segment.
		_record("wall child nodes", float(wall.get_child_count()), "", float(segments * 2), 0.001)

	# Spawns: evenly spaced on the inner ring, each facing the middle.
	var count := 4
	var centre := _arena.global_position
	for i in count:
		var spawn := _arena.get_spawn_transform(i, count)
		var offset := spawn.origin - centre
		offset.y = 0.0
		var expected_radius: float = _arena.radius * _arena.spawn_ring_fraction
		_expect(
			absf(offset.length() - expected_radius) < 0.01,
			"spawn %d sits on the inner ring (%.2f vs %.2f)" % [i, offset.length(), expected_radius]
		)
		# -Z is forward in Godot, so the nose is the negated third basis column.
		var facing := -spawn.basis.z
		_expect(
			facing.dot(-offset.normalized()) > 0.999,
			"spawn %d faces the centre (dot %.4f)" % [i, facing.dot(-offset.normalized())]
		)

	var first := _arena.get_spawn_transform(0, count).origin
	var second := _arena.get_spawn_transform(1, count).origin
	var separation := (first - centre).angle_to(second - centre)
	_record("spawn separation for 4 players", rad_to_deg(separation), "deg", 90.0, 0.01)

	# The ring wall must actually contain the car. Drive flat out at it.
	_reset()
	_vehicle.global_position = centre + Vector3(0.0, 0.35, 0.0)
	_drive(6.0, 1.0, 0.0, Vector3.RIGHT)
	var escaped := _vehicle.global_position - centre
	escaped.y = 0.0
	_expect(
		escaped.length() < _arena.radius,
		"the ring wall contains the car (%.2f m from centre, radius %.1f)"
		% [escaped.length(), _arena.radius]
	)
	_expect(
		_vehicle.last_collision != null,
		"driving into the ring wall registers a collision"
	)


func _check_player_roster() -> void:
	PlayerRoster.clear()
	_expect(PlayerRoster.count() == 0, "roster starts empty")

	var keyboard := InputDevice.keyboard()
	var pad_a := InputDevice.gamepad(0)
	var pad_b := InputDevice.gamepad(1)

	var slot_one := PlayerRoster.join(keyboard)
	_expect(slot_one != null and slot_one.index == 0, "first device takes seat P1")
	_expect(
		PlayerRoster.join(keyboard) == null, "the same device cannot take a second seat"
	)

	var slot_two := PlayerRoster.join(pad_a)
	_expect(slot_two != null and slot_two.index == 1, "second device takes seat P2")
	_expect(PlayerRoster.count() == 2, "roster holds two players")
	_expect(
		PlayerRoster.has_device(pad_a) and not PlayerRoster.has_device(pad_b),
		"roster reports device membership correctly"
	)

	# A freed seat is reused rather than leaving a gap.
	_expect(PlayerRoster.leave(keyboard), "a joined device can leave")
	_expect(PlayerRoster.count() == 1, "leaving frees the seat")
	var rejoin := PlayerRoster.join(pad_b)
	_expect(
		rejoin != null and rejoin.index == 0, "the lowest free seat is reused, not appended"
	)

	# Capacity.
	PlayerRoster.clear()
	for i in 5:
		PlayerRoster.join(InputDevice.gamepad(i))
	_expect(
		PlayerRoster.count() == PlayerRoster.MAX_PLAYERS,
		"roster caps at %d players (got %d)" % [PlayerRoster.MAX_PLAYERS, PlayerRoster.count()]
	)

	# Distinct colours, so players can tell their car apart.
	var colors := {}
	for slot in PlayerRoster.players:
		colors[slot.color()] = true
	_expect(colors.size() == PlayerRoster.count(), "each seat gets its own colour")

	PlayerRoster.clear()
	PlayerRoster.ensure_at_least_one()
	_expect(
		PlayerRoster.count() == 1 and PlayerRoster.players[0].device.is_keyboard(),
		"an empty roster falls back to one keyboard player"
	)
	PlayerRoster.clear()


# ---------------------------------------------------------------------------
# Scene wiring and camera
# ---------------------------------------------------------------------------

## Guards the node_paths trap: an @export node reference written into a .tscn as
## a bare NodePath resolves to null unless the node header declares it in
## node_paths. It fails silently, and every script here has a get_parent()
## fallback, so the only symptom was features quietly doing nothing — the dash
## never fired in game because Driver.skill was null.
func _check_scene_wiring() -> void:
	var scene := load("res://scenes/vehicle.tscn") as PackedScene
	var car := scene.instantiate() as ArcadeVehicle
	add_child(car)
	car.global_position = Vector3(0.0, 0.35, -3000.0)

	var driver: PlayerVehicleDriver = null
	var skill: BrakeDashSkill = null
	var adjudicator: ImpactAdjudicator = null
	for child in car.get_children():
		if child is PlayerVehicleDriver:
			driver = child
		elif child is BrakeDashSkill:
			skill = child
		elif child is ImpactAdjudicator:
			adjudicator = child
	var combat := VehicleCombat.find_for(car)

	_expect(driver != null, "vehicle scene has a driver")
	_expect(skill != null, "vehicle scene has a brake-dash skill")
	_expect(combat != null, "vehicle scene has a combat node")
	_expect(adjudicator != null, "vehicle scene has an impact adjudicator")

	_expect(
		driver != null and driver.skill == skill,
		"driver.skill resolves - without it the dash button does nothing"
	)
	_expect(driver != null and driver.vehicle == car, "driver.vehicle resolves")
	_expect(skill != null and skill.vehicle == car, "skill.vehicle resolves")
	_expect(
		combat != null and combat.skill == skill,
		"combat.skill resolves - without it knockback cannot cancel a dash"
	)
	_expect(combat != null and combat.vehicle == car, "combat.vehicle resolves")
	_expect(
		adjudicator != null and adjudicator.vehicle == car, "adjudicator.vehicle resolves"
	)
	_expect(skill != null and skill.tuning != null, "skill tuning resource is assigned")

	# End to end: hold the device's skill button and confirm the car reacts.
	if driver != null and skill != null:
		driver.device = null
		_expect(
			not skill.is_active(), "skill starts inactive"
		)
		for i in 30:
			skill.set_skill_input_pressed(true)
			skill._physics_process(TICK)
			car._physics_process(TICK)
		_expect(
			skill.is_active() and car.external_velocity_control,
			"holding the skill button drives the car into the dash sequence"
		)
		skill.abort_to_ready()

	car.queue_free()


## The one that actually matters: does the shipping match scene frame its own
## arena? Read from the scene's own values so retuning either one is caught.
## Instantiated but never added to the tree - it must not build arena geometry
## on top of the cars the other checks are using.
func _check_match_scene_framing() -> void:
	var scene := load("res://scenes/arena_match.tscn") as PackedScene
	var root := scene.instantiate()

	var arena := root.get_node("Arena") as CircularArena
	var rig := root.get_node("CameraRig") as VehicleCameraRig
	if arena == null or rig == null:
		_expect(false, "match scene exposes an Arena and a CameraRig")
		root.free()
		return

	_expect(rig.center_bias >= 0.999, "match camera is fully anchored to the arena")
	_expect(
		rig.base_pitch_deg <= -80.0,
		"match camera is near top-down (%.0f deg)" % rig.base_pitch_deg
	)
	_expect(rig.fit_ground_radius > 0.0, "match camera uses fitted framing")

	var height := rig._fitted_arm_length() * sin(deg_to_rad(absf(rig.base_pitch_deg)))
	var half_view := height * tan(deg_to_rad(rig.base_fov * 0.5))
	_expect(
		half_view >= arena.radius,
		"the whole arena fits in frame (%.1f m view vs %.1f m arena)"
		% [half_view, arena.radius]
	)
	_record("match view half-height", half_view, "m", arena.radius * 1.15, 0.1)

	root.free()


func _check_camera_framing() -> void:
	var rig := VehicleCameraRig.new()
	var camera := Camera3D.new()
	camera.name = "Camera3D"
	rig.add_child(camera)
	rig.base_pitch_deg = -85.0
	rig.base_fov = 90.0
	rig.fit_ground_radius = 30.0
	rig.center_anchor = _arena
	rig.center_bias = 1.0
	add_child(rig)

	# Arm length must put the requested ground radius inside the vertical FOV.
	var arm := rig._fitted_arm_length()
	var height := arm * sin(deg_to_rad(85.0))
	var half_view := height * tan(deg_to_rad(45.0))
	_record("fitted camera arm length", arm, "m", 30.0 / sin(deg_to_rad(85.0)), 0.01)
	_expect(
		half_view >= rig.fit_ground_radius - 0.01,
		"the fitted arm covers the requested ground radius (%.1f m vs %.1f m)"
		% [half_view, rig.fit_ground_radius]
	)
	_check_match_scene_framing()

	# Fully anchored: the shot holds the arena centre no matter where cars are.
	_reset()
	_vehicle.global_position = _arena.global_position + Vector3(20.0, 0.35, 0.0)
	rig.set_targets([_vehicle] as Array[ArcadeVehicle])
	var focus := rig._focus_point()
	_expect(
		focus.distance_to(_arena.global_position) < 0.01,
		"center_bias 1 locks focus to the arena (%.2f m off)"
		% focus.distance_to(_arena.global_position)
	)

	# And with the anchor off it goes back to following the car.
	rig.center_bias = 0.0
	focus = rig._focus_point()
	_expect(
		focus.distance_to(_vehicle.global_position) < 0.01,
		"center_bias 0 follows the car again"
	)

	rig.queue_free()


# ---------------------------------------------------------------------------
# Feel
# ---------------------------------------------------------------------------

## Every easing curve must hit its endpoints and, critically, must not be linear
## anywhere - a linear scale change is exactly what these exist to avoid.
func _check_easing() -> void:
	var curves := {
		"out_cubic": Callable(Easing, "out_cubic"),
		"in_out_cubic": Callable(Easing, "in_out_cubic"),
		"out_back": Callable(Easing, "out_back"),
		"out_elastic": Callable(Easing, "out_elastic"),
	}

	for name in curves:
		var f: Callable = curves[name]
		_expect(
			absf(float(f.call(0.0))) < 0.001 and absf(float(f.call(1.0)) - 1.0) < 0.001,
			"%s runs 0 to 1" % name
		)
		# Compare against the straight line between the endpoints. A linear curve
		# would sit on it the whole way; an eased one departs from it.
		var max_deviation := 0.0
		for i in range(1, 20):
			var t := float(i) / 20.0
			max_deviation = maxf(max_deviation, absf(float(f.call(t)) - t))
		_expect(max_deviation > 0.05, "%s is not linear (max deviation %.3f)" % [name, max_deviation])

	_expect(
		Easing.out_back(0.62) > 1.0, "out_back overshoots past its target for the pop"
	)

	# Pulse envelopes must start and end at rest, and peak in between.
	for pulse_name in ["pulse", "pulse_back"]:
		var f := Callable(Easing, pulse_name)
		_expect(
			absf(float(f.call(0.0))) < 0.001 and absf(float(f.call(1.0))) < 0.001,
			"%s starts and ends at rest" % pulse_name
		)
		var peak := 0.0
		for i in range(1, 100):
			peak = maxf(peak, float(f.call(float(i) / 100.0)))
		_expect(peak >= 0.99, "%s reaches full strength (%.3f)" % [pulse_name, peak])
	_expect(
		Easing.pulse_back(0.12) > 1.0, "pulse_back overshoots on the attack"
	)


func _check_feel() -> void:
	var scene := load("res://scenes/vehicle.tscn") as PackedScene
	var car := scene.instantiate() as ArcadeVehicle
	add_child(car)
	car.global_position = Vector3(0.0, 0.35, -4000.0)

	var visual := car.get_node_or_null("Visual") as Node3D
	var feel: VehicleFeel = null
	for child in car.get_children():
		if child is VehicleFeel:
			feel = child
	_expect(visual != null, "vehicle scene has a Visual root for the meshes")
	_expect(feel != null, "vehicle scene has a feel node")
	_expect(
		feel != null and feel.visual_root == visual,
		"feel.visual_root resolves to the Visual node"
	)
	if feel == null or visual == null:
		car.queue_free()
		return

	# Isolate the one-shot pulses. Engine idle vibration is continuous by design,
	# so with it on the mesh never sits exactly at rest and "settles" is
	# unmeasurable. Duplicated because the .tres is shared between all cars.
	feel.tuning = feel.tuning.duplicate()
	feel.tuning.enable_engine_vibration = false

	# The whole safety property of this layer: it deforms the mesh, never the body.
	var body_transform := car.global_transform
	var body_scale := car.scale
	feel.play_impact(12.0, Vector3.BACK)
	for i in 6:
		feel._process(TICK)
	_expect(
		car.global_transform.is_equal_approx(body_transform) and car.scale.is_equal_approx(body_scale),
		"feel never moves or scales the collision body"
	)
	_expect(
		not visual.scale.is_equal_approx(Vector3.ONE),
		"an impact deforms the visual mesh (scale %v)" % visual.scale
	)

	# The pulse has to come back to rest on its own.
	var settle := int(ceil(feel.tuning.impact_pulse_duration / TICK)) + 60
	for i in settle:
		feel._process(TICK)
	_expect(
		visual.scale.is_equal_approx(Vector3.ONE)
		and visual.position.is_equal_approx(Vector3.ZERO),
		"the impact pulse settles back to rest (scale %v, pos %v)"
		% [visual.scale, visual.position]
	)

	# A harder hit landing mid-pulse restarts it; a weaker one must not stomp it.
	feel.play_impact(12.0, Vector3.BACK)
	feel._process(TICK)
	var strong := feel._impact_strength
	feel.play_impact(2.0, Vector3.BACK)
	_expect(
		is_equal_approx(feel._impact_strength, strong),
		"a weaker hit does not interrupt a stronger pulse"
	)
	feel.play_impact(12.0, Vector3.BACK)
	_expect(is_zero_approx(feel._impact_elapsed), "an equal or harder hit restarts the pulse")

	# Impact direction is stored in local space so the squash follows the body.
	car.rotation.y = PI * 0.5
	feel.play_impact(12.0, Vector3.BACK)
	_expect(
		absf(feel._impact_local_dir.x) > 0.9,
		"a hit from behind a turned car squashes across its local axis (%v)"
		% feel._impact_local_dir
	)

	# Dash pop scales with charge.
	feel._on_dash_started(Vector3.FORWARD, 1.0, 42.0)
	var full_charge_strength := feel._dash_strength
	feel._on_dash_started(Vector3.FORWARD, 0.0, 26.0)
	_expect(
		feel._dash_strength < full_charge_strength,
		"a short charge pops less than a full one (%.2f vs %.2f)"
		% [feel._dash_strength, full_charge_strength]
	)

	# And the dash stretch runs along the length axis, not uniformly.
	feel._on_dash_started(Vector3.FORWARD, 1.0, 42.0)
	feel._process(TICK * 3.0)
	var dash_scale := feel._dash_scale(0.0)
	_expect(
		dash_scale.z > 0.0 and dash_scale.x < 0.0,
		"the dash stretches length and squashes width (%v)" % dash_scale
	)

	# Engine idle: a continuous wobble that stays inside its configured ceiling.
	feel.tuning.enable_engine_vibration = true
	feel.tuning.enable_acceleration_deform = false
	feel._dash_elapsed = -1.0
	feel._impact_elapsed = -1.0
	var lowest := 2.0
	var highest := 0.0
	for i in 240:
		feel._process(TICK)
		lowest = minf(lowest, visual.scale.x)
		highest = maxf(highest, visual.scale.x)
	_expect(highest - lowest > 0.001, "engine idle keeps the body breathing (%.4f)" % (highest - lowest))
	_expect(
		highest - 1.0 <= feel.tuning.engine_max_variance + 0.001
		and 1.0 - lowest <= feel.tuning.engine_max_variance + 0.001,
		"engine idle stays inside max_variance (%.4f to %.4f)" % [lowest, highest]
	)

	car.queue_free()


func _record(label: String, value: float, unit: String, expected: float, tolerance: float) -> void:
	var ok := absf(value - expected) <= absf(expected) * tolerance
	_results.append(
		"  %-34s %9.3f %-6s (expect %.3f +/- %.0f%%)  %s"
		% [label, value, unit, expected, tolerance * 100.0, "ok" if ok else "MISMATCH"]
	)
	if not ok:
		_failures.append("%s = %.3f %s, expected %.3f" % [label, value, unit, expected])


func _expect(condition: bool, message: String) -> void:
	_results.append("  %-6s %s" % ["ok" if condition else "FAILED", message])
	if not condition:
		_failures.append(message)


func _report() -> void:
	print("\n=== arcade vehicle movement check ===")
	for line in _results:
		print(line)
	if _failures.is_empty():
		print("\nall checks passed\n")
		return
	print("\n%d FAILURE(S):" % _failures.size())
	for failure in _failures:
		print("  - " + failure)
	print("")
