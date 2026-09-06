class_name CombatTuning
extends Resource
## Target-side combat config. Collapses three Unreal sources:
## UCaddyVehicleAttributeSet defaults (via ACaddyVehiclePawn), the tier tables in
## UCaddyVehicleKnockbackAbility, and the tier tables in UCaddyVehicleStaggerAbility.
##
## Knockback speeds converted from cm/s to m/s; durations and spins unchanged.

@export_group("Attributes")
## UE DefaultMaxHealth was 100; raised 10x for longer fights.
@export var max_health: float = 1000.0
## UE DefaultKnockbackResistance 0. Scales knockback speed by (1 - resistance).
@export_range(0.0, 0.95) var knockback_resistance: float = 0.0

@export_group("Knockback - Light")
## UE LightKnockback.OverrideSpeed 620 cm/s.
@export var light_knockback_speed: float = 12.0
## UE LightKnockback.OverrideDuration 0.12.
@export var light_knockback_duration: float = 0.21
## UE LightKnockback.CarryVelocityRatio 0.12.
@export var light_knockback_carry: float = 0.14

@export_group("Knockback - Medium")
## UE MediumKnockback.OverrideSpeed 950 cm/s.
@export var medium_knockback_speed: float = 16.0
## UE MediumKnockback.OverrideDuration 0.16.
@export var medium_knockback_duration: float = 0.24
## UE MediumKnockback.CarryVelocityRatio 0.16.
@export var medium_knockback_carry: float = 0.18

@export_group("Knockback - Heavy")
## UE HeavyKnockback.OverrideSpeed 1320 cm/s.
@export var heavy_knockback_speed: float = 21.0
## UE HeavyKnockback.OverrideDuration 0.22.
@export var heavy_knockback_duration: float = 0.28
## UE HeavyKnockback.CarryVelocityRatio 0.20.
@export var heavy_knockback_carry: float = 0.22

@export_group("Stagger - Light")
## UE LightTier.DurationSeconds 0.35.
@export var light_stagger_duration: float = 0.2
## UE LightTier.Spins 1. Cosmetic; consumed by the feel layer.
@export var light_stagger_spins: int = 1
## UE LightTier.InputLockSeconds 0.35.
@export var light_stagger_input_lock: float = 0.2

@export_group("Stagger - Medium")
## UE MediumTier.DurationSeconds 0.55.
@export var medium_stagger_duration: float = 0.3
## UE MediumTier.Spins 2.
@export var medium_stagger_spins: int = 2
## UE MediumTier.InputLockSeconds 0.55.
@export var medium_stagger_input_lock: float = 0.3

@export_group("Stagger - Heavy")
## UE HeavyTier.DurationSeconds 0.8.
@export var heavy_stagger_duration: float = 0.45
## UE HeavyTier.Spins 3.
@export var heavy_stagger_spins: int = 3
## UE HeavyTier.InputLockSeconds 0.8.
@export var heavy_stagger_input_lock: float = 0.45
