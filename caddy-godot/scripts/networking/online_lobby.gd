extends Control
## Online lobby: host or join a Steam session, see who is in, start the match.
##
## Built in code like the join screen. Mouse-driven, since Steam's own overlay
## and lobby codes are mouse-and-keyboard affairs anyway. The device that drives
## this machine's car can still be switched here: press A on a pad or Enter on
## the keyboard.

const LOCAL_SCENE := "res://scenes/join_screen.tscn"
## Friends' lobbies are polled from Steam, not pushed, so refresh on a timer.
const FRIEND_REFRESH_SECONDS := 3.0

@onready var _root: VBoxContainer = $Root

var _steam_label: Label
var _status_label: Label
var _code_label: Label
var _copy_button: Button
var _host_button: Button
var _invite_button: Button
var _leave_button: Button
var _code_input: LineEdit
var _join_button: Button
var _members_box: VBoxContainer
var _friends_box: VBoxContainer
var _device_label: Label
var _start_button: Button

var _previous_join := {}
var _friend_refresh := 0.0


func _ready() -> void:
	_build()
	NetworkManager.lobby_changed.connect(_refresh)
	NetworkManager.status_changed.connect(_on_status_changed)
	_on_status_changed(NetworkManager.status)
	_refresh()
	_refresh_friends()


func _process(delta: float) -> void:
	_poll_device_switch()
	_friend_refresh += delta
	if _friend_refresh >= FRIEND_REFRESH_SECONDS:
		_friend_refresh = 0.0
		_refresh_friends()


func _poll_device_switch() -> void:
	# Enter belongs to the lobby code box while it is being typed in.
	var typing := _code_input.has_focus()
	for device in InputDevice.connected_devices():
		if typing and device.is_keyboard():
			continue
		var key := "%d:%d" % [device.kind, device.device_id]
		var held := device.is_join_pressed()
		var was_held: bool = _previous_join.get(key, false)
		_previous_join[key] = held
		if held and not was_held and not device.matches(NetworkManager.local_device):
			NetworkManager.local_device = device
			_refresh_device()


# ---------------------------------------------------------------------------
# Layout
# ---------------------------------------------------------------------------

func _build() -> void:
	var title := Label.new()
	title.text = "ONLINE  ·  STEAM"
	title.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	title.add_theme_font_size_override("font_size", 44)
	_root.add_child(title)

	_steam_label = _label(14, Color(0.6, 0.65, 0.75))
	_status_label = _label(18, Color(0.95, 0.85, 0.5))

	var session_row := _row()
	_host_button = _button(session_row, "Host lobby", NetworkManager.host_lobby)
	_invite_button = _button(session_row, "Invite friends", NetworkManager.invite_friends)
	_leave_button = _button(session_row, "Leave lobby", NetworkManager.leave_lobby)

	var code_row := _row()
	_code_label = Label.new()
	_code_label.add_theme_font_size_override("font_size", 14)
	code_row.add_child(_code_label)
	_copy_button = _button(code_row, "Copy code", _copy_code)

	var join_row := _row()
	_code_input = LineEdit.new()
	_code_input.placeholder_text = "Paste a lobby code"
	_code_input.custom_minimum_size = Vector2(280, 0)
	_code_input.text_submitted.connect(func(_text: String) -> void: _join_by_code())
	join_row.add_child(_code_input)
	_join_button = _button(join_row, "Join", _join_by_code)

	var columns := _row()
	columns.add_theme_constant_override("separation", 40)
	_members_box = _column(columns, "IN THIS LOBBY")
	_friends_box = _column(columns, "FRIENDS PLAYING")

	_device_label = _label(14, Color(0.7, 0.75, 0.85))

	var action_row := _row()
	_start_button = _button(action_row, "Start match", NetworkManager.start_match)
	_start_button.custom_minimum_size = Vector2(220, 48)
	_button(action_row, "Back", _back)


