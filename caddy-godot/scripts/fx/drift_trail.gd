class_name DriftTrail
extends MeshInstance3D
## Glowing skid ribbons behind the rear wheels while the car is sliding.
##
## Built as a rebuilt-every-frame ImmediateMesh ribbon rather than particles: a
## skid mark has to be a continuous strip anchored to the ground the car has
## already crossed, which particles cannot express. Segments are dropped every
## `sample_distance` metres so the ribbon length tracks distance travelled, not
## frame rate.
##
## `top_level` is on so the ribbon stays in world space — it must not inherit the
## car's transform, or the marks would drag along behind it like a cape.

@export var vehicle: ArcadeVehicle
@export var tuning: DriftTrailTuning
## Set by the match to the player's colour.
@export var color: Color = Color(1.0, 0.75, 0.35)

## Each entry: {"pos": Vector3, "right": Vector3, "age": float, "strength": float}
var _left: Array[Dictionary] = []
var _right: Array[Dictionary] = []

var _immediate := ImmediateMesh.new()
var _last_sample_position := Vector3.INF


func _ready() -> void:
	top_level = true
	mesh = _immediate
	if vehicle == null:
		vehicle = get_parent() as ArcadeVehicle
	if tuning == null:
		tuning = DriftTrailTuning.new()

	var material := StandardMaterial3D.new()
	material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
	material.vertex_color_use_as_albedo = true
	material.cull_mode = BaseMaterial3D.CULL_DISABLED
	# Off, or the ribbon would occlude itself where segments overlap.
	material.no_depth_test = false
	material.depth_draw_mode = BaseMaterial3D.DEPTH_DRAW_DISABLED
	if tuning.additive:
		material.blend_mode = BaseMaterial3D.BLEND_MODE_ADD
	material_override = material


## 0..1 measure of how hard the car is currently sliding sideways.
func slip_strength() -> float:
	if vehicle == null or not tuning.enabled:
		return 0.0
	if vehicle.get_planar_speed() < tuning.min_speed:
		return 0.0
	var slip := absf(vehicle.get_lateral_speed())
	if slip < tuning.slip_threshold:
		return 0.0
	return clampf(
		(slip - tuning.slip_threshold)
		/ maxf(0.01, tuning.slip_for_full_effect - tuning.slip_threshold),
		0.0,
		1.0
	)


func _process(delta: float) -> void:
	if vehicle == null:
		return
	_age_segments(delta)
	_maybe_sample()
	_rebuild()


func _age_segments(delta: float) -> void:
	# Explicitly typed: iterating an untyped array literal gives Variant, which
	# GDScript will not infer an int from.
	for list: Array[Dictionary] in [_left, _right]:
		var index: int = list.size() - 1
		while index >= 0:
			list[index]["age"] += delta
			if list[index]["age"] >= tuning.lifetime:
				list.remove_at(index)
			index -= 1


func _maybe_sample() -> void:
	var strength := slip_strength()
	var position := vehicle.global_position

	if strength <= 0.0:
		# Breaks the ribbon so a new slide does not connect to the last one.
		_last_sample_position = Vector3.INF
		return

	if (
		_last_sample_position != Vector3.INF
		and position.distance_to(_last_sample_position) < tuning.sample_distance
	):
		return
	_last_sample_position = position

	var right := vehicle.planar_right()
	var forward := vehicle.planar_forward()
	var offset := tuning.wheel_offset
	var base := position + Vector3(0.0, tuning.ground_offset - offset.y, 0.0) - forward * offset.z

	_push(_left, base - right * offset.x, right, strength)
	_push(_right, base + right * offset.x, right, strength)


func _push(list: Array[Dictionary], position: Vector3, right: Vector3, strength: float) -> void:
	list.append({"pos": position, "right": right, "age": 0.0, "strength": strength})
	while list.size() > tuning.max_segments:
		list.remove_at(0)


func _rebuild() -> void:
	_immediate.clear_surfaces()
	if _left.size() < 2 and _right.size() < 2:
		return

	_immediate.surface_begin(Mesh.PRIMITIVE_TRIANGLES)
	_emit_ribbon(_left)
	_emit_ribbon(_right)
	_immediate.surface_end()


func _emit_ribbon(list: Array[Dictionary]) -> void:
	if list.size() < 2:
		return

	for i in range(list.size() - 1):
		var a: Dictionary = list[i]
		var b: Dictionary = list[i + 1]
		# Fades along its length as well as with age, so the tail thins out
		# instead of ending on a hard edge.
		var color_a := _segment_color(a)
		var color_b := _segment_color(b)
		var half_a: Vector3 = a["right"] * tuning.ribbon_width * 0.5 * a["strength"]
		var half_b: Vector3 = b["right"] * tuning.ribbon_width * 0.5 * b["strength"]

		var a0: Vector3 = a["pos"] - half_a
		var a1: Vector3 = a["pos"] + half_a
		var b0: Vector3 = b["pos"] - half_b
		var b1: Vector3 = b["pos"] + half_b

		_vertex(a0, color_a)
		_vertex(a1, color_a)
		_vertex(b1, color_b)

		_vertex(a0, color_a)
		_vertex(b1, color_b)
		_vertex(b0, color_b)


func _segment_color(segment: Dictionary) -> Color:
	var life := 1.0 - clampf(float(segment["age"]) / maxf(0.01, tuning.lifetime), 0.0, 1.0)
	# Squared falloff: bright while fresh, then away quickly.
	var alpha := life * life * float(segment["strength"])
	var result := color * tuning.tint
	result.a = alpha
	return result


func _vertex(position: Vector3, vertex_color: Color) -> void:
	_immediate.surface_set_color(vertex_color)
	_immediate.surface_add_vertex(position)
