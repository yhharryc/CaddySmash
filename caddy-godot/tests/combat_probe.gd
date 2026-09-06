extends Node3D
## Diagnostic: how long is a victim helpless, how far do they get pushed, and can
## the attacker simply drive back and do it again before they recover?
##
##   godot --headless --path caddy-godot res://tests/combat_probe.tscn
##
## The number that decides whether hits chain for free is the last column:
## input lock minus the time the attacker needs to re-close the gap. Positive
## means the attacker arrives while the victim is still frozen.

const TICK := 1.0 / 60.0
const LANE_X := 7000.0

var _log: PackedStringArray = []
var _combat_tuning: CombatTuning
var _vehicle_tuning: VehicleTuning


func _ready() -> void:
	Engine.physics_ticks_per_second = 60
	_combat_tuning = load("res://resources/tuning/combat_default.tres")
	_vehicle_tuning = load("res://resources/tuning/tuning_default.tres")
	await get_tree().physics_frame
	await get_tree().process_frame
	_run()
	for line in _log:
		print(line)
	get_tree().quit()


func _run() -> void:
	_log.append("=== hit stun vs knockback, per tier ===")
	_log.append(
		"  %-8s %10s %11s %12s %13s %14s"
		% ["tier", "lock", "kb speed", "kb distance", "re-close", "free window"]
	)

	for tier in [ImpactTier.Value.LIGHT, ImpactTier.Value.MEDIUM, ImpactTier.Value.HEAVY]:
		var row := _measure(tier)
		_log.append(
			"  %-8s %9.2fs %10.1f %11.2fm %12.2fs %13.2fs%s"
			% [
				ImpactTier.name_of(tier),
				row["lock"],
				row["speed"],
				row["distance"],
				row["reclose"],
				row["free"],
				"   <- free chain" if row["free"] > 0.0 else "",
			]
		)

	_log.append("")
	_log.append("re-close assumes the attacker keeps top speed (%.0f m/s) and drives" % _vehicle_tuning.max_forward_speed)
	_log.append("straight back. free window = lock - re-close; above zero the victim is")
	_log.append("still frozen when the next hit lands.")
	_log.append("")
	_log.append("stagger also stacks: a fresh hit restarts the lock from full.")


## Drives one real knockback and measures how far the car actually travels.
func _measure(tier: ImpactTier.Value) -> Dictionary:
	var car := _make_car()
	add_child(car)
	car.global_position = Vector3(LANE_X, 0.35, 0.0)
	var combat := VehicleCombat.new()
	combat.vehicle = car
	combat.tuning = _combat_tuning
	car.add_child(combat)

	var attacker := _make_car()
	add_child(attacker)
	attacker.global_position = Vector3(LANE_X, 0.35, 4.0)

	var impact := ImpactEvent.new()
	impact.attacker = attacker
	impact.target = car
	impact.tier = tier
	impact.damage = 1.0
	impact.normal = Vector3.BACK
	impact.apply_knockback = true
	impact.apply_stagger = true

	var start := car.global_position
	combat.receive_impact(impact)

	var lock := combat.stagger_remaining
	var speed := car.get_planar_speed()

	# Run the knockback out, moving the car for real so the distance is measured
	# rather than assumed from speed x duration.
	var guard := 0
	while combat.is_knocked_back() and guard < 400:
		combat._physics_process(TICK)
		car._physics_process(TICK)
		guard += 1
	# Plus the carry-over roll, which is part of the separation the victim gets.
	while car.get_planar_speed() > 0.5 and guard < 800:
		car._physics_process(TICK)
		guard += 1

	var distance := start.distance_to(car.global_position)
	var reclose := distance / maxf(0.01, _vehicle_tuning.max_forward_speed)

	car.queue_free()
	attacker.queue_free()
	return {
		"lock": lock,
		"speed": speed,
		"distance": distance,
		"reclose": reclose,
		"free": lock - reclose,
	}


func _make_car() -> ArcadeVehicle:
	var car := ArcadeVehicle.new()
	car.tuning = _vehicle_tuning
	var shape := CollisionShape3D.new()
	var box := BoxShape3D.new()
	box.size = Vector3(1.4, 0.875, 2.3)
	shape.shape = box
	car.add_child(shape)
	return car
