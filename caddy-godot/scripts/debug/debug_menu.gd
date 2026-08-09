extends CanvasLayer
## In-game tuning menu. Port of the Unreal debug panels, with live editing.
##
## Unreal's UCaddyVehicleDebugPanelProvider was read-only: it gathered rows of
## label/value for Core, Input, Tuning, Feel, Skill, Camera, Collision and
## DebugDraw. Same panels here, but the tuning ones are editable and can be
## written back to their .tres, which is what the read-only version could not do.
##
## Toggle with F1.

const TELEMETRY_REFRESH := 0.1

@export var match_manager: MatchManager
## Used when there is no match, e.g. the single-car test track.
@export var vehicle: ArcadeVehicle
@export var camera_rig: VehicleCameraRig

var _tabs: TabContainer
var _telemetry_label: RichTextLabel
var _status_label: Label
var _save_button: Button
var _revert_button: Button
var _confirm: ConfirmationDialog

var _panels: Array[TuningPanel] = []
var _telemetry_vehicle: ArcadeVehicle
var _telemetry_skill: BrakeDashSkill
var _telemetry_combat: VehicleCombat
var _telemetry_momentum: VehicleMomentum
var _last_contest := "none"
var _telemetry_timer := 0.0


func _ready() -> void:
	layer = 10
	# Must keep responding while a hit stop has the rest of the tree near-frozen.
	process_mode = Node.PROCESS_MODE_ALWAYS
	_build_ui()
	visible = false
	# Deferred so the match has spawned its cars before we look for them.
	_bind_targets.call_deferred()
	ClashArbiter.contest_resolved.connect(_on_contest_resolved)


func _on_contest_resolved(
	first: ArcadeVehicle,
	second: ArcadeVehicle,
	winner: ArcadeVehicle,
	outcome: ClashArbiter.Outcome,
	closing_speed: float,
	_position: Vector3
) -> void:
	if outcome == ClashArbiter.Outcome.CLASH:
		_last_contest = "CLASH  %s vs %s  @ %.1f m/s" % [first.name, second.name, closing_speed]
		return
	var loser := second if winner == first else first
	_last_contest = (
		"%s beat %s  (%s vs %s)  @ %.1f m/s"
		% [
			winner.name,
			loser.name,
			MomentumTier.name_of(ClashArbiter.tier_of(winner)),
			MomentumTier.name_of(ClashArbiter.tier_of(loser)),
			closing_speed,
		]
	)


func _unhandled_input(event: InputEvent) -> void:
	if event.is_action_pressed("caddy_debug_toggle"):
		visible = not visible
		get_viewport().set_input_as_handled()


func _process(delta: float) -> void:
	if not visible:
		return
	_telemetry_timer -= delta
	if _telemetry_timer <= 0.0:
		_telemetry_timer = TELEMETRY_REFRESH
		_update_telemetry()


# ---------------------------------------------------------------------------
# Construction
# ---------------------------------------------------------------------------

func _build_ui() -> void:
	var root := PanelContainer.new()
	root.set_anchors_preset(Control.PRESET_LEFT_WIDE)
	root.offset_left = 12.0
	root.offset_top = 12.0
	root.offset_right = 480.0
	root.offset_bottom = -12.0
	add_child(root)

	var column := VBoxContainer.new()
	column.add_theme_constant_override("separation", 6)
	root.add_child(column)

	var header := Label.new()
	header.text = "DEBUG  ·  F1 to close"
	header.add_theme_font_size_override("font_size", 16)
	column.add_child(header)

	_status_label = Label.new()
	_status_label.add_theme_font_size_override("font_size", 12)
	column.add_child(_status_label)

	var buttons := HBoxContainer.new()
	buttons.add_theme_constant_override("separation", 6)
	column.add_child(buttons)

	_save_button = Button.new()
	_save_button.text = "Save changes"
	_save_button.pressed.connect(_on_save_pressed)
	buttons.add_child(_save_button)

	_revert_button = Button.new()
	_revert_button.text = "Revert"
	_revert_button.pressed.connect(_on_revert_pressed)
	buttons.add_child(_revert_button)

	_tabs = TabContainer.new()
	_tabs.size_flags_vertical = Control.SIZE_EXPAND_FILL
	_tabs.custom_minimum_size = Vector2(0, 520)
	column.add_child(_tabs)

	_confirm = ConfirmationDialog.new()
	_confirm.title = "Save tuning to disk?"
	_confirm.ok_button_text = "Save"
	_confirm.dialog_autowrap = false
	_confirm.confirmed.connect(_on_save_confirmed)
	add_child(_confirm)

	_refresh_status()


