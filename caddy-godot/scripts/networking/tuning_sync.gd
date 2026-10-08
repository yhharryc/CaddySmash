extends Node
## Autoload that keeps every machine in an online session on the host's tuning.
##
## Host-only editing: on a client the debug menu is read-only, apart from the
## per-player Camera tab, and every value the host changes is pushed out live.
## This matters beyond fairness. Each client simulates its own car from its local
## tuning to predict it (see NetMatchSync), so a handling value the client never
## received would make that prediction disagree with the host and rubber-band.
##
## When a client connects, the host sends every tuning value it has, not just
## what it edited. A friend on an older build then still plays the host's
## numbers. When the session ends the client goes back to its own values,
## including its own saved overrides.
##
## No class_name: Godot rejects a global class that shadows an autoload name.

## A single value arrived from the host and has been applied.
signal value_changed(resource: Resource, property: String, value: Variant)
## Many values changed at once (a full snapshot, or going back to local values).
## Anything showing tuning should rebuild from the resources.
signal values_replaced
## The host switched handling preset.
signal preset_changed(index: int)

## Last handling preset the host announced, or -1. Kept here because it can
## arrive before the client's arena scene, and its preset switcher, exist.
var preset_index := -1

var _holding_host_values := false


func _ready() -> void:
	multiplayer.peer_connected.connect(_on_peer_connected)
	multiplayer.server_disconnected.connect(_restore_local)
	NetworkManager.lobby_changed.connect(_on_lobby_changed)


## Connected to someone else's session. Tuning is theirs to change.
func is_client() -> bool:
	return NetworkManager.is_online() and not multiplayer.is_server()


func can_edit(resource: Resource) -> bool:
	return not is_client() or TuningOverrides.is_local_only(resource)


## Called by the debug menu after it changes a value on this machine.
func notify_local_edit(resource: Resource, property: String, value: Variant) -> void:
	if not NetworkManager.is_host() or TuningOverrides.is_local_only(resource):
		return
	_rpc_set_value.rpc(resource.resource_path, property, value)


## Called by the preset switcher whenever the host's preset is set. -1 means the
## cars are on their scene's own tuning file rather than on a preset.
func notify_preset(index: int) -> void:
	if is_client():
		return
	preset_index = index
	if NetworkManager.is_host():
		_rpc_preset.rpc(index)


## Host: pushes every synced value to everyone, e.g. after a reset.
func broadcast_snapshot() -> void:
	if NetworkManager.is_host():
		_rpc_snapshot.rpc(_collect())


func _on_peer_connected(peer_id: int) -> void:
	# Clients see peer_connected for the host and for each other; only the host
	# answers.
	if not multiplayer.is_server() or not NetworkManager.is_online():
		return
	_rpc_snapshot.rpc_id(peer_id, _collect())
	if preset_index >= 0:
		_rpc_preset.rpc_id(peer_id, preset_index)


func _collect() -> Dictionary:
	var values := {}
	for path in TuningOverrides.synced_paths():
		values[path] = TuningOverrides.values_of(TuningOverrides.resource_for(path))
	return values


@rpc("authority", "call_remote", "reliable")
func _rpc_set_value(path: String, property: String, value: Variant) -> void:
	var resource := TuningOverrides.resource_for(path)
	if resource == null or not TuningOverrides.tunable_properties(resource).has(property):
		return
	resource.set(property, value)
	_holding_host_values = true
	value_changed.emit(resource, property, value)


@rpc("authority", "call_remote", "reliable")
func _rpc_snapshot(values: Dictionary) -> void:
	for path in values:
		TuningOverrides.apply_values(path, values[path])
	_holding_host_values = true
	values_replaced.emit()


@rpc("authority", "call_remote", "reliable")
func _rpc_preset(index: int) -> void:
	preset_index = index
	preset_changed.emit(index)


## Session over: back to this machine's shipped values plus its own overrides.
func _restore_local() -> void:
	preset_index = -1
	if not _holding_host_values:
		return
	_holding_host_values = false
	TuningOverrides.restore_shipped(true)
	TuningOverrides.reapply_saved()
	values_replaced.emit()


func _on_lobby_changed() -> void:
	if not NetworkManager.is_online():
		_restore_local()
