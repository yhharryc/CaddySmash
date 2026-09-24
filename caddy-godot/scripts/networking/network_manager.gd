extends Node
## Autoload that owns the Steam lobby and the multiplayer peer behind it.
##
## Flow: the host creates a friends-only Steam lobby and binds a
## SteamMultiplayerPeer to it. Friends get in through an overlay invite, "Join
## Game" on the Steam friends list, or by pasting the lobby code, and their peer
## connects to the lobby owner. Traffic goes over Steam Datagram Relay, so
## nobody forwards ports and NAT is Valve's problem. The host then starts the
## match and every machine loads the arena with the same seating.
##
## What happens inside a match is NetMatchSync's job; this only gets everyone
## into one session and back out of it.
##
## No class_name: Godot rejects a global class that shadows an autoload name,
## same as PlayerRoster and HitStop.

## Emitted whenever lobby membership, connection state or names change.
signal lobby_changed
signal status_changed(text: String)
## A client dropped. Fired on the host, so a running match can park their car.
signal peer_left(peer_id: int)

const LOBBY_SCENE := "res://scenes/online_lobby.tscn"
const MATCH_SCENE := "res://scenes/arena_match.tscn"
const LOCAL_SCENE := "res://scenes/join_screen.tscn"
## Matches PlayerRoster.MAX_PLAYERS. A literal, since autoload members are not
## constant expressions.
const MAX_MEMBERS := 4
## Written into lobby data so a lobby from another Spacewar (app 480) project is
## never mistaken for ours.
const LOBBY_GAME_TAG := "caddy_smash"

var steam_ready := false
var steam_id := 0
var steam_name := ""
var lobby_id := 0
var status := ""
var in_match := false
## The device this machine's player drives with. Chosen on the lobby screen.
var local_device: InputDevice = InputDevice.keyboard()

var _peer: SteamMultiplayerPeer = null


func _ready() -> void:
	steam_ready = Steam.isSteamRunning() and Steam.getSteamID() != 0
	if not steam_ready:
		_set_status("Steam is not running. Start Steam, sign in, then relaunch the game.")
		return

	steam_id = Steam.getSteamID()
	steam_name = Steam.getPersonaName()

	Steam.lobby_created.connect(_on_lobby_created)
	Steam.lobby_joined.connect(_on_lobby_joined)
	Steam.lobby_chat_update.connect(_on_lobby_chat_update)
	Steam.join_requested.connect(_on_join_requested)
	Steam.persona_state_change.connect(_on_persona_state_change)

	multiplayer.peer_connected.connect(_on_peer_connected)
	multiplayer.peer_disconnected.connect(_on_peer_disconnected)
	multiplayer.connected_to_server.connect(_on_connected_to_server)
	multiplayer.connection_failed.connect(_on_connection_failed)
	multiplayer.server_disconnected.connect(_on_server_disconnected)

	_set_status("Signed in to Steam as %s." % steam_name)
	_join_from_command_line.call_deferred()


## GodotSteam ignores `embed_callbacks` when `initialize_on_startup` is also on
## (it logs a warning saying so), so nothing Steam reports — lobby created,
## joined, invites, connection status — arrives unless it is pumped here.
func _process(_delta: float) -> void:
	if steam_ready:
		Steam.run_callbacks()


# ---------------------------------------------------------------------------
# Queries
# ---------------------------------------------------------------------------

func is_online() -> bool:
	return _peer != null and multiplayer.multiplayer_peer == _peer


func is_host() -> bool:
	return is_online() and multiplayer.is_server()


func is_in_lobby() -> bool:
	return lobby_id != 0


## Everyone in the Steam lobby, host first. `peer_id` is 0 until that member's
## multiplayer connection is up, which can trail their lobby join by a moment.
func lobby_members() -> Array[Dictionary]:
	var members: Array[Dictionary] = []
	if lobby_id == 0:
		return members

	var owner_id := Steam.getLobbyOwner(lobby_id)
	for i in Steam.getNumLobbyMembers(lobby_id):
		var member_id := Steam.getLobbyMemberByIndex(lobby_id, i)
		var member := {
			"steam_id": member_id,
			"name": _name_for_steam_id(member_id),
			"is_host": member_id == owner_id,
			"is_self": member_id == steam_id,
			"peer_id": _peer_id_for_steam_id(member_id),
		}
		if member["is_host"]:
			members.push_front(member)
		else:
			members.append(member)
	return members


