class_name VehicleCombat
extends Node
## Target-side combat state. Collapses UCaddyVehicleAttributeSet,
## UCaddyVehicleHitRegisterDamageableComponent, UCaddyVehicleKnockbackAbility and
## UCaddyVehicleStaggerAbility into one node.
##
## Unreal split these across GAS because it needed attribute replication and
## ability triggers. Without GAS the split earns nothing, so the four collapse
## into one: take damage, get shoved, get spun.
##
## Both reactions are driven by countdowns in _physics_process rather than
## SceneTree timers, so the whole thing steps deterministically under test.

## Ticks ahead of the vehicle so knockback velocity lands the same frame.
const _COMBAT_PRIORITY := -4

signal health_changed(health: float, max_health: float)
signal damage_taken(amount: float, impact: ImpactEvent)
signal destroyed
signal knockback_started(direction: Vector3, speed: float, duration: float)
signal knockback_ended(carry_speed: float)
## DI (or the host, online) re-aimed a knockback already under way. Carries the
## final values so a listener can copy them exactly.
signal knockback_redirected(direction: Vector3, hold_speed: float, carry_speed: float)
## spins and direction_sign are cosmetic, for the feel layer to consume.
signal stagger_started(duration: float, spins: int, direction_sign: float)
signal stagger_ended

@export var vehicle: ArcadeVehicle
@export var tuning: CombatTuning
## Aborted when knockback lands, so a dash and a shove cannot both drive velocity.
@export var skill: BrakeDashSkill

var health := 0.0

var knockback_remaining := 0.0
var stagger_remaining := 0.0

var _knockback_direction := Vector3.ZERO
## The shove is a flat hold, not a decay: UE re-set the same velocity every tick
## for the whole window.
var _knockback_hold_speed := 0.0
var _knockback_carry_speed := 0.0
## Set when a knockback starts, cleared once its DI has been read.
var _di_pending := false
var _stagger_active := false


## Finds the VehicleCombat belonging to a vehicle, or null if it has none.
static func find_for(target: ArcadeVehicle) -> VehicleCombat:
	if target == null:
		return null
	for child in target.get_children():
		if child is VehicleCombat:
			return child
	return null


func _ready() -> void:
	process_physics_priority = _COMBAT_PRIORITY
	if vehicle == null:
		vehicle = get_parent() as ArcadeVehicle
	if tuning == null:
		tuning = CombatTuning.new()
	health = tuning.max_health
	health_changed.emit(health, tuning.max_health)


func is_alive() -> bool:
	return health > 0.0


func is_staggered() -> bool:
	return _stagger_active


func is_knocked_back() -> bool:
	return knockback_remaining > 0.0


func _physics_process(delta: float) -> void:
	if vehicle == null:
		return

	if knockback_remaining > 0.0:
		# Like Smash, DI is read when hitlag ends, not on the frame of contact: the
		# hit-stop freeze is the player's window to choose. With no hit stop running
		# this is simply the first tick of the shove.
		if _di_pending and HitStop.freeze_remaining <= 0.0:
			_apply_directional_influence()
		knockback_remaining -= delta
		if knockback_remaining <= 0.0:
			_finish_knockback()
		else:
			# Hold the shove for its whole window; the car cannot drive out of it.
			vehicle.set_external_planar_velocity(_knockback_direction * _knockback_hold_speed)

	if _stagger_active:
		stagger_remaining -= delta
		if stagger_remaining <= 0.0:
			_finish_stagger()


# ---------------------------------------------------------------------------
# Damage
# ---------------------------------------------------------------------------

func receive_impact(impact: ImpactEvent) -> void:
	if not is_alive():
		return

	apply_damage(impact.damage, impact)
	if not is_alive():
		return

	if impact.apply_knockback:
		_start_knockback(impact)
	if impact.apply_stagger:
		_start_stagger(impact)


## UE routed this through an IncomingDamage meta attribute and
## PostGameplayEffectExecute; the clamp and the zero check are the whole of it.
func apply_damage(amount: float, impact: ImpactEvent = null) -> void:
	if amount <= 0.0 or not is_alive():
		return

	health = clampf(health - amount, 0.0, tuning.max_health)
	damage_taken.emit(amount, impact)
	health_changed.emit(health, tuning.max_health)

	if health <= 0.0:
		destroyed.emit()


