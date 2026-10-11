extends Control
## Online lobby: confirm a controller, host or join a Steam session, see who is
## in, start the match.
##
## Built in code like the join screen. Mouse-driven, since Steam's own overlay
## and lobby codes are mouse-and-keyboard affairs anyway.
##
## Confirm first: nothing here works until the player presses A on the pad they
## will play with, or Enter for the keyboard. A Steam invite that arrives before
## that waits, and is joined the moment they confirm (NetworkManager).

const LOCAL_SCENE := "res://scenes/join_screen.tscn"
## Friends' lobbies are polled from Steam, not pushed, so refresh on a timer.
const FRIEND_REFRESH_SECONDS := 3.0

const PROMPT_COLOR := Color(1.0, 0.85, 0.4)
const CONFIRMED_COLOR := Color(0.55, 0.9, 0.6)
const WARNING_COLOR := Color(1.0, 0.55, 0.4)
const MUTED_COLOR := Color(0.6, 0.65, 0.75)

@onready var _root: VBoxContainer = $Root

var _steam_label: Label
var _status_label: Label
var _device_label: Label
var _change_device_button: Button
var _controllers_label: Label
var _code_label: Label
var _copy_button: Button
var _host_button: Button
var _invite_button: Button
var _leave_button: Button
var _code_input: LineEdit
var _join_button: Button
var _members_box: VBoxContainer
var _friends_box: VBoxContainer
var _start_button: Button

## Held state from the previous frame, keyed by "kind:id", for edge detection.
var _previous_confirm := {}
var _friend_refresh := 0.0


func _ready() -> void:
	_build()
	NetworkManager.lobby_changed.connect(_refresh)
	NetworkManager.status_changed.connect(_on_status_changed)
	NetworkManager.device_changed.connect(_refresh)
	Input.joy_connection_changed.connect(
		func(_device_id: int, _connected: bool) -> void: _refresh_controllers()
	)
	_seed_confirm_state()
	_on_status_changed(NetworkManager.status)
	_refresh()
	_refresh_friends()


func _process(delta: float) -> void:
	if not NetworkManager.has_confirmed_device():
		_poll_confirm()
	_friend_refresh += delta
	if _friend_refresh >= FRIEND_REFRESH_SECONDS:
		_friend_refresh = 0.0
		_refresh_friends()


## Press, not hold: a button still held from the previous screen (the Y that
## opened this one, or Enter) must not confirm on the first frame.
func _seed_confirm_state() -> void:
	for device in InputDevice.connected_devices():
		_previous_confirm[_device_key(device)] = device.is_join_pressed()


func _poll_confirm() -> void:
	for device in InputDevice.connected_devices():
		var key := _device_key(device)
		var held := device.is_join_pressed()
		var was_held: bool = _previous_confirm.get(key, false)
		_previous_confirm[key] = held
		if held and not was_held:
			NetworkManager.confirm_device(device)
			return


func _device_key(device: InputDevice) -> String:
	return "%d:%d" % [device.kind, device.device_id]


# ---------------------------------------------------------------------------
# Layout
# ---------------------------------------------------------------------------

func _build() -> void:
	var title := Label.new()
	title.text = "ONLINE  ·  STEAM"
	title.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	title.add_theme_font_size_override("font_size", 44)
	_root.add_child(title)

	_steam_label = _label(14, MUTED_COLOR)
	_status_label = _label(18, Color(0.95, 0.85, 0.5))

	# Controller confirmation comes first, above everything it unlocks.
	_device_label = _label(20, PROMPT_COLOR)
	var device_row := _row()
	_change_device_button = _button(device_row, "Change controller", _on_change_device)
	_controllers_label = _label(13, MUTED_COLOR)

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


## Mouse-only buttons. A focused button is also pressed by a pad's A or the
## Enter key, and those are exactly the presses that confirm a controller, so
## "Change controller" would instantly fire again on the confirming press.
func _button(parent: Container, text: String, action: Callable) -> Button:
	var button := Button.new()
	button.text = text
	button.custom_minimum_size = Vector2(150, 40)
	button.focus_mode = Control.FOCUS_NONE
	button.pressed.connect(action)
	parent.add_child(button)
	return button


# ---------------------------------------------------------------------------
# State
# ---------------------------------------------------------------------------

func _refresh() -> void:
	var steam_ok := NetworkManager.steam_ready
	var confirmed := NetworkManager.has_confirmed_device()
	var in_lobby := NetworkManager.is_in_lobby()
	var hosting := NetworkManager.is_host()

	_steam_label.text = (
		"Signed in as %s" % NetworkManager.steam_name if steam_ok else "Steam unavailable"
	)

	# Everything that starts or joins a session waits on a confirmed controller.
	var can_act := steam_ok and confirmed
	_host_button.disabled = not can_act or in_lobby
	_invite_button.disabled = not in_lobby
	_leave_button.disabled = not in_lobby
	_join_button.disabled = not can_act
	_code_input.editable = can_act

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
	_refresh_friends_enabled()


func _refresh_device() -> void:
	var device := NetworkManager.local_device
	if device == null:
		var waiting := ""
		if NetworkManager.pending_lobby_id != 0:
			# Not `owner`: that would shadow Node.owner.
			var inviter := NetworkManager.pending_lobby_owner
			waiting = "Joining %s once you confirm.\n" % (
				"%s's lobby" % inviter if not inviter.is_empty() else "the lobby"
			)
		_device_label.text = (
			"%sPress A on the controller you'll play with, or Enter for the keyboard."
			% waiting
		)
		_device_label.add_theme_color_override("font_color", PROMPT_COLOR)
		_change_device_button.visible = false
	elif not NetworkManager.is_device_available():
		_device_label.text = (
			"Your controller is disconnected. Plug it back in, or press Change controller."
		)
		_device_label.add_theme_color_override("font_color", WARNING_COLOR)
		_change_device_button.visible = true
	else:
		_device_label.text = "You'll play with: %s  ✓" % device.display_name()
		_device_label.add_theme_color_override("font_color", CONFIRMED_COLOR)
		_change_device_button.visible = true
	# The seat's device is locked once a match has started.
	_change_device_button.disabled = NetworkManager.in_match
	_refresh_controllers()


## The pads the game can actually see. "None" with a pad plugged in means
## something outside the game has it, nearly always Steam Input.
func _refresh_controllers() -> void:
	var pads := NetworkManager.connected_controller_names()
	if pads.is_empty():
		_controllers_label.text = (
			"Controllers the game can see: none. If one is plugged in, Steam Input is "
			+ "probably hiding it — see PORTING.md, Online multiplayer."
		)
		_controllers_label.add_theme_color_override("font_color", WARNING_COLOR)
	else:
		_controllers_label.text = "Controllers the game can see: %s" % ", ".join(pads)
		_controllers_label.add_theme_color_override("font_color", MUTED_COLOR)


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
	_refresh_friends_enabled()


func _refresh_friends_enabled() -> void:
	var can_act := NetworkManager.steam_ready and NetworkManager.has_confirmed_device()
	for child in _friends_box.get_children():
		if child is Button:
			(child as Button).disabled = not can_act


func _on_status_changed(text: String) -> void:
	_status_label.text = text


func _on_change_device() -> void:
	NetworkManager.clear_device()
	# The click that got here must not count as the new confirmation.
	_seed_confirm_state()


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
