class_name TuningPanel
extends VBoxContainer
## Live editor for one tuning Resource, built by reflection.
##
## Reads the exported properties off the Resource with get_property_list(), so a
## new @export in any tuning script shows up here with no work. Edits are applied
## to the Resource immediately — every car shares the same instance, so changes
## are felt the moment you drag a value.
##
## Anything differing from the last saved state is marked dirty: bold, and
## recoloured. That is the whole point of the panel — knowing at a glance which
## numbers you have moved away from what is on disk.

## Colour for a value that has been tweaked but not saved.
const DIRTY_COLOR := Color(1.0, 0.72, 0.2)
const CLEAN_COLOR := Color(0.82, 0.86, 0.92)
const GROUP_COLOR := Color(0.55, 0.75, 1.0)

signal dirty_changed(panel: TuningPanel, dirty_count: int)

var resource: Resource
var title := ""

## Property name -> value as it was at load or last save.
var _baseline: Dictionary = {}
## Property name -> the RichTextLabel showing its name.
var _labels: Dictionary = {}
## Property names currently differing from baseline.
var _dirty: Dictionary = {}


func setup(target: Resource, panel_title: String) -> void:
	resource = target
	title = panel_title
	name = panel_title
	add_theme_constant_override("separation", 2)
	_build()


func dirty_count() -> int:
	return _dirty.size()


func dirty_names() -> Array:
	var names := _dirty.keys()
	names.sort()
	return names


## Human-readable summary of every pending change, for the confirm dialog.
func describe_changes() -> String:
	var lines := PackedStringArray()
	for property in dirty_names():
		lines.append(
			"    %s:  %s  ->  %s"
			% [property, _format(_baseline[property]), _format(resource.get(property))]
		)
	return "\n".join(lines)


func save() -> Error:
	if resource == null or resource.resource_path.is_empty():
		return ERR_FILE_BAD_PATH
	var result := ResourceSaver.save(resource, resource.resource_path)
	if result == OK:
		for property in _dirty.keys():
			_baseline[property] = resource.get(property)
		_dirty.clear()
		_restyle_all()
		dirty_changed.emit(self, 0)
	return result


func revert() -> void:
	for property in _dirty.keys():
		resource.set(property, _baseline[property])
	_dirty.clear()
	_refresh_widgets()
	_restyle_all()
	dirty_changed.emit(self, 0)


func _build() -> void:
	if resource == null:
		return

	for property in resource.get_property_list():
		var usage: int = property.get("usage", 0)

		# @export_group headers come through the same list; use them as sections.
		if usage & PROPERTY_USAGE_GROUP:
			_add_group_header(String(property.get("name", "")))
			continue

		if not (usage & PROPERTY_USAGE_SCRIPT_VARIABLE) or not (usage & PROPERTY_USAGE_EDITOR):
			continue

		var property_name := String(property.get("name", ""))
		if property_name.is_empty() or property_name == "script":
			continue

		var editor := _make_editor(property, property_name)
		if editor == null:
			continue

		_baseline[property_name] = resource.get(property_name)
		_add_row(property_name, editor)


func _add_group_header(text: String) -> void:
	var header := Label.new()
	header.text = text.to_upper()
	header.add_theme_font_size_override("font_size", 11)
	header.add_theme_color_override("font_color", GROUP_COLOR)
	var spacer := Control.new()
	spacer.custom_minimum_size = Vector2(0, 6)
	add_child(spacer)
	add_child(header)


func _add_row(property_name: String, editor: Control) -> void:
	var row := HBoxContainer.new()
	row.add_theme_constant_override("separation", 8)

	# RichTextLabel rather than Label: BBCode [b] is how the dirty state gets
	# bolded, and the default theme supplies the bold font for it.
	var label := RichTextLabel.new()
	label.bbcode_enabled = true
	label.fit_content = true
	label.scroll_active = false
	label.custom_minimum_size = Vector2(210, 0)
	label.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	row.add_child(label)

	editor.custom_minimum_size = Vector2(120, 0)
	row.add_child(editor)

	add_child(row)
	_labels[property_name] = label
	_style_label(property_name)