## Online clients: the host already decided this hit and took the health off, so
## only the knockback and stagger are replayed, on the car this client predicts.
func apply_reactions(impact: ImpactEvent) -> void:
	if impact.apply_knockback:
		_start_knockback(impact)
	if impact.apply_stagger:
		_start_stagger(impact)


## Online clients: health comes from the host's snapshots. Deliberately never
## emits destroyed — the host announces eliminations, they are not inferred here.
func set_network_health(value: float) -> void:
	var clamped := clampf(value, 0.0, tuning.max_health)
	if is_equal_approx(clamped, health):
		return
	health = clamped
	health_changed.emit(health, tuning.max_health)


func heal(amount: float) -> void:
	if amount <= 0.0:
		return
	health = clampf(health + amount, 0.0, tuning.max_health)
	health_changed.emit(health, tuning.max_health)


# ---------------------------------------------------------------------------
# Knockback
# ---------------------------------------------------------------------------

func _start_knockback(impact: ImpactEvent) -> void:
	var direction := _resolve_knockback_direction(impact)
	if direction.is_zero_approx():
		return

	var speed := _knockback_speed_for(impact.tier)
	speed *= 1.0 - clampf(tuning.knockback_resistance, 0.0, 0.95)
	var duration := maxf(0.01, _knockback_duration_for(impact.tier))

	# Unreal let a dash and a knockback both hold external velocity control, so
	# whichever finished first handed it back mid-effect. Cancelling the skill
	# keeps ownership single.
	if skill != null and skill.is_active():
		skill.abort_to_ready()

	_knockback_direction = direction
	_knockback_hold_speed = speed
	_knockback_carry_speed = speed * clampf(_knockback_carry_for(impact.tier), 0.0, 1.0)
	knockback_remaining = duration
	_di_pending = true

	vehicle.set_external_velocity_control_enabled(true)
	vehicle.set_external_planar_velocity(direction * speed)
	knockback_started.emit(direction, speed, duration)


## Smash Bros-style directional influence. Only the stick's component *across*
## the launch turns it, by up to knockback_di_max_angle_deg toward the stick:
## holding straight along the launch, toward or away, turns nothing. Optional
## launch speed influence then uses the component along it.
##
## Always ends in override_knockback, even when nothing changes, so the result is
## always announced: online the host's answer must reach the owner either way.
func _apply_directional_influence() -> void:
	_di_pending = false
	var stick := Vector3(vehicle.stick_intent.x, 0.0, vehicle.stick_intent.z)
	if stick.length() < tuning.knockback_di_dead_zone:
		stick = Vector3.ZERO

	var launch := _knockback_direction
	var max_angle := deg_to_rad(maxf(0.0, tuning.knockback_di_max_angle_deg))
	# cross(launch, stick).y is |stick| * sin(angle from launch to stick), signed
	# for a turn about +Y: positive turns the launch toward the stick.
	var across := clampf(launch.cross(stick).y, -1.0, 1.0)
	var along := clampf(launch.dot(stick), -1.0, 1.0)
	var speed_scale := 1.0 + clampf(tuning.knockback_di_speed_scale, 0.0, 0.5) * along

	override_knockback(
		launch.rotated(Vector3.UP, max_angle * across),
		_knockback_hold_speed * speed_scale,
		_knockback_carry_speed * speed_scale
	)


## Re-aims a knockback already under way. Used by DI, and online by a client to
## take the host's final answer for its own car so the two cannot disagree.
func override_knockback(direction: Vector3, hold_speed: float, carry_speed: float) -> void:
	var planar := Vector3(direction.x, 0.0, direction.z)
	if knockback_remaining <= 0.0 or planar.is_zero_approx():
		return
	_di_pending = false
	_knockback_direction = planar.normalized()
	_knockback_hold_speed = maxf(0.0, hold_speed)
	_knockback_carry_speed = maxf(0.0, carry_speed)
	vehicle.set_external_planar_velocity(_knockback_direction * _knockback_hold_speed)
	knockback_redirected.emit(_knockback_direction, _knockback_hold_speed, _knockback_carry_speed)


func _finish_knockback() -> void:
	knockback_remaining = 0.0
	_di_pending = false
	vehicle.set_external_velocity_control_enabled(false)
	if not _knockback_direction.is_zero_approx() and _knockback_carry_speed > 0.0001:
		vehicle.set_external_planar_velocity(_knockback_direction * _knockback_carry_speed)
	knockback_ended.emit(_knockback_carry_speed)


