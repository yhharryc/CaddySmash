extends Node
## Autoload that remembers the shipped tuning values and keeps tuning edits made
## in an exported build.
##
## An exported game's res:// is read-only — this project packs it inside the
## .exe — so the debug menu's Save cannot write the .tres files there. Builds
## save to user://tuning_overrides.cfg instead and load it again at startup.
## Running from the editor, Save still writes the .tres files and this file is
## never loaded, so the project's own values stay the source of truth while
## developing. (Both share the same user:// folder, which is why the editor has
## to skip it rather than just not writing it.)
##
## Also the one place that knows every tuning file by path. A path names the same
## value on every machine, which is what TuningSync relies on.
##
## No class_name: Godot rejects a global class that shadows an autoload name.

signal overrides_changed

const OVERRIDES_PATH := "user://tuning_overrides.cfg"

## Every tuning file that affects play. Loaded at startup so the shipped values
## are captured before anything edits them, and kept referenced so the resource
## cache hands the cars these same instances. Add new tuning files here.
const SYNCED_PATHS: Array[String] = [
	"res://resources/tuning/tuning_default.tres",
	"res://resources/tuning/presets/handling_stock.tres",
	"res://resources/tuning/presets/handling_quick.tres",
	"res://resources/tuning/presets/handling_balanced.tres",
	"res://resources/tuning/presets/handling_weighty.tres",
	"res://resources/tuning/presets/handling_heavy.tres",
	"res://resources/tuning/skill_default.tres",
	"res://resources/tuning/impact_default.tres",
	"res://resources/tuning/combat_default.tres",
	"res://resources/tuning/momentum_default.tres",
	"res://resources/tuning/feel_default.tres",
	"res://resources/tuning/impact_fx_default.tres",
	"res://resources/tuning/drift_trail_default.tres",
]
## Per-player tuning: saved locally, never sent to anyone. The shot each player
## looks at changes nothing about the simulation.
const LOCAL_ONLY_PATHS: Array[String] = [
	"res://resources/tuning/camera_arena.tres",
	"res://resources/tuning/camera_chase.tres",
]

## Value types an override can hold. Curves and other objects are out of scope,
## the same as in the debug menu.
const _SAVEABLE_TYPES := [TYPE_BOOL, TYPE_INT, TYPE_FLOAT, TYPE_COLOR]

## Resource path -> Resource.
var _resources: Dictionary = {}
## Resource path -> {property: value} as shipped.
var _pristine: Dictionary = {}
var _saved := ConfigFile.new()


func _ready() -> void:
	for path in SYNCED_PATHS + LOCAL_ONLY_PATHS:
		resource_for(path)
	if saves_to_user():
		_load_saved()


## True in an exported build. There, Save writes the overrides file.
func saves_to_user() -> bool:
	return not OS.has_feature("editor")


func is_local_only(resource: Resource) -> bool:
	return resource is CameraTuning or LOCAL_ONLY_PATHS.has(resource.resource_path)


## Records a resource's shipped values the first time it is seen. Every edit
## path calls this first, so the baseline is never taken after a change.
func register(resource: Resource) -> void:
	if resource == null or resource.resource_path.is_empty():
		return
	var path := resource.resource_path
	if _resources.has(path):
		return
	_resources[path] = resource
	_pristine[path] = values_of(resource)


## The live, shared instance for a tuning path, loading and registering it if
## needed. Null if no such file exists in this build.
func resource_for(path: String) -> Resource:
	if _resources.has(path):
		return _resources[path]
	if not ResourceLoader.exists(path):
		return null
	var resource := load(path)
	register(resource)
	return resource


## Every tunable property and its current value.
func values_of(resource: Resource) -> Dictionary:
	var values := {}
	for property in tunable_properties(resource):
		values[property] = resource.get(property)
	return values


## Writes whichever of `values` this resource actually has. A property the
## sender has and this build does not is skipped rather than erroring.
func apply_values(path: String, values: Dictionary) -> void:
	var resource := resource_for(path)
	if resource == null:
		return
	var known := tunable_properties(resource)
	for property in values:
		if known.has(property):
			resource.set(property, values[property])


func synced_paths() -> Array[String]:
	var paths: Array[String] = []
	for path in _resources:
		if not is_local_only(_resources[path]):
			paths.append(path)
	return paths


