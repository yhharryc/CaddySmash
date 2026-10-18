class_name NetVehicleState
extends RefCounted
## Wire layout for what NetMatchSync sends every tick: one input frame from each
## client, one snapshot of every car from the host.
##
## Plain packed float arrays rather than dictionaries. A dictionary serialises its
## key strings into every packet; at 60 snapshots a second that is most of the
## bandwidth, and bigger packets are what fragment and jitter over the relay.
##
## Kept leaf-level on purpose, the same way ImpactTier is: it reads the vehicle
## nodes but nothing references back into the networking layer.

## Floats in one input frame.
const INPUT_SIZE := 6

## Not named Input: that would shadow the engine singleton.
enum InputField {
	MOVE_X,
	MOVE_Y,
	THROTTLE,
	BRAKE,
	GRIP,
	SKILL,
}

## Floats per car in a snapshot.
const STRIDE := 12

enum Field {
	SLOT,
	POS_X,
	POS_Z,
	YAW,
	VEL_X,
	VEL_Z,
	HEALTH,
	SKILL_STATE,
	SKILL_CHARGE,
	SKILL_COOLDOWN,
	TIER,
	FLAGS,
}

const FLAG_EXTERNAL_VELOCITY := 1
const FLAG_CONTROL_LOCKED := 2
const FLAG_SKILL_DASHING := 4


## One tick of held input, already dead-zoned by the device.
static func encode_input(device: InputDevice) -> PackedFloat32Array:
	var frame := PackedFloat32Array()
	frame.resize(INPUT_SIZE)
	if device == null:
		return frame
	var stick := device.get_move_vector()
	frame[InputField.MOVE_X] = stick.x
	frame[InputField.MOVE_Y] = stick.y
	frame[InputField.THROTTLE] = device.get_throttle()
	frame[InputField.BRAKE] = device.get_brake()
	frame[InputField.GRIP] = device.get_grip()
	frame[InputField.SKILL] = 1.0 if device.is_skill_pressed() else 0.0
	return frame


## Appends one car to a snapshot. Planar only: the car never leaves its ride
## height, so Y position and pitch/roll would be wasted bytes.
static func write_vehicle(
	out: PackedFloat32Array,
	slot_index: int,
	vehicle: ArcadeVehicle,
	combat: VehicleCombat,
	skill: BrakeDashSkill,
	momentum: VehicleMomentum
) -> void:
	var flags := 0
	if vehicle.external_velocity_control:
		flags |= FLAG_EXTERNAL_VELOCITY
	if vehicle.control_locked:
		flags |= FLAG_CONTROL_LOCKED
	if vehicle.skill_dashing:
		flags |= FLAG_SKILL_DASHING

	out.append(float(slot_index))
	out.append(vehicle.global_position.x)
	out.append(vehicle.global_position.z)
	out.append(vehicle.rotation.y)
	out.append(vehicle.velocity.x)
	out.append(vehicle.velocity.z)
	out.append(combat.health if combat != null else 0.0)
	out.append(float(skill.state) if skill != null else 0.0)
	out.append(skill.current_charge_alpha if skill != null else 0.0)
	out.append(skill.cooldown_remaining if skill != null else 0.0)
	out.append(float(momentum.tier) if momentum != null else 0.0)
	out.append(float(flags))


static func has_flag(entry: PackedFloat32Array, flag: int) -> bool:
	return (int(entry[Field.FLAGS]) & flag) != 0
