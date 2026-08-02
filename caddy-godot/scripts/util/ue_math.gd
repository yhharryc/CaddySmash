class_name UeMath
extends RefCounted
## Ports of the Unreal FMath interpolation helpers the vehicle code depends on.
##
## Godot's lerp/move_toward are not equivalent: Unreal's FInterpTo is a
## framerate-scaled exponential ease, and FInterpConstantTo is a constant-rate
## move. Reimplementing them exactly keeps the ported tuning values meaningful.


## FMath::FInterpTo - exponential ease toward target. interp_speed is 1/seconds.
static func finterp_to(current: float, target: float, delta: float, interp_speed: float) -> float:
	if interp_speed <= 0.0:
		return target
	var dist := target - current
	if is_zero_approx(dist):
		return target
	return current + dist * clampf(delta * interp_speed, 0.0, 1.0)


## FMath::VInterpTo - vector form of the above.
static func vinterp_to(current: Vector3, target: Vector3, delta: float, interp_speed: float) -> Vector3:
	if interp_speed <= 0.0:
		return target
	var dist := target - current
	if dist.length_squared() < 0.00000001:
		return target
	return current + dist * clampf(delta * interp_speed, 0.0, 1.0)


## FMath::FInterpConstantTo - constant-rate move, equivalent to move_toward.
static func finterp_constant_to(current: float, target: float, delta: float, interp_speed: float) -> float:
	if interp_speed <= 0.0:
		return target
	return move_toward(current, target, interp_speed * delta)


## FMath::InterpEaseInOut - symmetric ease built from pow(alpha, exponent).
static func interp_ease_in_out(from: float, to: float, alpha: float, exponent: float) -> float:
	var a := clampf(alpha, 0.0, 1.0)
	var blend := (
		pow(a * 2.0, exponent) * 0.5
		if a < 0.5
		else (1.0 - pow(2.0 - a * 2.0, exponent)) * 0.5 + 0.5
	)
	return lerpf(from, to, blend)


## Yaw (radians) that points a node's -Z forward axis along the given planar direction.
static func heading_to_yaw(planar_dir: Vector3) -> float:
	return atan2(-planar_dir.x, -planar_dir.z)


## Planar unit direction for a yaw, matching heading_to_yaw.
static func yaw_to_heading(yaw: float) -> Vector3:
	return Vector3(-sin(yaw), 0.0, -cos(yaw))
