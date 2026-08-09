class_name VehicleMomentum
extends Node
## Tracks which of the three momentum states a car is in.
##
## This is the whole contest rule: when two cars hit, the higher tier wins. It
## has to be legible before contact, which is why the tier is deliberately sticky
## — hysteresis on the way down plus a minimum dwell time, so the outline the
## player is reading is not flickering between two answers.

signal tier_changed(new_tier: MomentumTier.Value, previous_tier: MomentumTier.Value)

@export var vehicle: ArcadeVehicle
@export var skill: BrakeDashSkill
@export var tuning: MomentumTuning

var tier: MomentumTier.Value = MomentumTier.Value.LOW
## 0..1 progress toward the next tier, for smooth visuals between steps.
var charge := 0.0

var _time_in_tier := 0.0


func _ready() -> void:
	if vehicle == null:
		vehicle = get_parent() as ArcadeVehicle
	if tuning == null:
		tuning = MomentumTuning.new()
	if skill == null and vehicle != null:
		for child in vehicle.get_children():
			if child is BrakeDashSkill:
				skill = child
				break


func is_dashing() -> bool:
	return skill != null and skill.state == BrakeDashSkill.State.DASHING


## Lateral slip in m/s. The honest "am I committed" signal, unlike is_drifting.
func slip() -> float:
	return absf(vehicle.get_lateral_speed()) if vehicle != null else 0.0


func _physics_process(delta: float) -> void:
	if vehicle == null:
		return

	_time_in_tier += delta
	charge = _compute_charge()

	var wanted := _wanted_tier()
	if wanted == tier:
		return
	# Rising is allowed to be instant so a dash reads immediately; falling and
	# any change at all still has to clear the dwell time.
	if _time_in_tier < tuning.min_tier_seconds:
		return

	var previous := tier
	tier = wanted
	_time_in_tier = 0.0
	tier_changed.emit(tier, previous)


## Base tier from speed, raised one step by a genuine slide, forced to the top by
## an active dash. Dropping a tier needs the speed to fall a margin below the
## threshold that raised it, so hovering on a boundary does not oscillate.
func _wanted_tier() -> MomentumTier.Value:
	if tuning.dash_forces_high and is_dashing():
		return MomentumTier.Value.HIGH

	var speed := vehicle.get_planar_speed()
	var high_gate := tuning.high_speed
	var mid_gate := tuning.mid_speed
	# Already at a tier? Then the gate to stay there is lower than the gate was
	# to reach it.
	if tier >= MomentumTier.Value.HIGH:
		high_gate -= tuning.tier_drop_margin
	if tier >= MomentumTier.Value.MID:
		mid_gate -= tuning.tier_drop_margin

	var base := MomentumTier.Value.LOW
	if speed >= high_gate:
		base = MomentumTier.Value.HIGH
	elif speed >= mid_gate:
		base = MomentumTier.Value.MID

	if slip() >= tuning.slip_for_bump:
		base = (
			MomentumTier.Value.HIGH
			if base >= MomentumTier.Value.MID
			else MomentumTier.Value.MID
		)

	return base


## How far through the current tier's speed band the car is, for visuals.
func _compute_charge() -> float:
	if is_dashing():
		return 1.0
	var speed := vehicle.get_planar_speed()
	match tier:
		MomentumTier.Value.HIGH:
			return 1.0
		MomentumTier.Value.MID:
			return clampf(
				(speed - tuning.mid_speed) / maxf(0.01, tuning.high_speed - tuning.mid_speed),
				0.0,
				1.0
			)
		_:
			return clampf(speed / maxf(0.01, tuning.mid_speed), 0.0, 1.0)
