class_name CircularArena
extends Node3D
## Round arena with a ring wall, built in code.
##
## The wall is a polygon of flat box segments rather than a curved shape. Godot
## has no inside-out primitive, and a concave trimesh is fragile against
## CharacterBody3D sweeps. Flat segments also suit the arcade wall glide, which
## works off a single surface normal per contact: at 64 segments the normal turns
## 5.6 degrees per joint, which reads as a smooth curve at driving speed.

@export_group("Arena")
## Inner radius of the wall, in metres.
@export var radius: float = 40.0
@export var wall_height: float = 2.0
@export var wall_thickness: float = 1.0
## More segments means a rounder wall. 64 gives ~4 m panels on a 40 m arena.
@export_range(8, 256) var wall_segments: int = 64

@export_group("Obstacles")
@export var pillar_count: int = 5
@export var pillar_ring_radius: float = 18.0
@export var pillar_size: float = 2.5

@export_group("Spawns")
## Players spawn on a ring this fraction of the way out, facing the middle.
@export_range(0.1, 0.95) var spawn_ring_fraction: float = 0.6

var _wall_body: StaticBody3D


func _ready() -> void:
	_build_floor()
	_build_wall()
	_build_pillars()


## Where player `index` of `count` starts: evenly spaced, nose toward the centre.
## Returned in world space, so the arena does not have to sit at the origin.
func get_spawn_transform(index: int, count: int) -> Transform3D:
	var slots := maxi(1, count)
	var angle := TAU * (float(index) / float(slots))
	var spawn_radius := radius * spawn_ring_fraction
	var offset := Vector3(sin(angle) * spawn_radius, 0.44, cos(angle) * spawn_radius)

	# Face the middle. heading_to_yaw maps a direction to the -Z forward basis.
	var facing := Vector3(-offset.x, 0.0, -offset.z).normalized()
	var yaw := UeMath.heading_to_yaw(facing)
	return global_transform * Transform3D(Basis(Vector3.UP, yaw), offset)


func _build_floor() -> void:
	var floor_mesh := MeshInstance3D.new()
	var disc := CylinderMesh.new()
	disc.top_radius = radius
	disc.bottom_radius = radius
	disc.height = 0.1
	disc.radial_segments = maxi(24, wall_segments)
	floor_mesh.mesh = disc
	floor_mesh.position = Vector3(0.0, -0.05, 0.0)
	floor_mesh.material_override = _make_material(Color(0.16, 0.17, 0.19))
	# Visual only: the car is planar and never touches the ground.
	add_child(floor_mesh)


func _build_wall() -> void:
	_wall_body = StaticBody3D.new()
	_wall_body.name = "Wall"
	add_child(_wall_body)

	var material := _make_material(Color(0.32, 0.34, 0.40))
	var segments := maxi(8, wall_segments)
	var centre_radius := radius + wall_thickness * 0.5
	# Edge length of a polygon whose faces are tangent to the circle, plus a
	# little overlap so neighbouring segments cannot leave a seam to snag on.
	var segment_length := 2.0 * radius * tan(PI / float(segments)) * 1.05
	var size := Vector3(segment_length, wall_height, wall_thickness)

	for i in segments:
		var angle := TAU * (float(i) / float(segments))
		var offset := Vector3(sin(angle), 0.0, cos(angle))
		var transform := Transform3D(
			Basis(Vector3.UP, angle),
			offset * centre_radius + Vector3(0.0, wall_height * 0.5, 0.0)
		)

		var shape := CollisionShape3D.new()
		var box := BoxShape3D.new()
		box.size = size
		shape.shape = box
		shape.transform = transform
		_wall_body.add_child(shape)

		var mesh_instance := MeshInstance3D.new()
		var box_mesh := BoxMesh.new()
		box_mesh.size = size
		mesh_instance.mesh = box_mesh
		mesh_instance.transform = transform
		mesh_instance.material_override = material
		_wall_body.add_child(mesh_instance)


func _build_pillars() -> void:
	if pillar_count <= 0:
		return

	var material := _make_material(Color(0.55, 0.30, 0.26))
	for i in pillar_count:
		var angle := TAU * (float(i) / float(pillar_count))
		var position := Vector3(
			sin(angle) * pillar_ring_radius, wall_height * 0.5, cos(angle) * pillar_ring_radius
		)
		var size := Vector3(pillar_size, wall_height, pillar_size)

		var body := StaticBody3D.new()
		body.position = position

		var shape := CollisionShape3D.new()
		var box := BoxShape3D.new()
		box.size = size
		shape.shape = box
		body.add_child(shape)

		var mesh_instance := MeshInstance3D.new()
		var box_mesh := BoxMesh.new()
		box_mesh.size = size
		mesh_instance.mesh = box_mesh
		mesh_instance.material_override = material
		body.add_child(mesh_instance)

		add_child(body)


func _make_material(color: Color) -> StandardMaterial3D:
	var material := StandardMaterial3D.new()
	material.albedo_color = color
	return material
