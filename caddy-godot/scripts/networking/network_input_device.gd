class_name NetworkInputDevice
extends InputDevice
## Input for a car whose player is on another machine.
##
## The host drives remote cars through the same PlayerVehicleDriver as local ones,
## so this stands in for a keyboard or pad: NetMatchSync writes the newest frame
## the owner sent, and the driver polls it like any other device. Nothing on the
## vehicle side knows the input came over the wire.

## Multiplayer peer id of the machine that owns this input.
var peer_id: int = 0
## Steam persona name, shown where a local device would show "Keyboard".
var player_name: String = ""
## The owner's physics tick for the newest frame taken, or -1 before the first.
## NetMatchSync echoes it back in snapshots so the owner knows which of its
## predicted states the host's answer corresponds to.
var latest_tick: int = -1

var _move := Vector2.ZERO
var _throttle := 0.0
var _brake := 0.0
var _grip := 0.0
var _skill := false


static func for_peer(owner_peer_id: int, owner_name: String) -> NetworkInputDevice:
	var device := NetworkInputDevice.new()
	device.kind = Kind.NETWORK
	device.device_id = owner_peer_id
	device.peer_id = owner_peer_id
	device.player_name = owner_name
	return device


## Unreliable packets can arrive late or out of order; anything not newer than
## what is already held is dropped. Returns whether the frame was taken.
func push_frame(tick: int, frame: PackedFloat32Array) -> bool:
	if tick <= latest_tick or frame.size() < NetVehicleState.INPUT_SIZE:
		return false
	latest_tick = tick
	_move = Vector2(
		frame[NetVehicleState.InputField.MOVE_X], frame[NetVehicleState.InputField.MOVE_Y]
	).limit_length(1.0)
	_throttle = clampf(frame[NetVehicleState.InputField.THROTTLE], 0.0, 1.0)
	_brake = clampf(frame[NetVehicleState.InputField.BRAKE], 0.0, 1.0)
	_grip = clampf(frame[NetVehicleState.InputField.GRIP], 0.0, 1.0)
	_skill = frame[NetVehicleState.InputField.SKILL] > 0.5
	return true


## Lets go of everything, e.g. when the owner disconnects mid-match.
func clear() -> void:
	_move = Vector2.ZERO
	_throttle = 0.0
	_brake = 0.0
	_grip = 0.0
	_skill = false


func display_name() -> String:
	return player_name if not player_name.is_empty() else "Peer %d" % peer_id


## Disconnects are reported by the multiplayer peer, not by polling a device.
func is_available() -> bool:
	return true


func get_move_vector() -> Vector2:
	return _move


func get_throttle() -> float:
	return _throttle


func get_brake() -> float:
	return _brake


func get_grip() -> float:
	return _grip


func is_skill_pressed() -> bool:
	return _skill


# Menus are always driven by a local device.

func is_join_pressed() -> bool:
	return false


func is_leave_pressed() -> bool:
	return false


func is_start_pressed() -> bool:
	return false


func is_online_pressed() -> bool:
	return false
