class_name Easing
extends RefCounted
## Easing curves for the feel layer.
##
## Nothing here is linear on purpose. A linear scale change reads as a glitch —
## the eye sees the start and stop as hard edges. Every effect either accelerates
## into its extreme and decelerates out, or overshoots and settles.

## Decelerates into the target. Good for the attack of a hit: instant, then soft.
static func out_cubic(t: float) -> float:
	var x := clampf(t, 0.0, 1.0)
	return 1.0 - pow(1.0 - x, 3.0)


## Accelerates out, decelerates in. The default for anything settling back.
static func in_out_cubic(t: float) -> float:
	var x := clampf(t, 0.0, 1.0)
	if x < 0.5:
		return 4.0 * x * x * x
	return 1.0 - pow(-2.0 * x + 2.0, 3.0) * 0.5


## Overshoots past the target then settles. Gives scale pops their snap.
static func out_back(t: float, overshoot: float = 1.70158) -> float:
	var x := clampf(t, 0.0, 1.0)
	var c := overshoot + 1.0
	return 1.0 + c * pow(x - 1.0, 3.0) + overshoot * pow(x - 1.0, 2.0)


## Springs past the target and oscillates down. For the biggest impacts only.
static func out_elastic(t: float) -> float:
	var x := clampf(t, 0.0, 1.0)
	if is_zero_approx(x) or is_equal_approx(x, 1.0):
		return x
	return pow(2.0, -10.0 * x) * sin((x * 10.0 - 0.75) * (TAU / 3.0)) + 1.0


## One-shot envelope: 0 -> 1 -> 0 across t, eased at both ends.
## `attack` is the fraction spent rising, so a small value snaps in and drifts out.
static func pulse(t: float, attack: float = 0.18) -> float:
	var x := clampf(t, 0.0, 1.0)
	var a := clampf(attack, 0.01, 0.99)
	if x < a:
		return out_cubic(x / a)
	return in_out_cubic(1.0 - (x - a) / (1.0 - a))


## Same shape, but the rise overshoots. Use where the pop should read as impact.
static func pulse_back(t: float, attack: float = 0.18) -> float:
	var x := clampf(t, 0.0, 1.0)
	var a := clampf(attack, 0.01, 0.99)
	if x < a:
		return out_back(x / a)
	return in_out_cubic(1.0 - (x - a) / (1.0 - a))