## Friends currently sitting in a lobby of this game, for one-click joining.
func friends_in_lobbies() -> Array[Dictionary]:
	var found: Array[Dictionary] = []
	if not steam_ready:
		return found

	var app_id := Steam.getAppID()
	for i in Steam.getFriendCount(Steam.FRIEND_FLAG_IMMEDIATE):
		var friend_id := Steam.getFriendByIndex(i, Steam.FRIEND_FLAG_IMMEDIATE)
		var game: Dictionary = Steam.getFriendGamePlayed(friend_id)
		if game.is_empty() or int(game.get("id", 0)) != app_id:
			continue
		var friend_lobby := int(game.get("lobby", 0))
		if friend_lobby == 0 or friend_lobby == lobby_id:
			continue
		found.append({
			"steam_id": friend_id,
			"name": _name_for_steam_id(friend_id),
			"lobby_id": friend_lobby,
		})
	return found


func can_start_match() -> bool:
	return is_host() and not in_match


# ---------------------------------------------------------------------------
# Lobby lifecycle
# ---------------------------------------------------------------------------

func host_lobby() -> void:
	if not _require_steam() or lobby_id != 0:
		return
	_set_status("Creating lobby...")
	Steam.createLobby(Steam.LOBBY_TYPE_FRIENDS_ONLY, MAX_MEMBERS)


func join_lobby(target_lobby_id: int) -> void:
	if not _require_steam() or target_lobby_id == 0 or target_lobby_id == lobby_id:
		return
	if lobby_id != 0:
		leave_lobby()
	_set_status("Joining lobby...")
	Steam.joinLobby(target_lobby_id)


func leave_lobby() -> void:
	_close_peer()
	if lobby_id != 0:
		Steam.leaveLobby(lobby_id)
		lobby_id = 0
	in_match = false
	lobby_changed.emit()


## Opens the Steam overlay's invite dialog for the current lobby.
func invite_friends() -> void:
	if lobby_id != 0:
		Steam.activateGameOverlayInviteDialog(lobby_id)


# ---------------------------------------------------------------------------
# Match lifecycle (host drives, everyone follows)
# ---------------------------------------------------------------------------

## Seats the host first, then connected clients in peer id order, and sends that
## seating to everyone so every machine spawns the identical lineup.
func start_match() -> void:
	if not can_start_match():
		return

	var entries: Array = [{"peer_id": 1, "name": steam_name}]
	var peers := multiplayer.get_peers()
	peers.sort()
	for peer_id in peers:
		if entries.size() >= MAX_MEMBERS:
			break
		entries.append({"peer_id": peer_id, "name": _name_for_peer(peer_id)})

	# Nobody can drop into a match already in progress.
	Steam.setLobbyJoinable(lobby_id, false)
	_rpc_start_match.rpc(entries)


## Host only: takes everyone back to the lobby screen, session intact.
func return_to_lobby() -> void:
	if is_host():
		_rpc_return_to_lobby.rpc()


@rpc("authority", "call_local", "reliable")
func _rpc_start_match(entries: Array) -> void:
	PlayerRoster.set_online_roster(entries, multiplayer.get_unique_id(), local_device)
	in_match = true
	get_tree().change_scene_to_file(MATCH_SCENE)


@rpc("authority", "call_local", "reliable")
func _rpc_return_to_lobby() -> void:
	in_match = false
	PlayerRoster.clear()
	if is_host():
		Steam.setLobbyJoinable(lobby_id, true)
	get_tree().change_scene_to_file(LOBBY_SCENE)


# ---------------------------------------------------------------------------
# Steam callbacks
# ---------------------------------------------------------------------------

func _on_lobby_created(result: int, new_lobby_id: int) -> void:
	if result != Steam.RESULT_OK:
		_set_status("Could not create a lobby (Steam result %d)." % result)
		return

	lobby_id = new_lobby_id
	Steam.setLobbyJoinable(lobby_id, true)
	Steam.setLobbyData(lobby_id, "game", LOBBY_GAME_TAG)
	Steam.setLobbyData(lobby_id, "name", "%s's arena" % steam_name)

	_peer = _make_peer()
	var error: Error = _peer.host_with_lobby(lobby_id)
	if error != OK:
		_set_status("Could not start hosting (error %d)." % error)
		leave_lobby()
		return

	multiplayer.multiplayer_peer = _peer
	_set_status("Hosting. Invite friends, then start the match.")
	lobby_changed.emit()


