extends MeshInstance3D
## Port of UArcadeVehicleMovementComponent::DrawDebugVisuals.
##
## Green   nose direction
## Blue    body right axis
## Cyan    move intent (where the stick is pointing)
## Yellow  world velocity - the gap between this and green IS the drift
## Orange  lateral slip, drawn along the body's right axis

@export var vehicle: ArcadeVehicle
@export var direction_line_length: float = 2.8
@export var velocity_line_scale: float = 0.08
@export var draw_height: float = 0.3

var _immediate := ImmediateMesh.new()


func _ready() -> void:
	top_level = true
	mesh = _immediate

	var mat := StandardMaterial3D.new()
	mat.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	mat.vertex_color_use_as_albedo = true
	mat.no_depth_test = true
	material_override = mat

	set_process(vehicle != null)


func _process(_delta: float) -> void:
	_immediate.clear_surfaces()
	if vehicle == null or not visible:
		return

	var origin := vehicle.global_position + Vector3.UP * draw_height
	var forward := vehicle.planar_forward()
	var right := vehicle.planar_right()

	_immediate.surface_begin(Mesh.PRIMITIVE_LINES)

	_line(origin, forward * direction_line_length, Color.GREEN)
	_line(origin, right * direction_line_length * 0.45, Color(0.4, 0.55, 1.0))

	if vehicle.has_move_intent:
		_line(origin, vehicle.move_intent * direction_line_length, Color.CYAN)

	var planar_velocity := Vector3(vehicle.velocity.x, 0.0, vehicle.velocity.z)
	var speed := planar_velocity.length()
	if speed > 0.01:
		var length := clampf(
			speed * maxf(0.01, velocity_line_scale), 0.6, direction_line_length * 1.8
		)
		_line(origin, planar_velocity / speed * length, Color.YELLOW)

	var lateral := vehicle.get_lateral_speed()
	if absf(lateral) > 0.01:
		var lateral_length := clampf(absf(lateral) * 0.06, 0.4, direction_line_length)
		_line(origin, right * lateral_length * signf(lateral), Color.ORANGE)

	_immediate.surface_end()


func _line(from: Vector3, offset: Vector3, color: Color) -> void:
	_immediate.surface_set_color(color)
	_immediate.surface_add_vertex(from)
	_immediate.surface_set_color(color)
	_immediate.surface_add_vertex(from + offset)
