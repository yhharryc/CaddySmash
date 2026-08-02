class_name FeelTuning
extends Resource
## Port of FCaddyVehicleFeelConfig (UCaddyVehicleFeelComponent).
##
## Purely cosmetic: every value here moves the visual mesh only, never the
## collision body. Speeds and distances converted from cm to m.

@export_group("Acceleration deform")
## UE bEnableAccelerationDeform. Stretches under power, squashes under braking.
@export var enable_acceleration_deform: bool = true
## UE MaxForwardAccelForDeform 9000 cm/s^2.
@export var max_forward_accel_for_deform: float = 90.0
## UE MaxAccelSquashStretch 0.07.
@export var max_accel_squash_stretch: float = 0.07
## UE MaxSpeedStretch 0.03.
@export var max_speed_stretch: float = 0.03
## UE MaxSpeedForStretch 2200 cm/s.
@export var max_speed_for_stretch: float = 22.0

@export_group("Lean")
## UE bEnableLateralLean. Banks the body into a slide.
@export var enable_lateral_lean: bool = true
## UE LateralSpeedForMaxLean 1000 cm/s.
@export var lateral_speed_for_max_lean: float = 10.0
## UE MaxLateralLeanRollDeg 7.
@export var max_lateral_lean_roll_deg: float = 7.0

@export_group("Impact pulse")
## UE bEnableImpactPulse.
@export var enable_impact_pulse: bool = true
## UE ImpactPulseDuration 0.28.
@export var impact_pulse_duration: float = 0.28
## UE ImpactNormalSpeedForMaxPulse 1200 cm/s.
@export var impact_speed_for_max_pulse: float = 12.0
## UE ImpactPulseScale 0.10. Squash along the impact axis, bulge across it.
@export var impact_pulse_scale: float = 0.1
## UE ImpactPulseLocationKick 7.5 cm.
@export var impact_pulse_location_kick: float = 0.075
## UE ImpactPulseRotationKickDeg 4.
@export var impact_pulse_rotation_kick_deg: float = 4.0
## Fraction of the pulse spent snapping in. Small values hit hard.
@export_range(0.02, 0.9) var impact_attack: float = 0.12
## Optional override. X is normalised pulse time, Y is strength.
@export var impact_pulse_curve: Curve

@export_group("Dash")
@export var enable_dash_pulse: bool = true
## Anticipation: the body compresses as the dash charges, eased by charge alpha.
@export var dash_charge_squash: float = 0.14
## Release: stretch along the length axis, squashing width and height.
@export var dash_pulse_stretch: float = 0.26
@export var dash_pulse_duration: float = 0.38
@export_range(0.02, 0.9) var dash_attack: float = 0.1
## Optional override. X is normalised pulse time, Y is strength.
@export var dash_pulse_curve: Curve

@export_group("Engine")
## Idle vibration, expressed only as scale so it never fights the physics.
@export var enable_engine_vibration: bool = true
## UE BaseVariance 0.018.
@export var engine_base_variance: float = 0.018
## UE BaseFrequencyHz 6.2.
@export var engine_base_frequency_hz: float = 6.2
## UE ThrottleVarianceBoost 0.010.
@export var engine_throttle_variance_boost: float = 0.01
## UE ThrottleFrequencyBoostHz 1.6.
@export var engine_throttle_frequency_boost_hz: float = 1.6
## UE SpeedForCurveNormalization 1800 cm/s.
@export var engine_speed_for_normalization: float = 18.0
## UE MaxVariance 0.08.
@export var engine_max_variance: float = 0.08

@export_group("Smoothing")
## UE OffsetInterpSpeed 8.
@export var offset_interp_speed: float = 8.0
## UE ScaleInterpSpeed 10.
@export var scale_interp_speed: float = 10.0
