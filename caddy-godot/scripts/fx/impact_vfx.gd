class_name ImpactVfx
extends RefCounted
## One-shot impact visuals, built in code so no scene authoring is needed.
##
## Two layers: a spark burst for the debris read, and an expanding ring for the
## shockwave read. Both self-free. Both ease — the ring in particular uses a
## quintic ease-out so it snaps outward and drifts to a stop.


## Spark burst at a world point. `strength` is 0..1 and scales count and reach.
static func spark_burst(
	parent: Node, world_position: Vector3, color: Color, strength: float
) -> GPUParticles3D:
	var s := clampf(strength, 0.0, 1.0)

	var particles := GPUParticles3D.new()
	particles.emitting = false
	particles.one_shot = true
	particles.amount = maxi(8, int(lerpf(10.0, 44.0, s)))
	particles.lifetime = lerpf(0.28, 0.55, s)
	particles.explosiveness = 1.0
	particles.local_coords = false

	var process := ParticleProcessMaterial.new()
	process.emission_shape = ParticleProcessMaterial.EMISSION_SHAPE_SPHERE
	process.emission_sphere_radius = 0.35
	process.direction = Vector3(0.0, 1.0, 0.0)
	process.spread = 180.0
	process.initial_velocity_min = lerpf(3.0, 9.0, s)
	process.initial_velocity_max = lerpf(7.0, 20.0, s)
	process.gravity = Vector3(0.0, -18.0, 0.0)
	process.damping_min = 2.0
	process.damping_max = 6.0
	process.scale_min = lerpf(0.35, 0.7, s)
	process.scale_max = lerpf(0.7, 1.5, s)
	# Shrinks as it dies rather than popping out of existence.
	var scale_curve := Curve.new()
	scale_curve.add_point(Vector2(0.0, 1.0))
	scale_curve.add_point(Vector2(1.0, 0.0))
	var scale_texture := CurveTexture.new()
	scale_texture.curve = scale_curve
	process.scale_curve = scale_texture
	process.color = color
	particles.process_material = process

	var quad := QuadMesh.new()
	quad.size = Vector2(0.18, 0.18)
	particles.draw_pass_1 = quad
	particles.material_override = _unshaded_material(color, true)

	parent.add_child(particles)
	particles.global_position = world_position
	particles.emitting = true
	_free_after(particles, particles.lifetime + 0.3)
	return particles


## Spiky star ring, flat on the ground plane. Reads as the shockwave.
##
## Timing is deliberately short and front-loaded: it snaps to most of its size
## almost immediately (exponential ease-out), holds its brightness, then drops
## out fast. A slower, evenly-fading ring reads as a bubble rather than a hit.
static func shockwave(
	parent: Node, world_position: Vector3, color: Color, strength: float
) -> MeshInstance3D:
	var s := clampf(strength, 0.0, 1.0)

	var ring := MeshInstance3D.new()
	ring.mesh = spiky_ring_mesh(
		int(lerpf(9.0, 16.0, s)), 0.62, 1.0, 0.74
	)
	var material := _unshaded_material(color, true)
	ring.material_override = material
	parent.add_child(ring)
	ring.global_position = world_position + Vector3(0.0, 0.08, 0.0)
	# Starts already visible at readable size, so frame one reads as a hit.
	ring.scale = Vector3.ONE * lerpf(1.2, 2.0, s)

	var target_scale := lerpf(3.4, 9.5, s)
	var duration := lerpf(0.13, 0.22, s)

	var tween := ring.create_tween()
	tween.set_parallel(true)
	tween.tween_property(ring, "scale", Vector3.ONE * target_scale, duration).set_trans(
		Tween.TRANS_EXPO
	).set_ease(Tween.EASE_OUT)
	# EASE_IN on alpha holds it bright, then kills it late and fast.
	tween.tween_property(material, "albedo_color:a", 0.0, duration).set_trans(
		Tween.TRANS_EXPO
	).set_ease(Tween.EASE_IN)
	tween.chain().tween_callback(ring.queue_free)
	return ring


## Flat star-shaped band in the XZ plane: alternating long spikes and short
## notches around an inner rim. Built directly on the ground plane so it needs no
## rotation, and with UP normals since it renders unshaded anyway.
static func spiky_ring_mesh(
	spikes: int, inner_radius: float, spike_radius: float, notch_radius: float
) -> ArrayMesh:
	var count := maxi(3, spikes) * 2
	var surface := SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)

	for i in count:
		var angle_a := TAU * float(i) / float(count)
		var angle_b := TAU * float(i + 1) / float(count)
		var radius_a := spike_radius if i % 2 == 0 else notch_radius
		var radius_b := notch_radius if i % 2 == 0 else spike_radius

		var dir_a := Vector3(sin(angle_a), 0.0, cos(angle_a))
		var dir_b := Vector3(sin(angle_b), 0.0, cos(angle_b))
		var inner_a := dir_a * inner_radius
		var inner_b := dir_b * inner_radius
		var outer_a := dir_a * radius_a
		var outer_b := dir_b * radius_b

		for vertex in [inner_a, outer_a, outer_b, inner_a, outer_b, inner_b]:
			surface.set_normal(Vector3.UP)
			surface.add_vertex(vertex)

	return surface.commit()


static func _unshaded_material(color: Color, additive: bool) -> StandardMaterial3D:
	var material := StandardMaterial3D.new()
	material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
	material.albedo_color = color
	material.vertex_color_use_as_albedo = true
	if additive:
		material.blend_mode = BaseMaterial3D.BLEND_MODE_ADD
	material.billboard_mode = BaseMaterial3D.BILLBOARD_DISABLED
	material.cull_mode = BaseMaterial3D.CULL_DISABLED
	return material


static func _free_after(node: Node, seconds: float) -> void:
	var timer := node.get_tree().create_timer(seconds, true, false, true)
	timer.timeout.connect(node.queue_free)
