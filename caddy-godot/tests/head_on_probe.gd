extends Node3D
## Diagnostic: stages a perfectly symmetric head-on between two cars and reports
## what each side actually deals and takes.
##
##   godot --headless --path caddy-godot res://tests/head_on_probe.tscn
##
## Both cars are identical, start at mirrored positions, and drive at each other
## at full throttle. Any difference in the result comes from the order they are
## stepped in, which in the real game is spawn order, which is player number.

const TICK := 1.0 / 60.0
## Far from the wall and the arena the movement suite builds.
const LANE_X := 2000.0

var _log: PackedStringArray = []


func _ready() -> void:
	Engine.physics_ticks_per_second = 60
	await get_tree().physics_frame
	await get_tree().process_frame

	_log.append("=== symmetric head-on, both cars identical ===")
	await _run_exchange("P1 first (real spawn order)", false)
	await _run_exchange("P2 first (order reversed)", true)
	_log.append("")
	_log.append("Both blocks must match. Any difference is tick-order bias.")

	for line in _log:
		print(line)
	get_tree().quit()


func _run_exchange(label: String, reverse_order: bool) -> void:
	var scene := load("res://scenes/vehicle.tscn") as PackedScene

	var a := scene.instantiate() as ArcadeVehicle
	var b := scene.instantiate() as ArcadeVehicle
	add_child(a)
	add_child(b)
	a.name = "CarA"
	b.name = "CarB"

	# Mirrored: A at -Z facing +Z, B at +Z facing -Z. Forward is -Z at yaw 0.
	a.global_position = Vector3(LANE_X, 0.35, -9.0)
	a.rotation.y = PI
	b.global_position = Vector3(LANE_X, 0.35, 9.0)
	b.rotation.y = 0.0

	# The physics server only learns about the new bodies on the next step; step
	# them by hand before that and their sweeps hit nothing at all.
	await get_tree().physics_frame
	await get_tree().process_frame

	var parts_a := _parts(a)
	var parts_b := _parts(b)

	var taken := {"CarA": 0.0, "CarB": 0.0}
	var dealt := {"CarA": [], "CarB": []}

	parts_a["combat"].damage_taken.connect(
		func(amount: float, _i: ImpactEvent) -> void: taken["CarA"] += amount
	)
	parts_b["combat"].damage_taken.connect(
		func(amount: float, _i: ImpactEvent) -> void: taken["CarB"] += amount
	)
	parts_a["adjudicator"].impact_dealt.connect(
		func(impact: ImpactEvent) -> void: dealt["CarA"].append(impact)
	)
	parts_b["adjudicator"].impact_dealt.connect(
		func(impact: ImpactEvent) -> void: dealt["CarB"].append(impact)
	)

	var first: ArcadeVehicle = b if reverse_order else a
	var second: ArcadeVehicle = a if reverse_order else b
	var first_parts: Dictionary = parts_b if reverse_order else parts_a
	var second_parts: Dictionary = parts_a if reverse_order else parts_b

	var contests: Array[String] = []
	ClashArbiter.contest_resolved.connect(
		func(
			p: ArcadeVehicle,
			q: ArcadeVehicle,
			w: ArcadeVehicle,
			outcome: ClashArbiter.Outcome,
			closing: float,
			_pos: Vector3
		) -> void:
			contests.append(
				"CLASH %s vs %s @ %.1f m/s" % [p.name, q.name, closing]
				if outcome == ClashArbiter.Outcome.CLASH
				else "%s WON vs %s @ %.1f m/s" % [w.name, (q if w == p else p).name, closing]
			)
	)

	for i in int(3.0 / TICK):
		for car in [first, second]:
			car.set_throttle_input(1.0)
			car.set_move_intent(Vector3.ZERO)
		# The arbiter snapshots both velocities before anything has moved. This
		# is what makes the result independent of the order below.
		ClashArbiter._physics_process(TICK)
		for parts in [first_parts, second_parts]:
			parts["momentum"]._physics_process(TICK)
			parts["adjudicator"]._physics_process(TICK)
			parts["combat"]._physics_process(TICK)
		# The ordering that used to decide everything.
		first._physics_process(TICK)
		second._physics_process(TICK)

	_log.append("")
	_log.append("--- %s ---" % label)
	for key in ["CarA", "CarB"]:
		var hits: Array = dealt[key]
		var summary := "no hit registered"
		if not hits.is_empty():
			var impact: ImpactEvent = hits[0]
			summary = (
				"%s  closing %.1f m/s  score %.1f  damage %.1f"
				% [
					ImpactTier.name_of(impact.tier),
					impact.effective_normal_speed,
					impact.impact_score,
					impact.damage,
				]
			)
		_log.append("  %s dealt:  %s" % [key, summary])
	_log.append(
		"  damage taken:  CarA %.1f   CarB %.1f" % [taken["CarA"], taken["CarB"]]
	)
	_log.append("  momentum:      CarA %s   CarB %s" % [
		MomentumTier.name_of(parts_a["momentum"].tier),
		MomentumTier.name_of(parts_b["momentum"].tier),
	])
	_log.append("  contests:      %s" % ("none" if contests.is_empty() else contests[0]))

	a.queue_free()
	b.queue_free()


func _parts(car: ArcadeVehicle) -> Dictionary:
	var parts := {}
	for child in car.get_children():
		if child is VehicleCombat:
			parts["combat"] = child
		elif child is ImpactAdjudicator:
			parts["adjudicator"] = child
		elif child is VehicleMomentum:
			parts["momentum"] = child
		elif child is PlayerVehicleDriver:
			# No input source; the probe drives the cars directly.
			child.enabled = false
	return parts
