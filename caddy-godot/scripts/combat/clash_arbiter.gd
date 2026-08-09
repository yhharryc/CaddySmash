extends Node
## Autoload that resolves every car-on-car contest, once, fairly.
##
## Why this exists: collisions used to be resolved by whichever car's
## _physics_process ran first, which is tree order, which is spawn order, which
## is player number. ArcadeVehicle._handle_blocking_collision rewrites its own
## velocity while resolving, so the second car swept into an opponent that had
## already been slowed and turned. Measured on a symmetric head-on, the car that
## moved first scored on 44 m/s of closing speed and the other on 14.2 — a
## deterministic 3.1x advantage to P1.
##
## The fix is the velocity snapshot below. Taken before any car has moved, it is
## the same for both sides no matter who reports the contact, so closing speed is
## a property of the crash rather than of the tick order.
##
## No class_name: Godot rejects a global class that shadows an autoload name,
## same as PlayerRoster and HitStop.

## Cars register here so their velocity can be snapshotted each frame.
const VEHICLE_GROUP := &"vehicles"

enum Outcome {
	## One car had strictly higher momentum.
	DECIDED,
	## Equal momentum: both pay.
	CLASH,
}

## Both cars are always named so listeners can tell whether they were involved;
## `winner` is null on a CLASH.
signal contest_resolved(
	first: ArcadeVehicle,
	second: ArcadeVehicle,
	winner: ArcadeVehicle,
	outcome: Outcome,
	closing_speed: float,
	position: Vector3
)

@export var enabled: bool = true
## Damage the winner takes, as a fraction of what it would have taken. 0 means a
## clean win. Raise toward 0.25 if winning proves too safe.
@export_range(0.0, 1.0) var winner_damage_ratio: float = 0.0
## Damage each side takes on an equal-momentum clash.
@export_range(0.0, 1.0) var clash_damage_ratio: float = 0.85
## Minimum seconds between resolutions for the same pair, replacing the
## per-attacker cooldown that used to live on ImpactAdjudicator.
@export var pair_cooldown_seconds: float = 0.2

## Vehicle instance id -> velocity at the start of this physics frame.
var _snapshot: Dictionary = {}
## Pair key -> seconds remaining before that pair may resolve again.
var _pair_cooldowns: Dictionary = {}
## Pair keys already resolved this frame.
var _resolved_this_frame: Dictionary = {}


func _ready() -> void:
	# Ahead of everything: drivers sit at -10, skills -5, combat -4, cars 0.
	# The snapshot has to be taken before any of them can move a car.
	process_physics_priority = -100


func _physics_process(delta: float) -> void:
	_resolved_this_frame.clear()

	for key in _pair_cooldowns.keys():
		var remaining: float = _pair_cooldowns[key] - delta
		if remaining <= 0.0:
			_pair_cooldowns.erase(key)
		else:
			_pair_cooldowns[key] = remaining

	_snapshot.clear()
	for node in get_tree().get_nodes_in_group(VEHICLE_GROUP):
		var car := node as ArcadeVehicle
		if car != null:
			_snapshot[car.get_instance_id()] = car.velocity


## Velocity the car had before anything moved this frame. Falls back to its
## current velocity when no snapshot exists yet, e.g. on the first frame or in a
## test that steps physics by hand.
func velocity_at_frame_start(car: ArcadeVehicle) -> Vector3:
	if car == null:
		return Vector3.ZERO
	return _snapshot.get(car.get_instance_id(), car.velocity)


## Order-independent key for a pair of cars.
static func pair_key(a: ArcadeVehicle, b: ArcadeVehicle) -> String:
	var ida := a.get_instance_id()
	var idb := b.get_instance_id()
	return "%d:%d" % ([ida, idb] if ida < idb else [idb, ida])


func is_pair_ready(a: ArcadeVehicle, b: ArcadeVehicle) -> bool:
	return not _pair_cooldowns.has(pair_key(a, b))


## Called by whichever car noticed the contact. Safe to call from both.
func report(
	reporter: ArcadeVehicle, other: ArcadeVehicle, normal: Vector3, position: Vector3
) -> void:
	if not enabled or reporter == null or other == null or reporter == other:
		return

	var key := pair_key(reporter, other)
	if _resolved_this_frame.has(key) or _pair_cooldowns.has(key):
		return
	_resolved_this_frame[key] = true

	var contact_normal := Vector3(normal.x, 0.0, normal.z).normalized()
	if contact_normal.is_zero_approx():
		contact_normal = (other.global_position - reporter.global_position)
		contact_normal.y = 0.0
		contact_normal = contact_normal.normalized()
	if contact_normal.is_zero_approx():
		return

	# The whole point: both velocities come from the same pre-movement snapshot.
	var closing := _closing_speed(reporter, other, contact_normal)

	var reporter_impact := _score(reporter, other, closing, contact_normal, position)
	var other_impact := _score(other, reporter, closing, -contact_normal, position)
	if reporter_impact == null and other_impact == null:
		return

	_pair_cooldowns[key] = maxf(0.0, pair_cooldown_seconds)
	_resolve(reporter, other, reporter_impact, other_impact, closing, position)


