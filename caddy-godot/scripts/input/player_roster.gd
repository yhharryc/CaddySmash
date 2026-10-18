extends Node
## Autoload holding who joined the match, so the join screen can hand the lineup
## to the arena across a scene change.
##
## Deliberately has no class_name: Godot rejects a global class whose name
## collides with an autoload singleton, and the singleton name is what callers use.

const MAX_PLAYERS := 4

signal roster_changed

var players: Array[PlayerSlot] = []


func count() -> int:
	return players.size()


func is_full() -> bool:
	return players.size() >= MAX_PLAYERS


func has_device(device: InputDevice) -> bool:
	return find_by_device(device) != null


func find_by_device(device: InputDevice) -> PlayerSlot:
	for slot in players:
		if slot.device != null and slot.device.matches(device):
			return slot
	return null


## Claims the lowest free seat. Returns the slot, or null if full or already in.
func join(device: InputDevice) -> PlayerSlot:
	if device == null or is_full() or has_device(device):
		return null

	var slot := PlayerSlot.make(_lowest_free_index(), device)
	players.append(slot)
	players.sort_custom(func(a: PlayerSlot, b: PlayerSlot) -> bool: return a.index < b.index)
	roster_changed.emit()
	return slot


func leave(device: InputDevice) -> bool:
	var slot := find_by_device(device)
	if slot == null:
		return false
	players.erase(slot)
	roster_changed.emit()
	return true


func clear() -> void:
	players.clear()
	roster_changed.emit()


## Drops anyone whose pad was unplugged. Returns how many were removed.
func prune_disconnected() -> int:
	var removed := 0
	for slot in players.duplicate():
		if slot.device == null or not slot.device.is_available():
			players.erase(slot)
			removed += 1
	if removed > 0:
		roster_changed.emit()
	return removed


## Online seating, sent by the host so every machine spawns the same lineup.
## `entries` is [{peer_id, name}] in seat order. This machine's seat drives with
## `local_device`; every other seat gets a NetworkInputDevice, which only the
## host actually feeds.
func set_online_roster(entries: Array, local_peer_id: int, local_device: InputDevice) -> void:
	players.clear()
	for i in mini(entries.size(), MAX_PLAYERS):
		var entry: Dictionary = entries[i]
		var peer_id := int(entry.get("peer_id", 0))
		var player_name := String(entry.get("name", ""))
		var device: InputDevice = (
			local_device
			if peer_id == local_peer_id
			else NetworkInputDevice.for_peer(peer_id, player_name)
		)
		var slot := PlayerSlot.make(i, device)
		slot.peer_id = peer_id
		slot.player_name = player_name
		players.append(slot)
	roster_changed.emit()


## Falls back to a single keyboard player, so the arena scene can be run directly
## without going through the join screen.
func ensure_at_least_one() -> void:
	if players.is_empty():
		join(InputDevice.keyboard())


func _lowest_free_index() -> int:
	var taken := {}
	for slot in players:
		taken[slot.index] = true
	for i in MAX_PLAYERS:
		if not taken.has(i):
			return i
	return MAX_PLAYERS - 1
