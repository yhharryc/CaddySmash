class_name VehicleTuning
extends Resource
## Port of UCaddyVehicleTuningDataAsset's Gas + Handling configs.
##
## All Unreal values were in cm and cm/s; they are divided by 100 here so the
## Godot project works in meters. Interp speeds and angles are unitless and
## carry over unchanged. The UE default is noted next to each value.

## Shown by the preset switcher. Port of the naming on UE's runtime tuning
## presets, which were cycled with caddy.vehicle.tuning.next/prev.
@export var preset_name: String = "Default"

@export_group("Gas")
## UE MaxForwardSpeed 2200 cm/s.
@export var max_forward_speed: float = 22.0
## UE ForwardAcceleration 6200 cm/s^2.
@export var forward_acceleration: float = 62.0
## UE CoastDeceleration 2600 cm/s^2. Constant rate, applied with no input.
@export var coast_deceleration: float = 26.0
## UE BrakeDeceleration 8200 cm/s^2. Constant rate, applied while moving forward.
@export var brake_deceleration: float = 82.0
## UE MaxReverseSpeed 920 cm/s.
@export var max_reverse_speed: float = 9.2
## UE ReverseAcceleration 3600 cm/s^2.
@export var reverse_acceleration: float = 36.0

@export_group("Handling")
## UE SteeringRateDegPerSec 540.
@export var steering_rate_deg: float = 540.0
## UE MinSpeedForSteering 120 cm/s. Below this the body will not yaw.
@export var min_speed_for_steering: float = 1.2
## UE LinearDrag 0.3. Applied to the forward axis only, never to lateral slip.
@export var linear_drag: float = 0.3
## UE StopSpeedThreshold 8 cm/s. Speeds under this snap to rest.
@export var stop_speed_threshold: float = 0.08
## UE MoveIntentDeadZone 0.12.
@export var move_intent_dead_zone: float = 0.12

@export_group("Drift")
## UE DriftLateralFrictionInterpSpeed 2.5. Used in the car's resting state.
@export var drift_lateral_friction: float = 2.5
## UE LateralFrictionInterpSpeed 7.5. Used only while the grip input is held.
@export var grip_lateral_friction: float = 7.5
## UE DriftSteeringRateMultiplier 1.35.
@export var drift_steering_rate_multiplier: float = 1.35
## Grip input above this value pulls the car out of its default drifty state.
## Equivalent to UE's DriftInputThreshold 0.15 seen through bInvertDriftInput.
@export var grip_input_threshold: float = 0.85
## Lateral slip, in m/s, before a collision counts as a drift hit for combat
## scoring. The is_drifting flag cannot serve here: it is true by default, so it
## would hand out the drift bonus on every hit ever landed.
@export var slip_for_drift_bonus: float = 5.0

@export_group("Reverse")
## UE bEnableInputRelativeReverseSteering.
@export var enable_input_relative_reverse_steering: bool = true
## UE ReverseSteeringEnterSpeed 120 cm/s.
@export var reverse_steering_enter_speed: float = 1.2
## UE ReverseSteeringExitSpeed 70 cm/s. Lower than enter speed, for hysteresis.
@export var reverse_steering_exit_speed: float = 0.7

## UE ECaddyVehicleCollisionResponseMode.
enum ResponseMode {
	SLIDE_ONLY,
	ARCADE_WALL_GLIDE,
}

@export_group("Collision")
## UE ResponseMode. ArcadeWallGlide deliberately discards physical response and
## converts impacts into a steerable slide along the wall.
@export var collision_response_mode: ResponseMode = ResponseMode.ARCADE_WALL_GLIDE
## UE MaxCollisionIterations 2.
@export var max_collision_iterations: int = 2
## UE SpeedRetainRatio 0.62.
@export var speed_retain_ratio: float = 0.62
## UE WallGlideVelocityInterpSpeed 14.
@export var wall_glide_velocity_interp_speed: float = 14.0
## UE WallGlideInputAssist 0.45. How far move intent can bend the glide.
@export var wall_glide_input_assist: float = 0.45
## UE MinNormalImpactSpeedForGlide 140 cm/s. Below this an impact just slides.
@export var min_normal_impact_speed_for_glide: float = 1.4
## UE MinWallGlideSpeed 260 cm/s. Floor so a hard hit never stops the car dead.
@export var min_wall_glide_speed: float = 2.6
## UE HeadOnGlideSpeedScale 0.50. Converts head-on impact speed into tangent speed.
@export var head_on_glide_speed_scale: float = 0.5
## UE PushOutDistance 3 cm. Separation nudge to stop sticky wall contact.
@export var push_out_distance: float = 0.03
