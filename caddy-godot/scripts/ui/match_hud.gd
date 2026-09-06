extends CanvasLayer
## Per-player health readout, built from whatever the match spawned.

@export var match_manager: MatchManager

@onready var _rows_container: VBoxContainer = $Rows
@onready var _banner: Label = $Banner

var _bars: Dictionary = {}
var _names: Dictionary = {}
var _skill_labels: Dictionary = {}


func _ready() -> void:
	_banner.visible = false
	if match_manager == null:
		return
	match_manager.player_spawned.connect(_on_player_spawned)
	match_manager.player_eliminated.connect(_on_player_eliminated)
	match_manager.match_finished.connect(_on_match_finished)
	match_manager.match_reset.connect(_on_match_reset)


func _on_player_spawned(slot: PlayerSlot, _vehicle: ArcadeVehicle) -> void:
	var row := HBoxContainer.new()
	row.add_theme_constant_override("separation", 10)

	var name_label := Label.new()
	name_label.text = slot.label()
	name_label.custom_minimum_size = Vector2(38, 0)
	name_label.add_theme_color_override("font_color", slot.color())
	name_label.add_theme_font_size_override("font_size", 20)
	row.add_child(name_label)

	var bar := ProgressBar.new()
	bar.custom_minimum_size = Vector2(200, 20)
	bar.show_percentage = false
	bar.max_value = 100.0
	bar.value = 100.0
	var fill := StyleBoxFlat.new()
	fill.bg_color = slot.color()
	bar.add_theme_stylebox_override("fill", fill)
	row.add_child(bar)

	# Skill readout, so the dash is visibly a thing you have rather than a button
	# you have to already know about.
	var skill_label := Label.new()
	skill_label.custom_minimum_size = Vector2(96, 0)
	skill_label.add_theme_font_size_override("font_size", 13)
	row.add_child(skill_label)

	var device_label := Label.new()
	device_label.text = slot.device.display_name() if slot.device != null else ""
	device_label.add_theme_font_size_override("font_size", 12)
	device_label.add_theme_color_override("font_color", Color(0.65, 0.68, 0.75))
	row.add_child(device_label)

	_rows_container.add_child(row)
	_bars[slot.index] = bar
	_names[slot.index] = name_label
	_skill_labels[slot.index] = skill_label

	var combat: VehicleCombat = match_manager.combats.get(slot.index)
	if combat != null:
		bar.max_value = combat.tuning.max_health
		bar.value = combat.health
		combat.health_changed.connect(
			func(health: float, _max_health: float) -> void: bar.value = health
		)


func _process(_delta: float) -> void:
	if match_manager == null:
		return
	for slot_index in _skill_labels:
		var label: Label = _skill_labels[slot_index]
		var skill: BrakeDashSkill = match_manager.skills.get(slot_index)
		if skill == null or not match_manager.is_alive(slot_index):
			label.text = ""
			continue

		match skill.state:
			BrakeDashSkill.State.BRAKING:
				label.text = "DASH  brake"
				label.add_theme_color_override("font_color", Color(1.0, 0.85, 0.4))
			BrakeDashSkill.State.CHARGING:
				label.text = "DASH  %3d%%" % int(skill.current_charge_alpha * 100.0)
				label.add_theme_color_override("font_color", Color(1.0, 0.72, 0.25))
			BrakeDashSkill.State.DASHING:
				label.text = "DASH!"
				label.add_theme_color_override("font_color", Color(1.0, 0.4, 0.3))
			_:
				if skill.cooldown_remaining > 0.0:
					label.text = "dash %.1fs" % skill.cooldown_remaining
					label.add_theme_color_override("font_color", Color(0.5, 0.52, 0.58))
				else:
					label.text = "DASH ready"
					label.add_theme_color_override("font_color", Color(0.6, 0.9, 0.7))


func _on_player_eliminated(slot: PlayerSlot) -> void:
	var name_label: Label = _names.get(slot.index)
	if name_label != null:
		name_label.text = "%s OUT" % slot.label()
		name_label.add_theme_color_override("font_color", Color(0.5, 0.5, 0.55))


## Clears the OUT marks and the winner banner left over from the last round.
func _on_match_reset() -> void:
	_banner.visible = false
	for slot in match_manager.slots:
		var name_label: Label = _names.get(slot.index)
		if name_label != null:
			name_label.text = slot.label()
			name_label.add_theme_color_override("font_color", slot.color())


func _on_match_finished(winner: PlayerSlot) -> void:
	_banner.text = "%s WINS" % winner.label()
	_banner.add_theme_color_override("font_color", winner.color())
	_banner.visible = true
