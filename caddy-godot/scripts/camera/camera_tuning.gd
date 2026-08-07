class_name CameraTuning
extends Resource
## Port of FCaddyVehicleCameraConfig, plus the group-framing and shake settings
## the local-multiplayer arena needs.
##
## A Resource rather than node exports so the debug panel can edit it live and
## write it back to disk like every other tuning asset.

@export_group("Base")
## UE BaseArmLength 1400 cm. Ignored while fit_ground_radius is set.
@export var base_arm_length: float = 14.0
## UE BasePitchDeg -72. Near -90 is straight down.
@export var base_pitch_deg: float = -85.0
## UE BaseFOV 90.
@export var base_fov: float = 90.0

@export_group("Anchor")
## 0 chases the cars, 1 locks the shot to the anchor. Above 0 also fades out
## look-ahead, which is a chase behaviour and fights a steady frame.
@export_range(0.0, 1.0) var center_bias: float = 1.0
## When > 0, arm length is solved to fit this ground radius instead of using
## base_arm_length plus the speed and spread offsets.
@export var fit_ground_radius: float = 30.0

@export_group("Speed")
## UE MaxSpeedForEffects 2200 cm/s.
@export var max_speed_for_effects: float = 22.0
## UE MaxSpeedPitchOffsetDeg 6.5.
@export var max_speed_pitch_offset_deg: float = 6.5
## UE MaxSpeedArmLengthOffset 120 cm.
@export var max_speed_arm_length_offset: float = 1.2
## UE MaxSpeedFOVOffset 8.
@export var max_speed_fov_offset: float = 8.0

@export_group("Look ahead")
## UE LookAheadDistance 180 cm.
@export var look_ahead_distance: float = 1.8
## UE LookAheadInterpSpeed 4.
@export var look_ahead_interp_speed: float = 4.0

@export_group("Roll")
## UE MaxLateralRollDeg 7.5.
@export var max_lateral_roll_deg: float = 7.5
## UE LateralSpeedForMaxRoll 900 cm/s.
@export var lateral_speed_for_max_roll: float = 9.0
## UE RollInterpSpeed 6.
@export var roll_interp_speed: float = 6.0

@export_group("Lag")
@export var enable_camera_lag: bool = true
## UE CameraLagSpeedAtLowSpeed 12. Higher tracks tighter.
@export var camera_lag_speed_at_low_speed: float = 12.0
## UE CameraLagSpeedAtHighSpeed 7.
@export var camera_lag_speed_at_high_speed: float = 7.0
## UE CameraLagMaxDistance 340 cm.
@export var camera_lag_max_distance: float = 3.4

@export_group("Group framing")
## Extra arm length per metre of spread. Only used when fit_ground_radius is 0.
@export var spread_zoom_scale: float = 0.55
@export var max_spread_arm_length: float = 22.0

@export_group("Shake")
@export var enable_shake: bool = true
## Peak positional shake in metres at full trauma.
@export var max_shake_offset: float = 1.1
## Peak shake roll in degrees at full trauma.
@export var max_shake_roll_deg: float = 3.5
## Trauma lost per second. Higher settles faster.
@export var trauma_decay: float = 1.9
## How fast the noise scrolls. Higher is more jittery, lower is more of a sway.
@export var shake_frequency: float = 22.0

@export_group("Smoothing")
## UE TransformInterpSpeed 4.
@export var transform_interp_speed: float = 4.0
