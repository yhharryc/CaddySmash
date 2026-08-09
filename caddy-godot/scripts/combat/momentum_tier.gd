class_name MomentumTier
extends RefCounted
## The three momentum states a car can be in. Higher tier wins a contest.
##
## Leaf script with no dependencies, like impact_tier.gd. Cyclic class_name
## dependencies make GDScript's analyser spin rather than error (see PORTING.md),
## so shared enums live on their own.

enum Value {
	LOW,
	MID,
	HIGH,
}

const NAMES := ["low", "mid", "high"]

## Outline colours. Deliberately far apart in hue and brightness so the tier is
## legible at arena zoom, before the crash rather than after it.
const COLORS: Array[Color] = [
	Color(0.55, 0.60, 0.70),  # LOW  - dull steel, reads as "not a threat"
	Color(1.00, 0.72, 0.20),  # MID  - amber
	Color(1.00, 0.30, 0.85),  # HIGH - hot magenta
]


static func name_of(tier: Value) -> String:
	return NAMES[clampi(int(tier), 0, NAMES.size() - 1)]


static func color_of(tier: Value) -> Color:
	return COLORS[clampi(int(tier), 0, COLORS.size() - 1)]
