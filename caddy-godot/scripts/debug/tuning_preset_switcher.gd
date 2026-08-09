class_name TuningPresetSwitcher
extends CanvasLayer
## Cycles handling presets live, so two of them can be compared back to back
## rather than from memory.
##
## Port of the runtime tuning presets on ACaddyVehiclePawn — an array of tuning
## assets with CycleRuntimeTuningPreset, driven there by the console commands
## caddy.vehicle.tuning.next / .prev / .set. Bound to F2 and F3 here.
##
## The preset is applied to **every** car, not just the local one: comparing feel
## is only meaningful if both sides of a fight are on the same numbers.

## Other debug tools watch this to re-point themselves at the new resource.
const GROUP := &"tuning_preset_switcher"

## Loaded when `presets` is left empty. Kept as paths rather than as a typed
## array in the scene file: a script-typed resource array is fiddly to hand-write
## in a .tscn and fails silently if the type annotation is wrong.
const DEFAULT_PRESET_PATHS := [
	"res://resources/tuning/presets/handling_stock.tres",
	"res://resources/tuning/presets/handling_quick.tres",
	"res://resources/tuning/presets/handling_balanced.tres",
	"res://resources/tuning/presets/handling_weighty.tres",
	"res://resources/tuning/presets/handling_heavy.tres",
]

signal preset_changed(tuning: VehicleTuning, index: int)

@export var presets: Array[VehicleTuning] = []
## Shown in the corner. Turn off if it gets in the way of a screenshot.
@export var show_label: bool = true

var active_index := 0

var _label: Label


func _ready() -> void:
	add_to_group(GROUP)
	layer = 9
	process_mode = Node.PROCESS_MODE_ALWAYS
	if presets.is_empty():
		for path in DEFAULT_PRESET_PATHS:
			var preset := load(path) as VehicleTuning
			if preset != null:
				presets.append(preset)
	if show_label:
		_build_label()
	# Deferred: the cars do not exist yet while the scene is still being built.
	_adopt_current.call_deferred()


## Picks up whatever the cars already ship with, so nothing changes until a key
## is pressed. If that resource is one of the presets, start from its index.
func _adopt_current() -> void:
	var car := _first_vehicle()
	if car != null and car.tuning != null:
		var found := presets.find(car.tuning)
		if found >= 0:
			active_index = found
	_refresh_label()


func _unhandled_input(event: InputEvent) -> void:
	if presets.is_empty():
		return
	if event.is_action_pressed("caddy_tuning_next"):
		cycle(1)
		get_viewport().set_input_as_handled()
	elif event.is_action_pressed("caddy_tuning_prev"):
		cycle(-1)
		get_viewport().set_input_as_handled()


func cycle(step: int) -> void:
	apply_preset(active_index + step)


func apply_preset(index: int) -> void:
	if presets.is_empty():
		return

	active_index = wrapi(index, 0, presets.size())
	var preset := presets[active_index]
	if preset == null:
		return

	for node in get_tree().get_nodes_in_group(ClashArbiter.VEHICLE_GROUP):
		var car := node as ArcadeVehicle
		if car != null:
			car.tuning = preset

	_refresh_label()
	preset_changed.emit(preset, active_index)


func active_preset() -> VehicleTuning:
	return presets[active_index] if active_index < presets.size() else null


func _first_vehicle() -> ArcadeVehicle:
	for node in get_tree().get_nodes_in_group(ClashArbiter.VEHICLE_GROUP):
		var car := node as ArcadeVehicle
		if car != null:
			return car
	return null


func _build_label() -> void:
	var panel := PanelContainer.new()
	panel.set_anchors_preset(Control.PRESET_BOTTOM_RIGHT)
	panel.offset_left = -430.0
	panel.offset_top = -58.0
	panel.offset_right = -12.0
	panel.offset_bottom = -12.0
	add_child(panel)

	_label = Label.new()
	_label.add_theme_font_size_override("font_size", 14)
	_label.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	panel.add_child(_label)


func _refresh_label() -> void:
	if _label == null:
		return
	var preset := active_preset()
	if preset == null:
		_label.text = "no handling presets assigned"
		return
	_label.text = (
		"HANDLING %d/%d   %s\naccel %.0f   brake %.0f   top %.0f m/s      [F2/F3]"
		% [
			active_index + 1,
			presets.size(),
			preset.preset_name,
			preset.forward_acceleration,
			preset.brake_deceleration,
			preset.max_forward_speed,
		]
	)
