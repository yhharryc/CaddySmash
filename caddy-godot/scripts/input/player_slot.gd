class_name PlayerSlot
extends RefCounted
## One joined local player: which seat they took and what they are holding.

## Seat colours, in join order. Also tints the car body.
const COLORS: Array[Color] = [
	Color(0.20, 0.55, 0.90),  # P1 blue
	Color(0.85, 0.30, 0.35),  # P2 red
	Color(0.35, 0.80, 0.40),  # P3 green
	Color(0.95, 0.80, 0.25),  # P4 yellow
]

## 0-based seat. Player number shown to the user is index + 1.
var index: int = 0
var device: InputDevice = null


static func make(seat_index: int, seat_device: InputDevice) -> PlayerSlot:
	var slot := PlayerSlot.new()
	slot.index = seat_index
	slot.device = seat_device
	return slot


func color() -> Color:
	return COLORS[clampi(index, 0, COLORS.size() - 1)]


func label() -> String:
	return "P%d" % (index + 1)


func describe() -> String:
	return "%s  %s" % [label(), device.display_name() if device != null else "unassigned"]
