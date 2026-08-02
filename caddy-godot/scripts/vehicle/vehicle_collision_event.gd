class_name VehicleCollisionEvent
extends RefCounted
## Payload for ArcadeVehicle.blocking_collision.
##
## Carries the same values UE packed into the HitRegister FAttackRequest
## attributes (Attr.Collision.*), so the combat layer can be built on this
## without the vehicle needing to know anything about damage.

var collider: Object = null
var position := Vector3.ZERO
## Surface normal, flattened to the ground plane.
var normal := Vector3.ZERO
## Direction the car glides off along after the impact.
var tangent := Vector3.ZERO
## Attacker planar speed just before impact. UE Attr.Collision.TotalSpeed.
var total_speed := 0.0
## Closing speed into the surface. UE Attr.Collision.NormalImpactSpeed.
var normal_impact_speed := 0.0
## Closing speed measured against a moving target. UE Attr.Collision.RelativeNormalImpactSpeed.
var relative_normal_speed := 0.0
## UE Attr.Collision.TargetSpeed.
var target_speed := 0.0
## UE Attr.Collision.IsDrifting.
var is_drifting := false
## UE Attr.Collision.TargetIsVehicle.
var target_is_vehicle := false
## UE Attr.Collision.IsSkillDashing.
var is_skill_dashing := false


func describe() -> String:
	return (
		"%s speed %.1f normal %.1f rel %.1f%s%s"
		% [
			collider.name if collider is Node else "<none>",
			total_speed,
			normal_impact_speed,
			relative_normal_speed,
			" drift" if is_drifting else "",
			" dash" if is_skill_dashing else "",
		]
	)
