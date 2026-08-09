class_name MomentumTuning
extends Resource
## What raises and lowers a car's momentum state.
##
## Speed sets the base tier; genuinely sliding raises it one; an active dash
## forces the top. Note that "drifting" is NOT used: with grip unheld — the
## default and the shipping feel — ArcadeVehicle.is_drifting is always true, so
## it says nothing about commitment. Real lateral slip does.

@export_group("Speed")
## Planar speed at or above which the car sits in MID. Max forward speed is 22.
@export var mid_speed: float = 10.0
## Planar speed at or above which the car sits in HIGH.
@export var high_speed: float = 18.0

@export_group("Commitment")
## Lateral slip, in m/s, that raises the tier by one. Matches the band
## DriftTrail uses to decide a slide is worth drawing.
@export var slip_for_bump: float = 5.0
## An active brake-dash forces HIGH regardless of speed - it is the committed
## offensive move, and winning contests is what it is for.
@export var dash_forces_high: bool = true

@export_group("Stability")
## How far below a threshold the car must fall before it drops a tier. Without
## this the state flickers whenever speed hovers on a boundary, which makes the
## outline strobe and the contest rule feel arbitrary. Same enter/exit shape as
## the reverse-steering latch in ArcadeVehicle.
@export var tier_drop_margin: float = 1.6
## Minimum time a tier is held before it may change again, in seconds. Stops a
## single-frame spike from repainting the car.
@export var min_tier_seconds: float = 0.14
