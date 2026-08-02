class_name ImpactEvent
extends RefCounted
## Adjudicated result of one vehicle-on-vehicle collision.
##
## This is what UE's HitRegister context held after HRN_AdjudicateVehicleCollision
## ran: raw collision numbers turned into a tier, a score and a damage figure.

var attacker: ArcadeVehicle = null
var target: ArcadeVehicle = null
var tier: ImpactTier.Value = ImpactTier.Value.NONE
## UE Attr.Collision.ImpactScore.
var impact_score := 0.0
## UE Attr.Collision.EffectiveNormalImpactSpeed.
var effective_normal_speed := 0.0
var damage := 0.0
## UE Hit.Collision.Clash: both cars head-on, both fast, both committed.
var is_clash := false
var normal := Vector3.ZERO
var position := Vector3.ZERO
var was_drifting := false
var was_skill_dashing := false
## Reaction gates. Decided by the attacker's tuning, matching UE where the emit
## node sat in the attacker's HitRegister pipeline.
var apply_knockback := false
var apply_stagger := false


func describe() -> String:
	return (
		"%s -> %s  %s score %.1f dmg %.1f%s"
		% [
			attacker.name if attacker != null else "?",
			target.name if target != null else "?",
			ImpactTier.name_of(tier),
			impact_score,
			damage,
			" CLASH" if is_clash else "",
		]
	)
