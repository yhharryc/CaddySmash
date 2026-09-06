extends Node3D
## Diagnostic: how fast does the car actually reach top speed, and how much of
## the arena does that eat?
##
##   godot --headless --path caddy-godot res://tests/acceleration_probe.tscn
##
## Reports time AND distance, because distance is what decides whether speed is a
## choice the player makes or just the state they are permanently in. It also
## reports where the momentum tier gates fall, since those decide contests.

const TICK := 1.0 / 60.0
## Clear of every other probe's geometry.
const LANE_X := 5000.0
## Arena the numbers are judged against: radius 19 in arena_match.tscn.
const ARENA_RADIUS := 19.0

var _log: PackedStringArray = []
var _vehicle: ArcadeVehicle
var _base_tuning: VehicleTuning
var _momentum_tuning: MomentumTuning


func _ready() -> void:
	Engine.physics_ticks_per_second = 60
	_base_tuning = load("res://resources/tuning/tuning_default.tres")
	_momentum_tuning = load("res://resources/tuning/momentum_default.tres")

	_vehicle = ArcadeVehicle.new()
	_vehicle.tuning = _base_tuning.duplicate()
	var shape := CollisionShape3D.new()
	var box := BoxShape3D.new()
	box.size = Vector3(1.4, 0.875, 2.3)
	shape.shape = box
	_vehicle.add_child(shape)
	add_child(_vehicle)

	await get_tree().physics_frame
	await get_tree().process_frame

	_report_current()
	_report_sweep()
	_report_stopping()

	for line in _log:
		print(line)
	get_tree().quit()


func _report_current() -> void:
	var t: VehicleTuning = _vehicle.tuning
	_log.append("=== current tuning ===")
	_log.append(
		"forward_acceleration %.0f m/s^2  (%.1f g)   max_forward_speed %.0f m/s (%.0f km/h)"
		% [
			t.forward_acceleration,
			t.forward_acceleration / 9.81,
			t.max_forward_speed,
			t.max_forward_speed * 3.6,
		]
	)
	_log.append("arena radius %.0f m  ->  %.0f m across" % [ARENA_RADIUS, ARENA_RADIUS * 2.0])
	_log.append("")

	var run := _measure(t.forward_acceleration)
	_log.append("full throttle from rest:")
	_log.append("  %-26s %8s %10s %10s" % ["milestone", "time", "distance", "% of arena"])
	for row in run["rows"]:
		_log.append(
			"  %-26s %7.2fs %9.1fm %9.0f%%"
			% [row["label"], row["time"], row["distance"], row["arena_pct"]]
		)


## The headline sweep. Each row is a candidate forward_acceleration.
func _report_sweep() -> void:
	_log.append("")
	_log.append("=== if forward_acceleration changed (max speed held at 22 m/s) ===")
	_log.append(
		"  %6s %6s %9s %9s %10s %10s"
		% ["accel", "g", "t to 95%", "d to 95%", "d to MID", "d to HIGH"]
	)

	for accel in [62.0, 45.0, 32.0, 24.0, 18.0, 12.0, 8.0]:
		var run := _measure(accel)
		_log.append(
			"  %6.0f %6.1f %8.2fs %8.1fm %9.1fm %9.1fm%s"
			% [
				accel,
				accel / 9.81,
				run["t95"],
				run["d95"],
				run["d_mid"],
				run["d_high"],
				"   <- current" if is_equal_approx(accel, 62.0) else "",
			]
		)

	_log.append("")
	_log.append(
		"d to HIGH is the one that matters for contests: below it the car cannot"
	)
	_log.append(
		"win a clash. At %.0f m across, anything under ~4 m means every fight"
		% (ARENA_RADIUS * 2.0)
	)
	_log.append("happens at top tier and momentum stops being a decision.")