static func tunable_properties(resource: Resource) -> Array[String]:
	var names: Array[String] = []
	if resource == null:
		return names
	for property in resource.get_property_list():
		var usage: int = property.get("usage", 0)
		if not (usage & PROPERTY_USAGE_SCRIPT_VARIABLE) or not (usage & PROPERTY_USAGE_EDITOR):
			continue
		if not _SAVEABLE_TYPES.has(property.get("type", TYPE_NIL)):
			continue
		var property_name := String(property.get("name", ""))
		if not property_name.is_empty() and property_name != "script":
			names.append(property_name)
	return names


# ---------------------------------------------------------------------------
# Saved overrides (exported builds)
# ---------------------------------------------------------------------------

## Replaces this resource's section of the overrides file with whatever it now
## differs from shipped by, and writes the file.
func save_resource(resource: Resource) -> Error:
	register(resource)
	var path := resource.resource_path
	if _saved.has_section(path):
		_saved.erase_section(path)
	var changed := _diff(path)
	for property in changed:
		_saved.set_value(path, property, changed[property])
	var result := _saved.save(OVERRIDES_PATH)
	overrides_changed.emit()
	return result


## Values held in the overrides file, i.e. what this build loads at startup.
func saved_count() -> int:
	var total := 0
	for section in _saved.get_sections():
		total += _saved.get_section_keys(section).size()
	return total


## Deletes the overrides file. Live values are untouched; use restore_shipped.
func clear_saved() -> void:
	_saved = ConfigFile.new()
	if FileAccess.file_exists(OVERRIDES_PATH):
		DirAccess.remove_absolute(ProjectSettings.globalize_path(OVERRIDES_PATH))
	overrides_changed.emit()


## Puts values back to how this build shipped. `include_synced` false touches
## only the local-only (camera) files.
func restore_shipped(include_synced: bool) -> void:
	for path in _resources:
		if not include_synced and not is_local_only(_resources[path]):
			continue
		apply_values(path, _pristine[path])


## Re-applies the overrides file on top of whatever is live. Builds only.
func reapply_saved() -> void:
	if not saves_to_user():
		return
	for section in _saved.get_sections():
		var values := {}
		for property in _saved.get_section_keys(section):
			values[property] = _saved.get_value(section, property)
		apply_values(section, values)


## Every value that differs from shipped, as text to paste back into the .tres
## files (or to a person) to make it permanent.
func describe_changes() -> String:
	var lines := PackedStringArray()
	for path in _resources:
		var changed := _diff(path)
		if changed.is_empty():
			continue
		lines.append(path)
		var names := changed.keys()
		names.sort()
		for property in names:
			lines.append("    %s = %s" % [property, _format(changed[property])])
	return "\n".join(lines) if not lines.is_empty() else "No tuning changes from the shipped values."


func _load_saved() -> void:
	if not FileAccess.file_exists(OVERRIDES_PATH):
		return
	if _saved.load(OVERRIDES_PATH) != OK:
		push_warning("Could not read %s; ignoring it." % OVERRIDES_PATH)
		_saved = ConfigFile.new()
		return
	reapply_saved()
	print("Tuning: loaded %d saved override(s) from %s" % [
		saved_count(), ProjectSettings.globalize_path(OVERRIDES_PATH)
	])


func _diff(path: String) -> Dictionary:
	var changed := {}
	var resource: Resource = _resources.get(path)
	if resource == null:
		return changed
	var shipped: Dictionary = _pristine.get(path, {})
	for property in tunable_properties(resource):
		var value = resource.get(property)
		if not shipped.has(property) or not _equal(value, shipped[property]):
			changed[property] = value
	return changed


func _equal(a, b) -> bool:
	if a is float and b is float:
		return is_equal_approx(a, b)
	return a == b


func _format(value) -> String:
	if value is float:
		var text := String.num(value, 4)
		if text.contains("."):
			text = text.rstrip("0").rstrip(".")
		return text if not text.is_empty() else "0"
	if value is Color:
		return "Color(%s)" % ", ".join([value.r, value.g, value.b, value.a].map(func(c: float) -> String: return String.num(c, 3)))
	return str(value)