func _label(font_size: int, color: Color) -> Label:
	var label := Label.new()
	label.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	label.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
	label.add_theme_font_size_override("font_size", font_size)
	label.add_theme_color_override("font_color", color)
	_root.add_child(label)
	return label


func _row() -> HBoxContainer:
	var row := HBoxContainer.new()
	row.alignment = BoxContainer.ALIGNMENT_CENTER
	row.add_theme_constant_override("separation", 12)
	_root.add_child(row)
	return row


func _column(parent: Container, heading: String) -> VBoxContainer:
	var panel := PanelContainer.new()
	panel.custom_minimum_size = Vector2(320, 190)
	parent.add_child(panel)

	var column := VBoxContainer.new()
	column.add_theme_constant_override("separation", 6)
	panel.add_child(column)

	var title := Label.new()
	title.text = heading
	title.add_theme_font_size_override("font_size", 13)
	title.add_theme_color_override("font_color", Color(0.55, 0.6, 0.7))
	column.add_child(title)

	var entries := VBoxContainer.new()
	column.add_child(entries)
	return entries


func _button(parent: Container, text: String, action: Callable) -> Button:
	var button := Button.new()
	button.text = text
	button.custom_minimum_size = Vector2(150, 40)
	button.pressed.connect(action)
	parent.add_child(button)
	return button


# ---------------------------------------------------------------------------
# State
# ---------------------------------------------------------------------------

func _refresh() -> void:
	var steam_ok := NetworkManager.steam_ready
	var in_lobby := NetworkManager.is_in_lobby()
	var hosting := NetworkManager.is_host()

	_steam_label.text = (
		"Signed in as %s" % NetworkManager.steam_name if steam_ok else "Steam unavailable"
	)
	_host_button.disabled = not steam_ok or in_lobby
	_invite_button.disabled = not in_lobby
	_leave_button.disabled = not in_lobby
	_join_button.disabled = not steam_ok
	_code_input.editable = steam_ok

	_code_label.text = "Lobby code: %d" % NetworkManager.lobby_id if in_lobby else "Not in a lobby"
	_copy_button.visible = in_lobby

	_start_button.visible = hosting
	_start_button.disabled = not NetworkManager.can_start_match()

	for child in _members_box.get_children():
		child.queue_free()
	var seat := 0
	for member in NetworkManager.lobby_members():
		var line := Label.new()
		var connected: bool = member["peer_id"] > 0
		line.text = "%s%s%s%s" % [
			member["name"],
			"  (host)" if member["is_host"] else "",
			"  (you)" if member["is_self"] else "",
			"" if connected else "  connecting...",
		]
		if connected and seat < PlayerSlot.COLORS.size():
			line.add_theme_color_override("font_color", PlayerSlot.COLORS[seat])
			seat += 1
		_members_box.add_child(line)

	_refresh_device()


func _refresh_friends() -> void:
	for child in _friends_box.get_children():
		child.queue_free()
	var friends := NetworkManager.friends_in_lobbies()
	if friends.is_empty():
		var none := Label.new()
		none.text = "No friends in a lobby right now."
		none.add_theme_color_override("font_color", Color(0.5, 0.52, 0.58))
		_friends_box.add_child(none)
		return
	for friend in friends:
		var lobby: int = friend["lobby_id"]
		_button(_friends_box, "Join %s" % friend["name"], func() -> void: NetworkManager.join_lobby(lobby))


func _refresh_device() -> void:
	_device_label.text = (
		"You drive with: %s    (A on a pad / Enter on the keyboard to switch)"
		% NetworkManager.local_device.display_name()
	)


func _on_status_changed(text: String) -> void:
	_status_label.text = text


func _join_by_code() -> void:
	var code := _code_input.text.strip_edges()
	if code.is_valid_int():
		NetworkManager.join_lobby(code.to_int())
		_code_input.release_focus()


func _copy_code() -> void:
	DisplayServer.clipboard_set(str(NetworkManager.lobby_id))


func _back() -> void:
	NetworkManager.leave_lobby()
	get_tree().change_scene_to_file(LOCAL_SCENE)