## Coast and brake distances, for contrast: acceleration only feels fast relative
## to how long it takes to shed the speed again.
func _report_stopping() -> void:
	var t: VehicleTuning = _vehicle.tuning
	_log.append("")
	_log.append("=== shedding speed from top ===")
	for mode in ["coast", "brake"]:
		_reset()
		_run_to_top()
		var start := _vehicle.global_position
		var elapsed := 0.0
		var guard := 0
		while _vehicle.get_planar_speed() > 0.5 and guard < 2000:
			_vehicle.set_throttle_input(0.0)
			_vehicle.set_brake_reverse_input(1.0 if mode == "brake" else 0.0)
			_vehicle.set_move_intent(Vector3.ZERO)
			_vehicle._physics_process(TICK)
			elapsed += TICK
			guard += 1
		_log.append(
			"  %-6s to a stop:  %.2fs over %.1f m"
			% [mode, elapsed, start.distance_to(_vehicle.global_position)]
		)
	# Restore the shipping value first: the sweep left the last candidate in place.
	var launch := _measure(_base_tuning.forward_acceleration)
	_log.append(
		"  regaining it:      %.2fs over %.1f m  (at the shipping %.0f m/s^2)"
		% [launch["t95"], launch["d95"], _base_tuning.forward_acceleration]
	)


## Runs one full-throttle launch and records where each milestone falls.
func _measure(acceleration: float) -> Dictionary:
	_vehicle.tuning.forward_acceleration = acceleration
	_reset()

	var top: float = _vehicle.tuning.max_forward_speed
	var milestones := [
		{"label": "25% of top speed", "speed": top * 0.25},
		{"label": "MID momentum gate", "speed": _momentum_tuning.mid_speed},
		{"label": "50% of top speed", "speed": top * 0.5},
		{"label": "HIGH momentum gate", "speed": _momentum_tuning.high_speed},
		{"label": "90% of top speed", "speed": top * 0.9},
		{"label": "95% of top speed", "speed": top * 0.95},
		{"label": "99% of top speed", "speed": top * 0.99},
	]

	var start := _vehicle.global_position
	var elapsed := 0.0
	var rows: Array[Dictionary] = []
	var index := 0
	var guard := 0

	while index < milestones.size() and guard < 3000:
		_vehicle.set_throttle_input(1.0)
		_vehicle.set_brake_reverse_input(0.0)
		_vehicle.set_move_intent(Vector3.ZERO)
		_vehicle._physics_process(TICK)
		elapsed += TICK
		guard += 1

		var distance := start.distance_to(_vehicle.global_position)
		while (
			index < milestones.size()
			and _vehicle.get_planar_speed() >= float(milestones[index]["speed"])
		):
			rows.append({
				"label": milestones[index]["label"],
				"time": elapsed,
				"distance": distance,
				"arena_pct": distance / (ARENA_RADIUS * 2.0) * 100.0,
			})
			index += 1

	var result := {"rows": rows}
	for row in rows:
		match row["label"]:
			"95% of top speed":
				result["t95"] = row["time"]
				result["d95"] = row["distance"]
			"MID momentum gate":
				result["d_mid"] = row["distance"]
			"HIGH momentum gate":
				result["d_high"] = row["distance"]
	# A car too slow to ever reach a gate still needs a number in the table.
	for key in ["t95", "d95", "d_mid", "d_high"]:
		if not result.has(key):
			result[key] = INF
	return result


func _run_to_top() -> void:
	for i in 300:
		_vehicle.set_throttle_input(1.0)
		_vehicle.set_move_intent(Vector3.ZERO)
		_vehicle._physics_process(TICK)


func _reset() -> void:
	_vehicle.velocity = Vector3.ZERO
	_vehicle.rotation = Vector3.ZERO
	_vehicle.global_position = Vector3(LANE_X, 0.35, 0.0)
	_vehicle.set_control_lock_enabled(false)
	_vehicle.set_external_velocity_control_enabled(false)
	# Inputs persist until overwritten. Leaving the brake held from a previous
	# run makes the next launch hold throttle and brake at once, which cancels
	# acceleration entirely and silently reports "never reached top speed".
	_vehicle.set_throttle_input(0.0)
	_vehicle.set_brake_reverse_input(0.0)