## Finds the tuning resources on the local player's car and builds a tab each.
func _bind_targets() -> void:
	var car := _resolve_vehicle()
	if car == null:
		_status_label.text = "No vehicle found."
		return

	_telemetry_vehicle = car
	for child in car.get_children():
		if child is BrakeDashSkill:
			_telemetry_skill = child
		elif child is VehicleCombat:
			_telemetry_combat = child

	_add_telemetry_tab()

	# Same eight areas Unreal exposed, minus the ones with nothing to tune.
	_add_tuning_tab(car.tuning, "Handling")
	if _telemetry_skill != null:
		_add_tuning_tab(_telemetry_skill.tuning, "Skill")
	for child in car.get_children():
		if child is VehicleFeel:
			_add_tuning_tab(child.tuning, "Feel")
		elif child is ImpactAdjudicator:
			_add_tuning_tab(child.tuning, "Impact")
		elif child is ImpactFx:
			_add_tuning_tab(child.tuning, "Hit FX")
		elif child is DriftTrail:
			_add_tuning_tab(child.tuning, "Trail")
		elif child is VehicleMomentum:
			_telemetry_momentum = child
			_add_tuning_tab(child.tuning, "Momentum")
	if _telemetry_combat != null:
		_add_tuning_tab(_telemetry_combat.tuning, "Combat")
	var rig := _resolve_camera_rig()
	if rig != null:
		_add_tuning_tab(rig.tuning, "Camera")

	_refresh_status()


func _add_tuning_tab(resource: Resource, title: String) -> void:
	if resource == null:
		return

	var scroll := ScrollContainer.new()
	scroll.name = title
	scroll.horizontal_scroll_mode = ScrollContainer.SCROLL_MODE_DISABLED

	var panel := TuningPanel.new()
	panel.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	scroll.add_child(panel)
	_tabs.add_child(scroll)
	# setup() after the tree add so the built widgets are already parented.
	panel.setup(resource, title)
	panel.dirty_changed.connect(_on_panel_dirty_changed)
	_panels.append(panel)


func _add_telemetry_tab() -> void:
	var scroll := ScrollContainer.new()
	scroll.name = "Live"
	_telemetry_label = RichTextLabel.new()
	_telemetry_label.bbcode_enabled = true
	_telemetry_label.fit_content = true
	_telemetry_label.scroll_active = false
	_telemetry_label.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	scroll.add_child(_telemetry_label)
	_tabs.add_child(scroll)


func _resolve_vehicle() -> ArcadeVehicle:
	if vehicle != null:
		return vehicle
	if match_manager != null:
		for slot in match_manager.slots:
			if match_manager.vehicles.has(slot.index):
				return match_manager.vehicles[slot.index]
	return null


func _resolve_camera_rig() -> VehicleCameraRig:
	if camera_rig != null:
		return camera_rig
	if match_manager != null and match_manager.camera_rig != null:
		return match_manager.camera_rig
	var rigs := get_tree().get_nodes_in_group(VehicleCameraRig.CAMERA_RIG_GROUP)
	return rigs[0] if not rigs.is_empty() else null


# ---------------------------------------------------------------------------
# Save / revert
# ---------------------------------------------------------------------------

func _total_dirty() -> int:
	var total := 0
	for panel in _panels:
		total += panel.dirty_count()
	return total


func _on_panel_dirty_changed(_panel: TuningPanel, _count: int) -> void:
	_refresh_status()


func _refresh_status() -> void:
	var dirty := _total_dirty()
	if _status_label != null:
		_status_label.text = (
			"%d unsaved change%s" % [dirty, "" if dirty == 1 else "s"] if dirty > 0
			else "No unsaved changes"
		)
		_status_label.add_theme_color_override(
			"font_color", TuningPanel.DIRTY_COLOR if dirty > 0 else TuningPanel.CLEAN_COLOR
		)
	if _save_button != null:
		_save_button.disabled = dirty == 0
	if _revert_button != null:
		_revert_button.disabled = dirty == 0

	# Mark the tab itself so a change is findable without opening every tab.
	for i in _panels.size():
		var panel := _panels[i]
		var tab_index := _tabs.get_children().find(panel.get_parent())
		if tab_index >= 0:
			_tabs.set_tab_title(
				tab_index, "%s *" % panel.title if panel.dirty_count() > 0 else panel.title
			)


func _on_save_pressed() -> void:
	if _total_dirty() == 0:
		return

	var lines := PackedStringArray()
	for panel in _panels:
		if panel.dirty_count() > 0:
			lines.append("%s  (%d)" % [panel.title, panel.dirty_count()])
			lines.append(panel.describe_changes())
	_confirm.dialog_text = (
		"Overwrite the tuning files on disk with these values?\n\n%s" % "\n".join(lines)
	)
	_confirm.popup_centered()