func _make_editor(property: Dictionary, property_name: String) -> Control:
	var type: int = property.get("type", TYPE_NIL)
	var hint: int = property.get("hint", PROPERTY_HINT_NONE)
	var hint_string := String(property.get("hint_string", ""))
	var value = resource.get(property_name)

	if type == TYPE_BOOL:
		var check := CheckBox.new()
		check.button_pressed = value
		check.toggled.connect(func(pressed: bool) -> void: _on_edited(property_name, pressed))
		return check

	if type == TYPE_INT and hint == PROPERTY_HINT_ENUM:
		var options := OptionButton.new()
		for entry in hint_string.split(","):
			# Entries can be "Name" or "Name:3"; the label is all we need.
			options.add_item(entry.split(":")[0])
		options.selected = clampi(int(value), 0, maxi(0, options.item_count - 1))
		options.item_selected.connect(
			func(index: int) -> void: _on_edited(property_name, index)
		)
		return options

	if type == TYPE_INT or type == TYPE_FLOAT:
		var spin := SpinBox.new()
		spin.allow_greater = true
		spin.allow_lesser = true
		if hint == PROPERTY_HINT_RANGE:
			var parts := hint_string.split(",")
			if parts.size() >= 2:
				spin.min_value = float(parts[0])
				spin.max_value = float(parts[1])
				spin.allow_greater = false
				spin.allow_lesser = false
			if parts.size() >= 3:
				spin.step = float(parts[2])
			elif type == TYPE_INT:
				spin.step = 1.0
			else:
				spin.step = 0.01
		else:
			spin.min_value = -100000.0
			spin.max_value = 100000.0
			spin.step = 1.0 if type == TYPE_INT else 0.01
		spin.value = float(value)
		spin.value_changed.connect(
			func(new_value: float) -> void:
				_on_edited(property_name, int(new_value) if type == TYPE_INT else new_value)
		)
		return spin

	if type == TYPE_COLOR:
		var picker := ColorPickerButton.new()
		picker.color = value
		picker.color_changed.connect(
			func(new_color: Color) -> void: _on_edited(property_name, new_color)
		)
		return picker

	# Curves and object references are out of scope for an in-game panel.
	return null


func _on_edited(property_name: String, value) -> void:
	resource.set(property_name, value)
	var is_dirty := not _values_equal(value, _baseline.get(property_name))
	if is_dirty:
		_dirty[property_name] = true
	else:
		_dirty.erase(property_name)
	_style_label(property_name)
	dirty_changed.emit(self, _dirty.size())


func _style_label(property_name: String) -> void:
	var label: RichTextLabel = _labels.get(property_name)
	if label == null:
		return
	if _dirty.has(property_name):
		label.text = (
			"[b][color=#%s]%s[/color][/b]  [color=#7a7f8a](was %s)[/color]"
			% [DIRTY_COLOR.to_html(false), property_name, _format(_baseline[property_name])]
		)
	else:
		label.text = "[color=#%s]%s[/color]" % [CLEAN_COLOR.to_html(false), property_name]


func _restyle_all() -> void:
	for property_name in _labels:
		_style_label(property_name)


## Rebuilds every widget from the Resource. Done wholesale rather than by
## writing values back into each control, which would re-fire their changed
## signals and mark everything dirty again.
func _refresh_widgets() -> void:
	for child in get_children():
		remove_child(child)
		child.queue_free()
	_labels.clear()
	_build()


func _values_equal(a, b) -> bool:
	if a is float and b is float:
		return is_equal_approx(a, b)
	return a == b


func _format(value) -> String:
	if value is float:
		# GDScript's % operator has no %g, so trim by hand: 22.0000 -> 22,
		# 0.3000 -> 0.3. Keeps the confirm dialog readable.
		var text := String.num(value, 4)
		if text.contains("."):
			text = text.rstrip("0").rstrip(".")
		return text if not text.is_empty() else "0"
	if value is bool:
		return "on" if value else "off"
	if value is Color:
		return "#" + value.to_html(false)
	return str(value)
