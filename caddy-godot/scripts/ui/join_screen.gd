extends Control
## Controller select. Any keyboard or gamepad can claim a seat; the roster is
## handed to the arena through the PlayerRoster autoload.
##
## Devices are polled directly rather than through the InputMap, because the
## whole point of this screen is telling one pad apart from another.

const MATCH_SCENE := "res://scenes/arena_match.tscn"
const ONLINE_SCENE := "res://scenes/online_lobby.tscn"
## At least this many seats filled before the match can start. One is allowed so
## the arena can be tested solo.
const MIN_PLAYERS := 1

@onready var _slots_container: HBoxContainer = $Root/Slots
@onready var _hint_label: Label = $Root/Hint

## Held state from the previous frame, keyed by "kind:id", for edge detection.
var _previous_join := {}
var _previous_leave := {}
var _previous_start := {}
var _previous_online := {}

var _slot_panels: Array[PanelContainer] = []
var _slot_labels: Array[Label] = []
var _slot_devices: Array[Label] = []


func _ready() -> void:
	PlayerRoster.clear()
	_build_slot_widgets()
	_refresh()


func _process(_delta: float) -> void:
	if PlayerRoster.prune_disconnected() > 0:
		_refresh()
	_poll_devices()


func _poll_devices() -> void:
	var changed := false

	for device in InputDevice.connected_devices():
		var key := _device_key(device)
		var joined := PlayerRoster.has_device(device)

		if _just_pressed(_previous_join, key, device.is_join_pressed()) and not joined:
			if PlayerRoster.join(device) != null:
				changed = true

		if _just_pressed(_previous_leave, key, device.is_leave_pressed()) and joined:
			if PlayerRoster.leave(device):
				changed = true

		# Only someone already in the match can start it.
		if _just_pressed(_previous_start, key, device.is_start_pressed()) and joined:
			if PlayerRoster.count() >= MIN_PLAYERS:
				_start_match()
				return

		# Whoever opens the online lobby is the device that drives online.
		if _just_pressed(_previous_online, key, device.is_online_pressed()):
			NetworkManager.local_device = device
			get_tree().change_scene_to_file(ONLINE_SCENE)
			return

	if changed:
		_refresh()


## Rising-edge test that also stores this frame's state for the next call.
func _just_pressed(cache: Dictionary, key: String, held: bool) -> bool:
	var was_held: bool = cache.get(key, false)
	cache[key] = held
	return held and not was_held


func _device_key(device: InputDevice) -> String:
	return "%d:%d" % [device.kind, device.device_id]


func _start_match() -> void:
	get_tree().change_scene_to_file(MATCH_SCENE)


func _build_slot_widgets() -> void:
	for i in PlayerRoster.MAX_PLAYERS:
		var panel := PanelContainer.new()
		panel.custom_minimum_size = Vector2(190, 210)

		var column := VBoxContainer.new()
		column.alignment = BoxContainer.ALIGNMENT_CENTER
		column.add_theme_constant_override("separation", 10)
		panel.add_child(column)

		var title := Label.new()
		title.text = "P%d" % (i + 1)
		title.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
		title.add_theme_font_size_override("font_size", 40)
		title.add_theme_color_override("font_color", PlayerSlot.COLORS[i])
		column.add_child(title)

		var status := Label.new()
		status.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
		status.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
		column.add_child(status)

		var device_label := Label.new()
		device_label.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
		device_label.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
		device_label.add_theme_font_size_override("font_size", 12)
		column.add_child(device_label)

		_slots_container.add_child(panel)
		_slot_panels.append(panel)
		_slot_labels.append(status)
		_slot_devices.append(device_label)


func _refresh() -> void:
	for i in PlayerRoster.MAX_PLAYERS:
		var slot := _slot_for_index(i)
		if slot != null:
			_slot_labels[i].text = "JOINED"
			_slot_labels[i].add_theme_color_override("font_color", PlayerSlot.COLORS[i])
			_slot_devices[i].text = slot.device.display_name()
			_slot_panels[i].modulate = Color(1, 1, 1, 1)
		else:
			_slot_labels[i].text = "open"
			_slot_labels[i].add_theme_color_override("font_color", Color(0.6, 0.63, 0.7))
			_slot_devices[i].text = ""
			_slot_panels[i].modulate = Color(1, 1, 1, 0.45)

	if PlayerRoster.count() >= MIN_PLAYERS:
		_hint_label.text = (
			"A / Enter to join    B / Esc to leave\nSTART / Space to begin  (%d joined)"
			% PlayerRoster.count()
		)
	else:
		_hint_label.text = "Press A on a controller, or Enter on the keyboard, to join"
	_hint_label.text += "\nY / O to play online over Steam"


func _slot_for_index(index: int) -> PlayerSlot:
	for slot in PlayerRoster.players:
		if slot.index == index:
			return slot
	return null
