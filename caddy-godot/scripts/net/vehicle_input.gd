class_name VehicleInput
extends RefCounted
## One frame of a driver's intent, as data.
##
## The point of this existing at all is the pivot to client prediction. Input has
## to be a value that can be recorded, sent, and **replayed** — a driver calling
## setters directly cannot be replayed, so prediction would be a rewrite. With
## this, prediction is "keep the last N of these and re-run them".
##
## The stick is sent raw rather than as a world direction: the conversion in
## ArcadeVehicle.set_move_intent_from_stick goes through the arena camera rig,
## whose yaw is world-fixed at 0 and therefore identical on every machine.

## Physics frame this input belongs to. Engine.get_physics_frames() is already a
## monotonic per-process counter, so it serves until the session hands out an
## agreed tick.
var tick: int = 0
## Raw stick, x = right, y = forward. Dead zone applied downstream.
var move_stick := Vector2.ZERO
var throttle := 0.0
var brake := 0.0
## 0 is the car's default drifty state, 1 is full grip.
var grip := 0.0
var skill_pressed := false


static func make(
	p_tick: int,
	p_stick: Vector2,
	p_throttle: float,
	p_brake: float,
	p_grip: float,
	p_skill: bool
) -> VehicleInput:
	var input := VehicleInput.new()
	input.tick = p_tick
	input.move_stick = p_stick
	input.throttle = p_throttle
	input.brake = p_brake
	input.grip = p_grip
	input.skill_pressed = p_skill
	return input


## Short keys: this goes out unreliably every physics frame, per player.
func to_dict() -> Dictionary:
	return {
		"t": tick,
		"s": move_stick,
		"th": throttle,
		"b": brake,
		"g": grip,
		"k": skill_pressed,
	}


static func from_dict(data: Dictionary) -> VehicleInput:
	return VehicleInput.make(
		int(data.get("t", 0)),
		data.get("s", Vector2.ZERO),
		float(data.get("th", 0.0)),
		float(data.get("b", 0.0)),
		float(data.get("g", 0.0)),
		bool(data.get("k", false))
	)


func copy() -> VehicleInput:
	return VehicleInput.make(tick, move_stick, throttle, brake, grip, skill_pressed)


## Ignores the tick: this asks whether the driver did the same thing, which is
## what matters when deciding a resend is redundant.
func matches(other: VehicleInput) -> bool:
	return (
		other != null
		and move_stick.is_equal_approx(other.move_stick)
		and is_equal_approx(throttle, other.throttle)
		and is_equal_approx(brake, other.brake)
		and is_equal_approx(grip, other.grip)
		and skill_pressed == other.skill_pressed
	)


func describe() -> String:
	return (
		"t%d stick(%.2f, %.2f) thr %.2f brk %.2f grip %.2f%s"
		% [tick, move_stick.x, move_stick.y, throttle, brake, grip, "  SKILL" if skill_pressed else ""]
	)
