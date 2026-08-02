extends CanvasLayer
## Telemetry readout mirroring the UE vehicle debug panel, so feel changes can be
## compared against the Unreal build number for number.

@export var vehicle: ArcadeVehicle
@export var camera_rig: VehicleCameraRig
@export var skill: BrakeDashSkill
@export var combat: VehicleCombat
@export var target_combat: VehicleCombat

const _SKILL_NAMES := ["READY", "BRAKING", "CHARGING", "DASHING"]

@onready var _label: Label = $Panel/Label

var _last_impact: ImpactEvent = null


func _ready() -> void:
	set_process(vehicle != null)
	var adjudicator := _find_adjudicator()
	if adjudicator != null:
		adjudicator.impact_dealt.connect(func(impact: ImpactEvent) -> void: _last_impact = impact)


func _find_adjudicator() -> ImpactAdjudicator:
	if vehicle == null:
		return null
	for child in vehicle.get_children():
		if child is ImpactAdjudicator:
			return child
	return null


func _unhandled_input(event: InputEvent) -> void:
	if event.is_action_pressed("caddy_debug_toggle"):
		visible = not visible
		get_viewport().set_input_as_handled()


func _process(_delta: float) -> void:
	if not visible or vehicle == null:
		return

	var lines := PackedStringArray()
	lines.append("[F1] toggle   [R] reset")
	lines.append("")
	lines.append("speed      %6.2f m/s  (%5.1f km/h)" % [
		vehicle.get_planar_speed(), vehicle.get_planar_speed() * 3.6
	])
	lines.append("forward    %6.2f m/s" % vehicle.get_forward_speed())
	lines.append("lateral    %6.2f m/s   <- drift" % vehicle.get_lateral_speed())
	lines.append("")
	lines.append("throttle   %5.2f" % vehicle.throttle_input)
	lines.append("brake/rev  %5.2f" % vehicle.brake_reverse_input)
	lines.append("grip       %5.2f" % vehicle.grip_input)
	lines.append("state      %s" % ("DRIFT" if vehicle.is_drifting else "GRIP"))
	lines.append("friction   %5.2f" % (
		vehicle.tuning.drift_lateral_friction if vehicle.is_drifting
		else vehicle.tuning.grip_lateral_friction
	))
	lines.append("")
	lines.append("intent     %s" % (
		"%6.2f deg" % rad_to_deg(UeMath.heading_to_yaw(vehicle.move_intent))
		if vehicle.has_move_intent else "  none"
	))
	lines.append("yaw        %6.2f deg" % rad_to_deg(vehicle.rotation.y))
	lines.append("reverse steer  %s" % ("ON" if vehicle.reverse_steering_active else "off"))
	lines.append("locked/ext     %s / %s" % [vehicle.control_locked, vehicle.external_velocity_control])

	if skill != null:
		lines.append("")
		lines.append("skill      %-9s  t %4.2f" % [_SKILL_NAMES[skill.state], skill.state_elapsed])
		lines.append("charge     %5.2f s -> alpha %4.2f" % [
			skill.current_charge_seconds, skill.current_charge_alpha
		])
		lines.append("dash       %5.2f m/s  cd %4.2f s" % [
			skill.current_override_speed, skill.cooldown_remaining
		])
		if skill.using_target_aim and skill.current_target != null:
			lines.append("target     %s" % skill.current_target.name)

	if combat != null:
		lines.append("")
		lines.append("health     %5.1f / %.0f" % [combat.health, combat.tuning.max_health])
		if combat.is_knocked_back():
			lines.append("KNOCKBACK  %4.2f s left" % combat.knockback_remaining)
		if combat.is_staggered():
			lines.append("STAGGER    %4.2f s left" % combat.stagger_remaining)

	if target_combat != null:
		lines.append("target hp  %5.1f / %.0f%s" % [
			target_combat.health,
			target_combat.tuning.max_health,
			"  STAGGERED" if target_combat.is_staggered() else "",
		])

	var hit := vehicle.last_collision
	if hit != null:
		lines.append("")
		lines.append("last hit   %5.2f s ago" % vehicle.get_time_since_last_collision())
		lines.append("  %s" % hit.describe())

	if _last_impact != null:
		lines.append("last impact")
		lines.append("  %s" % _last_impact.describe())

	if camera_rig != null:
		lines.append("")
		lines.append("cam alpha  %5.2f   arm %5.2f  fov %5.1f" % [
			camera_rig.speed_alpha, camera_rig.current_arm_length, camera_rig.current_fov
		])
		lines.append("cam roll   %5.2f deg  lag %5.2f" % [
			camera_rig.current_roll_deg, camera_rig.current_lag_speed
		])

	_label.text = "\n".join(lines)
