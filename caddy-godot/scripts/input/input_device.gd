class_name InputDevice
extends RefCounted
## One physical input source: the keyboard, or a specific gamepad.
##
## Local multiplayer cannot use the InputMap. Actions there aggregate every
## connected device, so Input.get_action_strength("caddy_accelerate") returns
## true when *any* pad pulls the trigger — there is no way to ask "what is
## player 2's pad doing". So gameplay input is polled raw, per device, here.
##
## Only menu/debug actions still go through the InputMap, where aggregation is
## the behaviour you actually want.

enum Kind {
	KEYBOARD,
	GAMEPAD,
}

## Radial dead zone for stick input, matching VehicleTuning.move_intent_dead_zone.
const STICK_DEAD_ZONE := 0.2
## Analog triggers rest slightly above zero on some pads.
const TRIGGER_DEAD_ZONE := 0.08

var kind: Kind = Kind.KEYBOARD
## Godot joypad device id, or -1 for the keyboard.
var device_id: int = -1


static func keyboard() -> InputDevice:
	var device := InputDevice.new()
	device.kind = Kind.KEYBOARD
	device.device_id = -1
	return device


static func gamepad(id: int) -> InputDevice:
	var device := InputDevice.new()
	device.kind = Kind.GAMEPAD
	device.device_id = id
	return device


## Every device currently available to join with.
static func connected_devices() -> Array[InputDevice]:
	var devices: Array[InputDevice] = [keyboard()]
	for id in Input.get_connected_joypads():
		devices.append(gamepad(id))
	return devices


func is_keyboard() -> bool:
	return kind == Kind.KEYBOARD


func matches(other: InputDevice) -> bool:
	return other != null and other.kind == kind and other.device_id == device_id


func display_name() -> String:
	if is_keyboard():
		return "Keyboard"
	var pad_name := Input.get_joy_name(device_id)
	return pad_name if not pad_name.is_empty() else "Gamepad %d" % device_id


## Still connected? A pad can be unplugged mid-match.
func is_available() -> bool:
	return is_keyboard() or Input.get_connected_joypads().has(device_id)


# ---------------------------------------------------------------------------
# Gameplay
# ---------------------------------------------------------------------------

## Stick vector with x = right, y = forward. Already dead-zoned.
func get_move_vector() -> Vector2:
	var raw := Vector2.ZERO
	if is_keyboard():
		raw = Vector2(
			_key_axis(KEY_A, KEY_D),
			_key_axis(KEY_S, KEY_W)
		)
	else:
		raw = Vector2(
			Input.get_joy_axis(device_id, JOY_AXIS_LEFT_X),
			-Input.get_joy_axis(device_id, JOY_AXIS_LEFT_Y)
		)

	# Radial, not per-axis: a per-axis dead zone would clip diagonals.
	if raw.length() < STICK_DEAD_ZONE:
		return Vector2.ZERO
	return raw.limit_length(1.0)


## Space is the dash, so keyboard throttle is Shift only - the two cannot share.
func get_throttle() -> float:
	if is_keyboard():
		return 1.0 if Input.is_physical_key_pressed(KEY_SHIFT) else 0.0
	if Input.is_joy_button_pressed(device_id, JOY_BUTTON_A):
		return 1.0
	return _trigger(JOY_AXIS_TRIGGER_RIGHT)


func get_brake() -> float:
	if is_keyboard():
		return 1.0 if Input.is_physical_key_pressed(KEY_Q) else 0.0
	if Input.is_joy_button_pressed(device_id, JOY_BUTTON_B):
		return 1.0
	return _trigger(JOY_AXIS_TRIGGER_LEFT)


## 0 is the car's default drifty state, 1 is full grip.
func get_grip() -> float:
	if is_keyboard():
		return 1.0 if Input.is_physical_key_pressed(KEY_CTRL) else 0.0
	return 1.0 if Input.is_joy_button_pressed(device_id, JOY_BUTTON_LEFT_SHOULDER) else 0.0


## Brake-dash: Space, or the west face button (X on an Xbox pad).
func is_skill_pressed() -> bool:
	if is_keyboard():
		return Input.is_physical_key_pressed(KEY_SPACE)
	return Input.is_joy_button_pressed(device_id, JOY_BUTTON_X)


# ---------------------------------------------------------------------------
# Menu. Callers do their own edge detection - these report held state.
# ---------------------------------------------------------------------------

func is_join_pressed() -> bool:
	if is_keyboard():
		return Input.is_physical_key_pressed(KEY_ENTER)
	return Input.is_joy_button_pressed(device_id, JOY_BUTTON_A)


func is_leave_pressed() -> bool:
	if is_keyboard():
		return Input.is_physical_key_pressed(KEY_ESCAPE)
	return Input.is_joy_button_pressed(device_id, JOY_BUTTON_B)


func is_start_pressed() -> bool:
	if is_keyboard():
		return Input.is_physical_key_pressed(KEY_SPACE)
	return Input.is_joy_button_pressed(device_id, JOY_BUTTON_START)


func _key_axis(negative: Key, positive: Key) -> float:
	var value := 0.0
	if Input.is_physical_key_pressed(positive):
		value += 1.0
	if Input.is_physical_key_pressed(negative):
		value -= 1.0
	return value


func _trigger(axis: JoyAxis) -> float:
	var value := Input.get_joy_axis(device_id, axis)
	return 0.0 if value < TRIGGER_DEAD_ZONE else clampf(value, 0.0, 1.0)
