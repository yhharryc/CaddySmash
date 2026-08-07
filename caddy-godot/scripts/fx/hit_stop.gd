extends Node
## Autoload that owns Engine.time_scale for hit emphasis.
##
## Two stages: a near-freeze that sells the moment of contact, then a slow-motion
## tail that eases back to full speed. Anything eased, never a hard step back.
##
## It has to be a single owner. Four cars colliding in the same frame would
## otherwise each write time_scale and the last one would win, so requests are
## merged here instead: the strongest freeze and the longest slow survive.
##
## No class_name - Godot rejects a global class that shadows an autoload name.

## Not literally zero: at exactly 0 nothing advances at all, including the
## effects that are supposed to be playing through the freeze.
const FREEZE_SCALE := 0.02

signal hit_stop_started(freeze_seconds: float, slow_seconds: float)
signal hit_stop_finished

@export var enabled: bool = true

var freeze_remaining := 0.0
var slow_remaining := 0.0
var slow_total := 0.0
var slow_scale := 0.35

var _last_ticks_usec := 0


func _ready() -> void:
	# Must keep running while the rest of the tree is frozen.
	process_mode = Node.PROCESS_MODE_ALWAYS
	_last_ticks_usec = Time.get_ticks_usec()


func is_active() -> bool:
	return freeze_remaining > 0.0 or slow_remaining > 0.0


## Merges into any hit stop already running rather than replacing it.
func request(freeze_seconds: float, slow_seconds: float, scale: float = 0.35) -> void:
	if not enabled:
		return

	var was_active := is_active()
	freeze_remaining = maxf(freeze_remaining, maxf(0.0, freeze_seconds))
	if slow_seconds > slow_remaining:
		slow_remaining = slow_seconds
		slow_total = slow_seconds
		slow_scale = clampf(scale, 0.01, 1.0)
	else:
		# A weaker request still deepens the slow if it asks for one.
		slow_scale = minf(slow_scale, clampf(scale, 0.01, 1.0))

	if not was_active:
		hit_stop_started.emit(freeze_remaining, slow_remaining)


func cancel() -> void:
	freeze_remaining = 0.0
	slow_remaining = 0.0
	slow_total = 0.0
	Engine.time_scale = 1.0


func _process(_delta: float) -> void:
	# Real elapsed time: the frame delta is itself scaled by what we set here, so
	# using it would make the freeze stretch itself indefinitely.
	var now := Time.get_ticks_usec()
	var real_delta := float(now - _last_ticks_usec) / 1_000_000.0
	_last_ticks_usec = now
	if real_delta <= 0.0:
		return
	# A stalled frame (window drag, breakpoint) must not eat the whole effect.
	real_delta = minf(real_delta, 0.1)

	if freeze_remaining > 0.0:
		freeze_remaining -= real_delta
		Engine.time_scale = FREEZE_SCALE
		return

	if slow_remaining > 0.0:
		slow_remaining -= real_delta
		var t := 1.0 - clampf(slow_remaining / maxf(0.0001, slow_total), 0.0, 1.0)
		# Eases back to full speed instead of snapping, which would read as a hitch.
		Engine.time_scale = lerpf(slow_scale, 1.0, Easing.in_out_cubic(t))
		if slow_remaining <= 0.0:
			Engine.time_scale = 1.0
			hit_stop_finished.emit()
		return

	if not is_equal_approx(Engine.time_scale, 1.0):
		Engine.time_scale = 1.0