## Shoved away from the attacker, bent along the attacker's path by
## knockback_momentum_blend, falling back to straight backwards.
func _resolve_knockback_direction(impact: ImpactEvent) -> Vector3:
	if impact.attacker != null:
		var away := vehicle.global_position - impact.attacker.global_position
		away.y = 0.0
		if not away.is_zero_approx():
			return _blend_attacker_momentum(away.normalized(), impact.attacker)
	return -vehicle.planar_forward()


## Mixes the attacker's direction of travel into `away`, so a sideswipe carries
## the hit car along the attacker's path instead of straight out sideways. Head-
## on and rear-end hits are untouched: there the path already points away.
##
## Velocity comes from ClashArbiter's frame-start snapshot, taken before either
## car moved, so the collision itself (which rewrites the attacker's velocity)
## cannot distort it.
func _blend_attacker_momentum(away: Vector3, attacker: ArcadeVehicle) -> Vector3:
	var blend := clampf(tuning.knockback_momentum_blend, 0.0, 1.0)
	if blend <= 0.0:
		return away

	var travel := ClashArbiter.velocity_at_frame_start(attacker)
	travel.y = 0.0
	var speed := travel.length()
	if speed < 0.01:
		return away

	# Never pull toward the attacker: drop any part of its travel that points back
	# at it (reversing away, or moving past the far side). What remains is
	# deliberately not renormalised, so only the sideways share of the path counts.
	var path := travel / speed
	var backward := path.dot(away)
	if backward < 0.0:
		path -= away * backward
	if path.is_zero_approx():
		return away

	var weight := blend * clampf(speed / maxf(0.01, attacker.get_max_speed()), 0.0, 1.0)
	return (away * (1.0 - weight) + path * weight).normalized()


func _knockback_speed_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_knockback_speed
		ImpactTier.Value.MEDIUM:
			return tuning.medium_knockback_speed
		_:
			return tuning.light_knockback_speed


func _knockback_duration_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_knockback_duration
		ImpactTier.Value.MEDIUM:
			return tuning.medium_knockback_duration
		_:
			return tuning.light_knockback_duration


func _knockback_carry_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_knockback_carry
		ImpactTier.Value.MEDIUM:
			return tuning.medium_knockback_carry
		_:
			return tuning.light_knockback_carry


# ---------------------------------------------------------------------------
# Stagger
# ---------------------------------------------------------------------------

func _start_stagger(impact: ImpactEvent) -> void:
	var duration := _stagger_duration_for(impact.tier)
	var spins := _stagger_spins_for(impact.tier)
	if duration <= 0.0001 or spins <= 0:
		return

	_stagger_active = true
	stagger_remaining = maxf(0.01, _stagger_input_lock_for(impact.tier))
	vehicle.set_control_lock_enabled(true)
	stagger_started.emit(duration, spins, _resolve_stagger_direction_sign(impact))


func _finish_stagger() -> void:
	_stagger_active = false
	stagger_remaining = 0.0
	vehicle.set_control_lock_enabled(false)
	stagger_ended.emit()


## Which way the spin reads. UE took sign(cross(forward, -normal).Z) under a
## left-handed Z-up basis; projecting onto the body's right axis is the same
## question ("did it come from my right?") without the handedness reasoning.
func _resolve_stagger_direction_sign(impact: ImpactEvent) -> float:
	var planar_normal := Vector3(impact.normal.x, 0.0, impact.normal.z).normalized()
	if planar_normal.is_zero_approx():
		return 1.0
	var side := vehicle.planar_right().dot(-planar_normal)
	return signf(side) if absf(side) > 0.0001 else 1.0


func _stagger_duration_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_stagger_duration
		ImpactTier.Value.MEDIUM:
			return tuning.medium_stagger_duration
		_:
			return tuning.light_stagger_duration


func _stagger_spins_for(tier: ImpactTier.Value) -> int:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_stagger_spins
		ImpactTier.Value.MEDIUM:
			return tuning.medium_stagger_spins
		_:
			return tuning.light_stagger_spins


func _stagger_input_lock_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_stagger_input_lock
		ImpactTier.Value.MEDIUM:
			return tuning.medium_stagger_input_lock
		_:
			return tuning.light_stagger_input_lock