## Closing speed along the contact normal, from the frame-start snapshot.
func _closing_speed(a: ArcadeVehicle, b: ArcadeVehicle, normal: Vector3) -> float:
	var relative := velocity_at_frame_start(a) - velocity_at_frame_start(b)
	relative.y = 0.0
	return absf(relative.dot(normal))


## Runs one side through its own ImpactAdjudicator so all the existing scoring,
## tiering and gating is reused verbatim - only the closing speed is corrected.
func _score(
	attacker: ArcadeVehicle,
	target: ArcadeVehicle,
	closing: float,
	normal: Vector3,
	position: Vector3
) -> ImpactEvent:
	var adjudicator := _adjudicator_for(attacker)
	if adjudicator == null:
		return null

	var collision := VehicleCollisionEvent.new()
	collision.collider = target
	collision.normal = normal
	collision.position = position
	collision.total_speed = velocity_at_frame_start(attacker).length()
	collision.normal_impact_speed = closing
	collision.relative_normal_speed = closing
	collision.target_speed = velocity_at_frame_start(target).length()
	collision.target_is_vehicle = true
	collision.is_drifting = _is_sliding(attacker)
	collision.is_skill_dashing = attacker.skill_dashing
	return adjudicator.adjudicate(collision)


## Real lateral slip, not the is_drifting flag, which is true by default and so
## says nothing about commitment.
func _is_sliding(car: ArcadeVehicle) -> bool:
	var momentum := momentum_for(car)
	if momentum == null:
		return car.is_drifting
	return momentum.slip() >= momentum.tuning.slip_for_bump


func _resolve(
	a: ArcadeVehicle,
	b: ArcadeVehicle,
	a_impact: ImpactEvent,
	b_impact: ImpactEvent,
	closing: float,
	position: Vector3
) -> void:
	var a_tier := tier_of(a)
	var b_tier := tier_of(b)

	if a_tier == b_tier:
		# Equal momentum: nobody wins, both pay a reduced price, both spin out.
		_apply(b, a_impact, clash_damage_ratio, true)
		_apply(a, b_impact, clash_damage_ratio, true)
		# Announced once, not once per side, or the shared effects double up.
		_announce(a_impact if a_impact != null else b_impact)
		contest_resolved.emit(a, b, null, Outcome.CLASH, closing, position)
		return

	var winner := a if a_tier > b_tier else b
	var loser := b if a_tier > b_tier else a
	var winner_impact := a_impact if winner == a else b_impact
	var loser_impact := b_impact if winner == a else a_impact

	# Winner walks away clean; loser takes the full hit plus stagger.
	_apply(loser, winner_impact, 1.0, true)
	_apply(winner, loser_impact, winner_damage_ratio, false)
	_announce(winner_impact)
	contest_resolved.emit(a, b, winner, Outcome.DECIDED, closing, position)


## Re-emits impact_dealt on the attacker's adjudicator so everything already
## listening for a landed hit — hit stop, screen shake, VFX, the debug readout —
## keeps working now that scoring has moved in here. Fired once per resolution.
func _announce(impact: ImpactEvent) -> void:
	if impact == null:
		return
	var adjudicator := _adjudicator_for(impact.attacker)
	if adjudicator != null:
		adjudicator.impact_dealt.emit(impact)


## Applies one side's scored impact to a car, scaled, optionally without the
## reactions. A ratio of 0 skips the car entirely.
func _apply(
	target: ArcadeVehicle, impact: ImpactEvent, damage_ratio: float, allow_reactions: bool
) -> void:
	if impact == null or target == null or damage_ratio <= 0.0:
		return
	var combat := VehicleCombat.find_for(target)
	if combat == null:
		return

	var scaled := ImpactEvent.new()
	scaled.attacker = impact.attacker
	scaled.target = target
	scaled.tier = impact.tier
	scaled.impact_score = impact.impact_score
	scaled.effective_normal_speed = impact.effective_normal_speed
	scaled.damage = impact.damage * damage_ratio
	scaled.is_clash = impact.is_clash
	scaled.normal = impact.normal
	scaled.position = impact.position
	scaled.was_drifting = impact.was_drifting
	scaled.was_skill_dashing = impact.was_skill_dashing
	scaled.apply_knockback = impact.apply_knockback and allow_reactions
	scaled.apply_stagger = impact.apply_stagger and allow_reactions
	combat.receive_impact(scaled)


func tier_of(car: ArcadeVehicle) -> MomentumTier.Value:
	var momentum := momentum_for(car)
	return momentum.tier if momentum != null else MomentumTier.Value.LOW


func momentum_for(car: ArcadeVehicle) -> VehicleMomentum:
	if car == null:
		return null
	for child in car.get_children():
		if child is VehicleMomentum:
			return child
	return null


func _adjudicator_for(car: ArcadeVehicle) -> ImpactAdjudicator:
	if car == null:
		return null
	for child in car.get_children():
		if child is ImpactAdjudicator:
			return child
	return null
