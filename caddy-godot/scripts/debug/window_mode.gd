extends Node
## Fullscreen handling, as an autoload so it works in every scene.
##
## The project boots fullscreen: running windowed at the default size made the
## arena occupy a small part of the screen, which makes car and map scale hard to
## judge. F11 or Alt+Enter drops back to a window when the editor needs the space.
##
## No class_name - a global class may not shadow an autoload name.

func _ready() -> void:
	process_mode = Node.PROCESS_MODE_ALWAYS


func _unhandled_input(event: InputEvent) -> void:
	var alt_enter: bool = (
		event is InputEventKey
		and event.pressed
		and not event.echo
		and event.keycode == KEY_ENTER
		and event.alt_pressed
	)
	if alt_enter or event.is_action_pressed("caddy_fullscreen"):
		toggle()
		get_viewport().set_input_as_handled()


func is_fullscreen() -> bool:
	var mode := DisplayServer.window_get_mode()
	return (
		mode == DisplayServer.WINDOW_MODE_FULLSCREEN
		or mode == DisplayServer.WINDOW_MODE_EXCLUSIVE_FULLSCREEN
	)


func toggle() -> void:
	DisplayServer.window_set_mode(
		DisplayServer.WINDOW_MODE_WINDOWED
		if is_fullscreen()
		else DisplayServer.WINDOW_MODE_FULLSCREEN
	)
