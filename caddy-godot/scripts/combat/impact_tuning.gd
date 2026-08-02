class_name ImpactTuning
extends Resource
## Port of UHRN_AdjudicateVehicleCollision plus the emission gates that lived in
## FCaddyVehicleCollisionHitRegisterConfig and UHRN_EmitVehicleCollisionGameplayEvents.
##
## Speed thresholds converted from cm/s to m/s. Note damage_by_normal_impact_speed:
## UE's 0.012 was per cm/s, so it becomes 1.2 per m/s for identical damage.

@export_group("Gates")
## UE MinSpeedForEvent 550 cm/s.
@export var min_speed_for_event: float = 5.5
## UE MinNormalImpactSpeedForEvent 180 cm/s.
@export var min_normal_impact_speed_for_event: float = 1.8
## UE EventCooldownSeconds 0.2.
@export var event_cooldown_seconds: float = 0.2
## UE bRequireVehicleTarget. Walls score nothing; only cars fight.
@export var require_vehicle_target: bool = true
## UE bStopIfBelowLightThreshold.
@export var stop_if_below_light_threshold: bool = true

@export_group("Scoring")
## UE bUseRelativeNormalImpactSpeed: score off closing speed against a moving target.
@export var use_relative_normal_impact_speed: bool = true
## UE ImpactScoreScale 1.0.
@export var impact_score_scale: float = 1.0
## UE LightImpactScoreThreshold 280 cm/s.
@export var light_score_threshold: float = 2.8
## UE MediumImpactScoreThreshold 620 cm/s.
@export var medium_score_threshold: float = 6.2
## UE HeavyImpactScoreThreshold 980 cm/s.
@export var heavy_score_threshold: float = 9.8
## UE DriftingImpactMultiplier 1.10 - sliding into someone hits harder.
@export var drifting_impact_multiplier: float = 1.1
## UE SkillDashImpactMultiplier 1.60 - the dash is the payoff move.
@export var skill_dash_impact_multiplier: float = 1.6

@export_group("Damage")
## UE DamageByNormalImpactSpeed 0.012 per cm/s.
@export var damage_by_normal_impact_speed: float = 1.2
## UE DamageBias 0.0.
@export var damage_bias: float = 0.0
## UE LightDamageMultiplier 0.65.
@export var light_damage_multiplier: float = 0.65
## UE MediumDamageMultiplier 1.0.
@export var medium_damage_multiplier: float = 1.0
## UE HeavyDamageMultiplier 1.55.
@export var heavy_damage_multiplier: float = 1.55
## UE MinFinalDamage. Reactions only fire above this.
@export var min_final_damage: float = 0.0001
## UE bRequirePositiveFinalDamage.
@export var require_positive_final_damage: bool = true

@export_group("Clash")
## UE bEnableHeadOnClashTag.
@export var enable_head_on_clash: bool = true
## UE ClashFacingDotThreshold 0.60 - how nose-to-nose the cars must be.
@export var clash_facing_dot_threshold: float = 0.6
## UE ClashSpeedRatioThreshold 0.70 - both cars must be committed, not one rolling.
@export var clash_speed_ratio_threshold: float = 0.7
## UE ClashMinRelativeNormalSpeed 600 cm/s.
@export var clash_min_relative_normal_speed: float = 6.0

@export_group("Reactions")
## UE bEmitKnockbackGameplayEvent.
@export var emit_knockback: bool = true
## UE bEmitStaggerGameplayEvent.
@export var emit_stagger: bool = true
## UE bStaggerOnLightImpact false.
@export var stagger_on_light: bool = false
## UE bStaggerOnMediumImpact true.
@export var stagger_on_medium: bool = true
## UE bStaggerOnHeavyImpact true.
@export var stagger_on_heavy: bool = true
