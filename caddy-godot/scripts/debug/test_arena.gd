extends Node3D
## Throwaway test geometry: a walled arena plus a few pillars to slide off.
## Built in code so the test scene stays small while the collision response is
## still being tuned.

@export var arena_size: float = 80.0
@export var wall_height: float = 2.0
@export var wall_thickness: float = 1.0
@export var pillar_positions: Array[Vector2] = [
	Vector2(14.0, 10.0),
	Vector2(-16.0, 6.0),
	Vector2(4.0, -18.0),
	Vector2(-10.0, -24.0),
	Vector2(24.0, -6.0),
]

var _wall_material: StandardMaterial3D
var _pillar_material: StandardMaterial3D


func _ready() -> void:
	_wall_material = _make_material(Color(0.32, 0.34, 0.40))
	_pillar_material = _make_material(Color(0.55, 0.30, 0.26))

	var half := arena_size * 0.5
	var span := arena_size + wall_thickness * 2.0
	_add_box(
		Vector3(0.0, wall_height * 0.5, -half - wall_thickness * 0.5),
		Vector3(span, wall_height, wall_thickness),
		_wall_material
	)
	_add_box(
		Vector3(0.0, wall_height * 0.5, half + wall_thickness * 0.5),
		Vector3(span, wall_height, wall_thickness),
		_wall_material
	)
	_add_box(
		Vector3(-half - wall_thickness * 0.5, wall_height * 0.5, 0.0),
		Vector3(wall_thickness, wall_height, span),
		_wall_material
	)
	_add_box(
		Vector3(half + wall_thickness * 0.5, wall_height * 0.5, 0.0),
		Vector3(wall_thickness, wall_height, span),
		_wall_material
	)

	for pillar in pillar_positions:
		_add_box(
			Vector3(pillar.x, wall_height * 0.5, pillar.y),
			Vector3(2.5, wall_height, 2.5),
			_pillar_material
		)


func _add_box(at: Vector3, size: Vector3, material: StandardMaterial3D) -> void:
	var body := StaticBody3D.new()
	body.position = at

	var shape := CollisionShape3D.new()
	var box := BoxShape3D.new()
	box.size = size
	shape.shape = box
	body.add_child(shape)

	var mesh_instance := MeshInstance3D.new()
	var mesh := BoxMesh.new()
	mesh.size = size
	mesh_instance.mesh = mesh
	mesh_instance.material_override = material
	body.add_child(mesh_instance)

	add_child(body)


func _make_material(color: Color) -> StandardMaterial3D:
	var material := StandardMaterial3D.new()
	material.albedo_color = color
	return material
