class_name DriftTrailTuning
extends Resource
## Glowing skid ribbons laid down behind the rear wheels on a hard turn.

@export_group("Trigger")
@export var enabled: bool = true
## Lateral slip, in m/s, before a ribbon starts. Below this the car is gripping
## and there is nothing to draw.
@export var slip_threshold: float = 2.5
## Lateral slip that maps to a full-width, full-brightness ribbon.
@export var slip_for_full_effect: float = 9.0
## Minimum forward speed before trails appear, so a spinning stationary car
## does not smear the ground.
@export var min_speed: float = 3.0

@export_group("Shape")
## Local offsets of the two emitters, in car space. Z positive is toward the rear.
@export var wheel_offset: Vector3 = Vector3(0.46, -0.3, 0.72)
@export var ribbon_width: float = 0.24
## Seconds a segment stays on the ground before it has fully faded.
@export var lifetime: float = 0.85
## Distance the car must travel before another segment is laid down.
@export var sample_distance: float = 0.22
@export var max_segments: int = 48

@export_group("Look")
## Multiplied by the player colour so each car's trail reads as theirs.
@export var tint: Color = Color(1.0, 0.75, 0.35, 1.0)
## Additive blending makes the ribbon glow rather than just sit on the floor.
@export var additive: bool = true
## Height above the ground, to stop the ribbon z-fighting the floor.
@export var ground_offset: float = 0.03