## Fires for the creator too, straight after lobby_created.
func _on_lobby_joined(joined_lobby_id: int, _permissions: int, _locked: bool, response: int) -> void:
	if response != Steam.CHAT_ROOM_ENTER_RESPONSE_SUCCESS:
		_set_status("Could not join that lobby (Steam response %d)." % response)
		return

	lobby_id = joined_lobby_id
	if Steam.getLobbyOwner(lobby_id) == steam_id:
		lobby_changed.emit()
		return

	if Steam.getLobbyData(lobby_id, "game") != LOBBY_GAME_TAG:
		_set_status("That lobby belongs to a different game.")
		leave_lobby()
		return

	_peer = _make_peer()
	var error: Error = _peer.connect_to_lobby(lobby_id)
	if error != OK:
		_set_status("Could not connect to the host (error %d)." % error)
		leave_lobby()
		return

	multiplayer.multiplayer_peer = _peer
	_set_status("Connecting to host...")
	lobby_changed.emit()


func _on_lobby_chat_update(_lobby: int, _changed_id: int, _making_change_id: int, _chat_state: int) -> void:
	lobby_changed.emit()


## "Join Game" from the Steam friends list, or accepting an overlay invite.
func _on_join_requested(requested_lobby_id: int, _friend_id: int) -> void:
	if in_match:
		return
	join_lobby(requested_lobby_id)
	_goto_lobby_screen()


## Names arrive asynchronously; refresh anything showing them.
func _on_persona_state_change(_changed_steam_id: int, _flags: int) -> void:
	lobby_changed.emit()


# ---------------------------------------------------------------------------
# Multiplayer callbacks
# ---------------------------------------------------------------------------

func _on_peer_connected(_peer_id: int) -> void:
	lobby_changed.emit()


func _on_peer_disconnected(peer_id: int) -> void:
	peer_left.emit(peer_id)
	lobby_changed.emit()


func _on_connected_to_server() -> void:
	_set_status("Connected. Waiting for the host to start.")
	lobby_changed.emit()


func _on_connection_failed() -> void:
	_set_status("Connection to the host failed.")
	leave_lobby()


func _on_server_disconnected() -> void:
	_set_status("The host left the session.")
	leave_lobby()
	_goto_lobby_screen()


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

func _make_peer() -> SteamMultiplayerPeer:
	var peer := SteamMultiplayerPeer.new()
	# Nagle holds small messages back for a few milliseconds to batch them. This
	# game sends a small input or snapshot packet every tick and wants each one
	# on the wire immediately.
	peer.no_nagle = true
	return peer


func _close_peer() -> void:
	if _peer == null:
		return
	if multiplayer.multiplayer_peer == _peer:
		multiplayer.multiplayer_peer = OfflineMultiplayerPeer.new()
	_peer.close()
	_peer = null


## Steam passes "+connect_lobby <id>" when an invite launches the game.
func _join_from_command_line() -> void:
	var args := OS.get_cmdline_args()
	var at := args.find("+connect_lobby")
	if at >= 0 and at + 1 < args.size():
		join_lobby(int(args[at + 1]))
		_goto_lobby_screen()


func _goto_lobby_screen() -> void:
	var current := get_tree().current_scene
	if current == null or current.scene_file_path != LOBBY_SCENE:
		get_tree().change_scene_to_file(LOBBY_SCENE)


func _require_steam() -> bool:
	if not steam_ready:
		_set_status("Steam is not running. Start Steam, sign in, then relaunch the game.")
	return steam_ready


func _peer_id_for_steam_id(member_id: int) -> int:
	if member_id == steam_id:
		return multiplayer.get_unique_id() if is_online() else 0
	if _peer == null:
		return 0
	return maxi(0, _peer.get_peer_id_for_steam_id(member_id))


func _name_for_peer(peer_id: int) -> String:
	if _peer == null:
		return "Peer %d" % peer_id
	return _name_for_steam_id(_peer.get_steam_id_for_peer_id(peer_id))


func _name_for_steam_id(id: int) -> String:
	if id == steam_id:
		return steam_name
	var persona := Steam.getFriendPersonaName(id)
	return persona if not persona.is_empty() else "Player"


func _set_status(text: String) -> void:
	status = text
	status_changed.emit(text)
