class_name ImpactFxTuning
extends Resource
## Emphasis applied when a hit lands: freeze, slow motion, screen shake, VFX.
##
## Scaled by impact tier, so a scrape and a full-charge dash into someone do not
## read the same. All of this is on top of the mesh deformation in VehicleFeel.

@export_group("Master")
@export var enable_hit_stop: bool = true
@export var enable_screen_shake: bool = true
@export var enable_vfx: bool = true

@export_group("Freeze - seconds of near-stopped time")
@export var light_freeze: float = 0.03
@export var medium_freeze: float = 0.06
@export var heavy_freeze: float = 0.11

@export_group("Slow motion - eased tail after the freeze")
@export var light_slow: float = 0.0
@export var medium_slow: float = 0.14
@export var heavy_slow: float = 0.3
## Time scale at the start of the tail. Eases back to 1 from here.
@export_range(0.05, 1.0) var slow_scale: float = 0.32

@export_group("Screen shake - trauma, squared before it is applied")
@export_range(0.0, 1.0) var light_trauma: float = 0.28
@export_range(0.0, 1.0) var medium_trauma: float = 0.55
@export_range(0.0, 1.0) var heavy_trauma: float = 0.9
## Trauma from scraping a wall, which should register but never dominate.
@export_range(0.0, 1.0) var wall_trauma_scale: float = 0.35

@export_group("VFX")
@export var spark_color: Color = Color(1.0, 0.85, 0.45)
@export var shockwave_color: Color = Color(1.0, 0.6, 0.3)
## Wall scrapes emit sparks but no shockwave, which is reserved for car-on-car.
@export var wall_sparks: bool = true
