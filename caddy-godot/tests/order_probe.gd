extends Node3D
## Does player number change the result of a crash?
##
##   godot --headless --path caddy-godot res://tests/order_probe.tscn
##
## Tree order is spawn order is player number, and it is the order the engine
## steps the cars in. Each crash is run twice, swapping only which car is added
## to the tree first. Unlike head_on_probe nothing is stepped by hand: the engine
## schedules every node itself, exactly as in a match. Exits non-zero if the two
## orders disagree on damage, winners or closing speed.

const LANE_X := 2000.0

var _log: PackedStringArray = []


func _ready() -> void:
	Engine.physics_ticks_per_second = 60
	await get_tree().physics_frame
	# name, A start, A yaw, B start, B yaw, A throttle, B throttle
	var scenarios := [
		["head-on, both full throttle", Vector3(0, 0, -9), PI, Vector3(0, 0, 9), 0.0, 1.0, 1.0],
		["T-bone, A into side of B", Vector3(0, 0, -9), PI, Vector3(0, 0, 0), PI / 2.0, 1.0, 0.0],
		["T-bone, both moving", Vector3(0, 0, -9), PI, Vector3(-6, 0, 0), -PI / 2.0, 1.0, 1.0],
	]
	var mismatches := 0
	for s in scenarios:
		_log.append("\n== %s ==" % s[0])
		var results: Array[String] = []
		for a_first in [true, false]:
			results.append(await _run(s, a_first))
		_log.append("  A spawned first:  " + results[0])
		_log.append("  B spawned first:  " + results[1])
		if results[0] != results[1]:
			mismatches += 1
			_log.append("  MISMATCH: player number changed the result")
	_log.append("")
	_log.append("order independent" if mismatches == 0 else "%d scenario(s) depend on player number" % mismatches)
	for line in _log:
		print(line)
	get_tree().quit(0 if mismatches == 0 else 1)


func _run(s: Array, a_first: bool) -> String:
	var scene := load("res://scenes/vehicle.tscn") as PackedScene
	var a := scene.instantiate() as ArcadeVehicle
	var b := scene.instantiate() as ArcadeVehicle
	a.name = "CarA"
	b.name = "CarB"
	# Tree order is spawn order is player number.
	if a_first:
		add_child(a)
		add_child(b)
	else:
		add_child(b)
		add_child(a)
	for car in [a, b]:
		for child in car.get_children():
			if child is PlayerVehicleDriver:
				child.enabled = false
	a.global_position = Vector3(LANE_X, 0.44, 0) + s[1]
	a.rotation.y = s[2]
	b.global_position = Vector3(LANE_X, 0.44, 0) + s[3]
	b.rotation.y = s[4]

	var hp := {}
	var contests: Array[String] = []
	var on_contest := func(
		p: ArcadeVehicle, q: ArcadeVehicle, w: ArcadeVehicle,
		outcome: ClashArbiter.Outcome, closing: float, _pos: Vector3
	) -> void:
		if not (p == a or p == b):
			return
		contests.append(
			("CLASH" if outcome == ClashArbiter.Outcome.CLASH else "%s won" % w.name)
			+ " @%.1f" % closing
		)
	ClashArbiter.contest_resolved.connect(on_contest)
	var feed := func() -> void:
		a.set_throttle_input(s[5])
		b.set_throttle_input(s[6])
	get_tree().physics_frame.connect(feed)

	# 2 s of real frames. Hit stop slows physics, so count physics ticks, not time.
	for i in 120:
		await get_tree().physics_frame

	get_tree().physics_frame.disconnect(feed)
	ClashArbiter.contest_resolved.disconnect(on_contest)
	HitStop.cancel()
	var hp_a: float = VehicleCombat.find_for(a).health
	var hp_b: float = VehicleCombat.find_for(b).health
	var line := "A lost %.1f  B lost %.1f  contests %s" % [
		1000.0 - hp_a, 1000.0 - hp_b,
		", ".join(contests) if not contests.is_empty() else "none"]
	a.queue_free()
	b.queue_free()
	await get_tree().physics_frame
	await get_tree().physics_frame
	return line
