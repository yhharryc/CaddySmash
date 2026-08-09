class_name ImpactAdjudicator
extends Node
## Attacker-side collision scoring. Port of UHRN_AdjudicateVehicleCollision and
## UHRN_EmitVehicleCollisionGameplayEvents, which were HitRegister pipeline nodes.
##
## Lives on the car that did the hitting: it listens to its own vehicle's
## blocking_collision, turns the raw numbers into a tier and a damage figure, then
## hands the result to the target's VehicleCombat. Same attacker -> target flow
## Unreal had, without the tag-and-attribute plumbing in between.

## Fired on the attacker when a hit scores at or above the light threshold.
signal impact_dealt(impact: ImpactEvent)
## Fired when a hit was rejected, with the reason. Mirrors UE's stop reasons.
signal impact_rejected(reason: String)

@export var vehicle: ArcadeVehicle
@export var tuning: ImpactTuning

var _cooldown_remaining := 0.0


func _ready() -> void:
	if vehicle == null:
		vehicle = get_parent() as ArcadeVehicle
	if tuning == null:
		tuning = ImpactTuning.new()
	if vehicle != null:
		vehicle.blocking_collision.connect(_on_blocking_collision)


func _physics_process(delta: float) -> void:
	_cooldown_remaining = maxf(0.0, _cooldown_remaining - delta)


func _on_blocking_collision(collision: VehicleCollisionEvent) -> void:
	# Car-on-car goes to the arbiter, which resolves the pair once using velocities
	# snapshotted before anything moved. Scoring it here would hand the advantage
	# to whichever car happens to tick first — see clash_arbiter.gd.
	var target := collision.collider as ArcadeVehicle
	if collision.target_is_vehicle and target != null:
		ClashArbiter.report(vehicle, target, collision.normal, collision.position)
		return

	var impact := adjudicate(collision)
	if impact == null:
		return

	_cooldown_remaining = maxf(0.0, tuning.event_cooldown_seconds)
	impact_dealt.emit(impact)

	var target_combat := VehicleCombat.find_for(impact.target)
	if target_combat != null:
		target_combat.receive_impact(impact)


## Returns the scored impact, or null when the hit does not qualify. Pure apart
## from the rejection signal, so the scoring can be unit tested directly.
func adjudicate(collision: VehicleCollisionEvent) -> ImpactEvent:
	if _cooldown_remaining > 0.0001:
		impact_rejected.emit("cooldown")
		return null
	if collision.total_speed < tuning.min_speed_for_event:
		impact_rejected.emit("speed below threshold")
		return null
	if collision.normal_impact_speed < tuning.min_normal_impact_speed_for_event:
		impact_rejected.emit("normal speed below threshold")
		return null
	if tuning.require_vehicle_target and not collision.target_is_vehicle:
		impact_rejected.emit("target is not a vehicle")
		return null

	var effective_normal_speed := collision.normal_impact_speed
	if tuning.use_relative_normal_impact_speed:
		effective_normal_speed = maxf(
			collision.normal_impact_speed, collision.relative_normal_speed
		)

	var score := maxf(0.0, tuning.impact_score_scale) * effective_normal_speed
	if collision.is_drifting:
		score *= maxf(0.0, tuning.drifting_impact_multiplier)
	if collision.is_skill_dashing:
		score *= maxf(0.0, tuning.skill_dash_impact_multiplier)

	var tier := _resolve_tier(score)
	if tier == ImpactTier.Value.NONE and tuning.stop_if_below_light_threshold:
		impact_rejected.emit("below light threshold")
		return null

	var damage := maxf(
		0.0, tuning.damage_bias + effective_normal_speed * tuning.damage_by_normal_impact_speed
	)
	damage *= _tier_damage_multiplier(tier)

	if tuning.require_positive_final_damage and damage <= maxf(0.0, tuning.min_final_damage):
		impact_rejected.emit("no final damage")
		return null

	var impact := ImpactEvent.new()
	impact.attacker = vehicle
	impact.target = collision.collider as ArcadeVehicle
	impact.tier = tier
	impact.impact_score = score
	impact.effective_normal_speed = effective_normal_speed
	impact.damage = damage
	impact.normal = collision.normal
	impact.position = collision.position
	impact.was_drifting = collision.is_drifting
	impact.was_skill_dashing = collision.is_skill_dashing
	impact.is_clash = _resolve_clash(collision, impact.target, effective_normal_speed)
	impact.apply_knockback = tuning.emit_knockback
	impact.apply_stagger = _should_stagger(tier)
	return impact


func _resolve_tier(score: float) -> ImpactTier.Value:
	if score >= tuning.heavy_score_threshold:
		return ImpactTier.Value.HEAVY
	if score >= tuning.medium_score_threshold:
		return ImpactTier.Value.MEDIUM
	if score >= tuning.light_score_threshold:
		return ImpactTier.Value.LIGHT
	return ImpactTier.Value.NONE


func _tier_damage_multiplier(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.LIGHT:
			return maxf(0.0, tuning.light_damage_multiplier)
		ImpactTier.Value.MEDIUM:
			return maxf(0.0, tuning.medium_damage_multiplier)
		ImpactTier.Value.HEAVY:
			return maxf(0.0, tuning.heavy_damage_multiplier)
		_:
			return 1.0


## Head-on clash: both cars pointing at each other, both carrying comparable
## speed, and closing hard. UE tagged this Hit.Collision.Clash.
func _resolve_clash(
	collision: VehicleCollisionEvent, target: ArcadeVehicle, effective_normal_speed: float
) -> bool:
	if not tuning.enable_head_on_clash or target == null or vehicle == null:
		return false

	var facing_dot := vehicle.planar_forward().dot(-target.planar_forward())
	var max_speed := maxf(collision.total_speed, collision.target_speed)
	var speed_ratio := (
		minf(collision.total_speed, collision.target_speed) / max_speed
		if max_speed > 0.0001
		else 0.0
	)

	return (
		facing_dot >= tuning.clash_facing_dot_threshold
		and speed_ratio >= tuning.clash_speed_ratio_threshold
		and effective_normal_speed >= tuning.clash_min_relative_normal_speed
	)


## Whether an impact of this tier should stagger the target. Decided here rather
## than on the target, because UE ran this in the attacker's pipeline.
func _should_stagger(tier: ImpactTier.Value) -> bool:
	if not tuning.emit_stagger:
		return false
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.stagger_on_heavy
		ImpactTier.Value.MEDIUM:
			return tuning.stagger_on_medium
		ImpactTier.Value.LIGHT:
			return tuning.stagger_on_light
		_:
			return false
