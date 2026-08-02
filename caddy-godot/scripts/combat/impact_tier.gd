class_name ImpactTier
extends RefCounted
## Collision severity, ported from EHRVehicleCollisionImpactTier.
##
## This lives in its own script rather than on ImpactAdjudicator so the enum can
## be shared without ImpactEvent and ImpactAdjudicator depending on each other.
## GDScript resolves cyclic class_name dependencies badly — the analyser can spin
## and eat memory rather than reporting an error — so keep shared types leaf-level.

enum Value {
	NONE,
	LIGHT,
	MEDIUM,
	HEAVY,
}

const NAMES := ["none", "light", "medium", "heavy"]


static func name_of(tier: Value) -> String:
	return NAMES[clampi(int(tier), 0, NAMES.size() - 1)]
