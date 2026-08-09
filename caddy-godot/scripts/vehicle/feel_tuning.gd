class_name FeelTuning
extends Resource
## Port of FCaddyVehicleFeelConfig (UCaddyVehicleFeelComponent), extended with
## the impact-swell, outline and charge-anticipation layers Unreal did not have.
##
## Purely cosmetic: every value here moves the visual mesh only, never the
## collision body. Speeds and distances converted from cm to m.

@export_group("Acceleration deform")
## UE bEnableAccelerationDeform. Stretches under power, squashes under braking.
@export var enable_acceleration_deform: bool = true
## UE MaxForwardAccelForDeform 9000 cm/s^2.
@export var max_forward_accel_for_deform: float = 90.0
## UE MaxAccelSquashStretch 0.07, exaggerated.
@export var max_accel_squash_stretch: float = 0.16
## UE MaxSpeedStretch 0.03, exaggerated.
@export var max_speed_stretch: float = 0.09
## UE MaxSpeedForStretch 2200 cm/s.
@export var max_speed_for_stretch: float = 22.0

@export_group("Lean")
## UE bEnableLateralLean. Banks the body into a slide.
@export var enable_lateral_lean: bool = true
## UE LateralSpeedForMaxLean 1000 cm/s.
@export var lateral_speed_for_max_lean: float = 10.0
## UE MaxLateralLeanRollDeg 7, exaggerated.
@export var max_lateral_lean_roll_deg: float = 16.0

@export_group("Impact pulse")
## UE bEnableImpactPulse.
@export var enable_impact_pulse: bool = true
## UE ImpactPulseDuration 0.28.
@export var impact_pulse_duration: float = 0.34
## UE ImpactNormalSpeedForMaxPulse 1200 cm/s.
@export var impact_speed_for_max_pulse: float = 12.0
## Sudden growth on impact. UE shrank the car instead, which reads as the car
## losing rather than as landing a hit; a swell reads as force.
@export var impact_inflate: float = 0.42
## How much the hit axis deviates from the uniform swell. 0 is a pure balloon;
## higher flattens along the impact and bulges across it. Kept well under 1 so
## the car never ends up smaller than it started.
@export_range(0.0, 0.9) var impact_directional_bias: float = 0.45
## UE ImpactPulseLocationKick 7.5 cm, exaggerated.
@export var impact_pulse_location_kick: float = 0.24
## UE ImpactPulseRotationKickDeg 4, exaggerated.
@export var impact_pulse_rotation_kick_deg: float = 15.0
## Fraction of the pulse spent snapping in. Small values hit hard.
@export_range(0.02, 0.9) var impact_attack: float = 0.1
## Optional override. X is normalised pulse time, Y is strength.
@export var impact_pulse_curve: Curve

@export_group("Momentum outline")
## Outline strength at MID. LOW is always zero — no outline at all is itself a
## readable state, and it keeps the low tier visually quiet.
@export var momentum_outline_mid: float = 0.62
## Outline strength at HIGH.
@export var momentum_outline_high: float = 1.0
## Thickness multiplier at HIGH, on top of impact_outline_grow. This is what
## makes the top tier read as exaggerated rather than just brighter.
@export var high_outline_scale: float = 2.4
## Pulse rate of the HIGH outline, in Hz.
@export var outline_pulse_hz: float = 5.5
## How much of the HIGH outline thickness the pulse swings, 0..1.
@export_range(0.0, 1.0) var outline_pulse_amount: float = 0.4

@export_group("Impact outline")
## Inverted-hull outline flashed on impact, for a comic-book emphasis frame.
@export var enable_impact_outline: bool = true
@export var impact_outline_color: Color = Color(1.0, 0.97, 0.85)
## Outline thickness in metres at full strength.
@export var impact_outline_grow: float = 0.13

@export_group("Dash release")
@export var enable_dash_pulse: bool = true
## Stretch along the length axis on release, squashing width and height.
@export var dash_pulse_stretch: float = 0.5
@export var dash_pulse_duration: float = 0.38
@export_range(0.02, 0.9) var dash_attack: float = 0.1
## Optional override. X is normalised pulse time, Y is strength.
@export var dash_pulse_curve: Curve

@export_group("Dash charge")
## Compression that builds while charging, so the release has something to
## release from. Driven through an ease so it loads late rather than linearly.
@export var dash_charge_squash: float = 0.28
## Peak yaw wiggle at full charge, in degrees.
@export var charge_wiggle_max_deg: float = 11.0
## Wiggle rate at the start of the charge, in Hz.
@export var charge_wiggle_base_hz: float = 6.0
## Wiggle rate at full charge. The ramp between the two is what reads as the car
## straining harder the longer you hold.
@export var charge_wiggle_max_hz: float = 27.0
## Lateral throw of the tail, in metres, counter to the yaw so the nose stays
## roughly planted and the back end does the swinging.
@export var charge_tail_swing: float = 0.22
## Squash pumped in time with the wiggle, on top of the steady compression.
@export var charge_shudder: float = 0.06

@export_group("Engine")
## Idle vibration, expressed only as scale so it never fights the physics.
@export var enable_engine_vibration: bool = true
## UE BaseVariance 0.018.
@export var engine_base_variance: float = 0.024
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
