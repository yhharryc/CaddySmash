class_name DriftTrailTuning
extends Resource
## Glowing skid ribbons laid down behind the rear wheels on a hard turn.

@export_group("Trigger")
@export var enabled: bool = true
## Trails are gated on momentum tier, not on sliding. LOW lays nothing down even
## in a full slide; MID and HIGH always lay a ribbon even driving dead straight.
## The trail is a readout of momentum, so it has to agree with the outline.
@export var mid_strength: float = 0.6
@export var high_strength: float = 1.0
## Slip still modulates within a tier, so a slide reads wider and brighter than
## a straight line at the same momentum.
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

@export_group("Tire sparks")
## Sparks thrown from the rear wheels at top momentum only, so the highest state
## has a signature nothing else shares.
@export var enable_tire_sparks: bool = true
@export var spark_color: Color = Color(1.0, 0.85, 0.5, 1.0)
@export var spark_amount: int = 26
@export var spark_lifetime: float = 0.34
@export var spark_speed: float = 7.0

@export_group("Look")
## Multiplied by the player colour so each car's trail reads as theirs.
@export var tint: Color = Color(1.0, 0.75, 0.35, 1.0)
## Additive blending makes the ribbon glow rather than just sit on the floor.
@export var additive: bool = true
## Height above the ground, to stop the ribbon z-fighting the floor.
@export var ground_offset: float = 0.03
