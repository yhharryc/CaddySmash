class_name SkillTuning
extends Resource
## Port of FCaddyVehicleBrakeDashSkillConfig (UCaddyVehicleSkillConfigDataAsset).
##
## Speeds converted from cm/s to m/s; durations and ratios carry over unchanged.

## UE ECaddyVehicleSkillTriggerMode.
enum TriggerMode {
	INPUT_HOLD,
	## Throttle and brake both held past their thresholds: the handbrake-turn gesture.
	BRAKE_THROTTLE_COMBO,
}

## UE ECaddyVehicleSkillAimSelectionMode.
enum AimSelectionMode {
	INPUT_ONLY,
	TARGET_ONLY,
	TARGET_PREFER_INPUT_FALLBACK,
}

@export_group("Trigger")
@export var enable_brake_dash: bool = true
@export var trigger_mode: TriggerMode = TriggerMode.INPUT_HOLD
## UE TriggerThrottleThreshold 0.85.
@export var trigger_throttle_threshold: float = 0.85
## UE TriggerBrakeThreshold 0.85.
@export var trigger_brake_threshold: float = 0.85
## UE TriggerInputHoldSeconds 0.02.
@export var trigger_input_hold_seconds: float = 0.02
## UE CooldownSeconds 2.0.
@export var cooldown_seconds: float = 2.0

@export_group("Brake")
## UE BrakeDuration 0.34.
@export var brake_duration: float = 0.34
## UE BrakeSpeedAlphaCurve. Falls back to pow(1 - t, 2.2): sharp bite, soft settle.
@export var brake_speed_alpha_curve: Curve

@export_group("Charge")
## UE MaxChargeSeconds 1.0. Holding past this auto-fires.
@export var max_charge_seconds: float = 1.0
## UE MinChargeSeconds 0.0.
@export var min_charge_seconds: float = 0.0
## UE ChargeAlphaCurve. Falls back to linear hold alpha.
@export var charge_alpha_curve: Curve
## UE AimInputDeadZone 0.10.
@export var aim_input_dead_zone: float = 0.1
## UE bRotateOwnerToAimDuringCharge.
@export var rotate_to_aim_during_charge: bool = true
## UE AimRotationRateDegPerSec 900. Applies at zero velocity, unlike normal steering.
@export var aim_rotation_rate_deg: float = 900.0

@export_group("Dash")
## UE DashDurationAtMinCharge 0.22.
@export var dash_duration_at_min_charge: float = 0.22
## UE DashDurationAtMaxCharge 0.42.
@export var dash_duration_at_max_charge: float = 0.42
## UE DashPeakSpeedAtMinCharge 2600 cm/s.
@export var dash_peak_speed_at_min_charge: float = 26.0
## UE DashPeakSpeedAtMaxCharge 4200 cm/s.
@export var dash_peak_speed_at_max_charge: float = 42.0
## UE DashSpeedAlphaCurve. Falls back to InterpEaseInOut(1, 0, t, 1.6).
@export var dash_speed_alpha_curve: Curve
## UE PostDashCarryRatio 0.30. Fraction of peak speed handed back to normal driving.
@export var post_dash_carry_ratio: float = 0.3

@export_group("Targeting")
## UE bEnableAbilityTargeting. Off by default, matching the Unreal config.
@export var enable_targeting: bool = false
@export var aim_selection_mode: AimSelectionMode = AimSelectionMode.TARGET_PREFER_INPUT_FALLBACK
## UE TraceDistance 1800 cm.
@export var trace_distance: float = 18.0
## UE TraceRadius 120 cm.
@export var trace_radius: float = 1.2
@export_flags_3d_physics var trace_mask: int = 1
## Stands in for UE's UHitRegisterTargetingProfile: candidates must be in this
## group. Empty accepts anything the sweep hits.
@export var target_group: StringName = &""