func _on_save_confirmed() -> void:
	var saved := 0
	var failed := PackedStringArray()
	for panel in _panels:
		if panel.dirty_count() == 0:
			continue
		if panel.save() == OK:
			saved += 1
		else:
			failed.append(panel.title)

	_refresh_status()
	if failed.is_empty():
		_status_label.text = "Saved %d file%s" % [saved, "" if saved == 1 else "s"]
		_status_label.add_theme_color_override("font_color", Color(0.5, 0.9, 0.6))
	else:
		_status_label.text = "Failed to save: %s" % ", ".join(failed)
		_status_label.add_theme_color_override("font_color", Color(1.0, 0.45, 0.4))


func _on_revert_pressed() -> void:
	for panel in _panels:
		panel.revert()
	_refresh_status()


# ---------------------------------------------------------------------------
# Telemetry (the read-only half of the Unreal panels)
# ---------------------------------------------------------------------------

func _update_telemetry() -> void:
	if _telemetry_label == null or _telemetry_vehicle == null:
		return

	var car := _telemetry_vehicle
	var lines := PackedStringArray()

	lines.append("[b]Core[/b]")
	lines.append(_row("speed", "%.2f m/s  (%.0f km/h)" % [car.get_planar_speed(), car.get_planar_speed() * 3.6]))
	lines.append(_row("forward", "%.2f" % car.get_forward_speed()))
	lines.append(_row("lateral", "%.2f   <- drift" % car.get_lateral_speed()))
	lines.append(_row("yaw", "%.1f deg" % rad_to_deg(car.rotation.y)))
	lines.append(_row("drifting", "yes" if car.is_drifting else "no"))
	lines.append(_row("reverse steer", "on" if car.reverse_steering_active else "off"))
	lines.append(_row("locked / external", "%s / %s" % [car.control_locked, car.external_velocity_control]))

	lines.append("")
	lines.append("[b]Input[/b]")
	lines.append(_row("throttle", "%.2f" % car.throttle_input))
	lines.append(_row("brake", "%.2f" % car.brake_reverse_input))
	lines.append(_row("grip", "%.2f" % car.grip_input))
	lines.append(_row("intent", "%.1f deg" % rad_to_deg(UeMath.heading_to_yaw(car.move_intent)) if car.has_move_intent else "none"))

	if _telemetry_skill != null:
		lines.append("")
		lines.append("[b]Skill[/b]")
		lines.append(_row("state", ["ready", "braking", "charging", "dashing"][_telemetry_skill.state]))
		lines.append(_row("charge", "%.2f s  alpha %.2f" % [_telemetry_skill.current_charge_seconds, _telemetry_skill.current_charge_alpha]))
		lines.append(_row("override speed", "%.2f" % _telemetry_skill.current_override_speed))
		lines.append(_row("cooldown", "%.2f s" % _telemetry_skill.cooldown_remaining))

	if _telemetry_momentum != null:
		lines.append("")
		lines.append("[b]Momentum[/b]")
		lines.append(_row("tier", "%s  (charge %.2f)" % [
			MomentumTier.name_of(_telemetry_momentum.tier), _telemetry_momentum.charge
		]))
		lines.append(_row("slip", "%.2f m/s" % _telemetry_momentum.slip()))
		lines.append(_row("last contest", _last_contest))

	if _telemetry_combat != null:
		lines.append("")
		lines.append("[b]Combat[/b]")
		lines.append(_row("health", "%.0f / %.0f" % [_telemetry_combat.health, _telemetry_combat.tuning.max_health]))
		lines.append(_row("knockback", "%.2f s" % _telemetry_combat.knockback_remaining))
		lines.append(_row("stagger", "%.2f s" % _telemetry_combat.stagger_remaining))

	var hit := car.last_collision
	if hit != null:
		lines.append("")
		lines.append("[b]Collision[/b]")
		lines.append(_row("age", "%.2f s" % car.get_time_since_last_collision()))
		lines.append(_row("last", hit.describe()))

	lines.append("")
	lines.append("[b]Time[/b]")
	lines.append(_row("time scale", "%.2f" % Engine.time_scale))
	lines.append(_row("hit stop", "freeze %.3f  slow %.3f" % [HitStop.freeze_remaining, HitStop.slow_remaining]))

	var rig := _resolve_camera_rig()
	if rig != null:
		lines.append("")
		lines.append("[b]Camera[/b]")
		lines.append(_row("arm / pitch / fov", "%.1f  %.1f  %.1f" % [rig.current_arm_length, rig.current_pitch_deg, rig.current_fov]))
		lines.append(_row("trauma", "%.2f" % rig.trauma))

	_telemetry_label.text = "\n".join(lines)


func _row(label: String, value: String) -> String:
	return "[color=#7f8794]%s[/color]  %s" % [label.rpad(18), value]
