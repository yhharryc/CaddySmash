class_name ImpactFx
extends Node
## Drives the exaggerated hit emphasis: freeze, slow motion, shake, VFX.
##
## Two sources, deliberately different in weight:
##   - ImpactAdjudicator.impact_dealt, the scored car-on-car hit. Gets the full
##     treatment, scaled by tier.
##   - ArcadeVehicle.blocking_collision against anything that is not a car, i.e.
##     walls. Sparks and a little shake only; a wall scrape must never freeze the
##     match.
##
## Kept apart from VehicleFeel because that layer is per-car and cosmetic, while
## these effects are global (time scale, the shared camera) and must be dosed
## once per hit rather than once per car.

## Camera rigs add themselves to this group so any car can shake the shot.
const CAMERA_RIG_GROUP := &"camera_rig"

@export var vehicle: ArcadeVehicle
@export var adjudicator: ImpactAdjudicator
@export var feel: VehicleFeel
@export var tuning: ImpactFxTuning
## Player colour, set by MatchManager, so a won contest is tinted by the winner.
@export var color: Color = Color(1.0, 0.85, 0.45)


func _ready() -> void:
	if vehicle == null:
		vehicle = get_parent() as ArcadeVehicle
	if tuning == null:
		tuning = ImpactFxTuning.new()
	if adjudicator == null and vehicle != null:
		for child in vehicle.get_children():
			if child is ImpactAdjudicator:
				adjudicator = child
				break

	if feel == null and vehicle != null:
		for child in vehicle.get_children():
			if child is VehicleFeel:
				feel = child
				break

	if adjudicator != null:
		adjudicator.impact_dealt.connect(_on_impact_dealt)
	if vehicle != null:
		vehicle.blocking_collision.connect(_on_blocking_collision)
	ClashArbiter.contest_resolved.connect(_on_contest_resolved)


## The moment of decision. Both cars deform, but the loser far harder, and the
## shockwave takes the winner's colour so the result is legible in one frame.
##
## Global effects — hit stop, screen shake, the shared shockwave — are driven by
## one side only. The signal reaches every car's ImpactFx, so without this guard
## each contest would fire them twice.
func _on_contest_resolved(
	first: ArcadeVehicle,
	second: ArcadeVehicle,
	winner: ArcadeVehicle,
	outcome: ClashArbiter.Outcome,
	closing_speed: float,
	position: Vector3
) -> void:
	if vehicle != first and vehicle != second:
		return

	var is_clash := outcome == ClashArbiter.Outcome.CLASH
	var lost := not is_clash and vehicle != winner

	# Losing, or trading blows, deforms the body far more than winning does.
	if feel != null:
		var strength := closing_speed
		if not is_clash and not lost:
			strength *= 0.35
		var away := (position - vehicle.global_position)
		away.y = 0.0
		feel.play_impact(strength, -away.normalized() if not away.is_zero_approx() else Vector3.BACK)

	if vehicle != first:
		return

	if tuning.enable_hit_stop:
		# A clash is the heaviest moment in the game: nobody won, both are hurt.
		var freeze := tuning.heavy_freeze * (1.35 if is_clash else 1.0)
		var slow := tuning.heavy_slow * (1.3 if is_clash else 1.0)
		HitStop.request(freeze, slow, tuning.slow_scale)
	if tuning.enable_screen_shake:
		_shake(tuning.heavy_trauma * (1.2 if is_clash else 1.0))
	if tuning.enable_vfx:
		var tint := _winner_color(winner) if not is_clash else tuning.shockwave_color
		ImpactVfx.shockwave(_fx_parent(), position, tint, 1.0)
		ImpactVfx.spark_burst(_fx_parent(), position, tuning.spark_color, 1.0)


func _winner_color(winner: ArcadeVehicle) -> Color:
	if winner == null:
		return tuning.shockwave_color
	for child in winner.get_children():
		if child is ImpactFx:
			return (child as ImpactFx).color
	return tuning.shockwave_color


## Scored hit. Car-on-car is skipped here because ClashArbiter re-emits this
## signal for the debug readout, and _on_contest_resolved already drives the
## effects for those — handling both would fire everything twice.
func _on_impact_dealt(impact: ImpactEvent) -> void:
	if impact.target is ArcadeVehicle:
		return

	var position := impact.position
	if position.is_zero_approx() and vehicle != null:
		position = vehicle.global_position

	if tuning.enable_hit_stop:
		HitStop.request(
			_freeze_for(impact.tier), _slow_for(impact.tier), tuning.slow_scale
		)
	if tuning.enable_screen_shake:
		_shake(_trauma_for(impact.tier))
	if tuning.enable_vfx:
		var strength := _strength_for(impact.tier)
		ImpactVfx.spark_burst(_fx_parent(), position, tuning.spark_color, strength)
		ImpactVfx.shockwave(_fx_parent(), position, tuning.shockwave_color, strength)


## Wall contact. Scaled right down, and skipped entirely for car-on-car so the
## scored path above stays the single source of emphasis for real hits.
func _on_blocking_collision(event: VehicleCollisionEvent) -> void:
	if event.target_is_vehicle:
		return

	var strength := clampf(event.normal_impact_speed / 14.0, 0.0, 1.0)
	if strength < 0.25:
		return

	if tuning.enable_screen_shake:
		_shake(strength * tuning.wall_trauma_scale)
	if tuning.enable_vfx and tuning.wall_sparks:
		ImpactVfx.spark_burst(
			_fx_parent(), event.position, tuning.spark_color, strength * 0.6
		)


func _shake(trauma: float) -> void:
	if trauma <= 0.0:
		return
	for rig in get_tree().get_nodes_in_group(CAMERA_RIG_GROUP):
		if rig is VehicleCameraRig:
			rig.add_trauma(trauma)


## Effects are parented to the scene root, not the car: a spawned burst must
## outlive the hit and must not inherit the car's squash and stretch.
func _fx_parent() -> Node:
	var scene_root := get_tree().current_scene
	return scene_root if scene_root != null else get_tree().root


func _freeze_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_freeze
		ImpactTier.Value.MEDIUM:
			return tuning.medium_freeze
		_:
			return tuning.light_freeze


func _slow_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_slow
		ImpactTier.Value.MEDIUM:
			return tuning.medium_slow
		_:
			return tuning.light_slow


func _trauma_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return tuning.heavy_trauma
		ImpactTier.Value.MEDIUM:
			return tuning.medium_trauma
		_:
			return tuning.light_trauma


func _strength_for(tier: ImpactTier.Value) -> float:
	match tier:
		ImpactTier.Value.HEAVY:
			return 1.0
		ImpactTier.Value.MEDIUM:
			return 0.62
		_:
			return 0.3
