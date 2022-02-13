@tool
extends EditorPlugin
	
var panelScene = preload("res://addons/terrain-editor/panel.tscn")
var panel


func _enter_tree():
	# Initialization of the plugin goes here.
	panel = panelScene.instantiate()
	add_control_to_bottom_panel(panel, "Terrain")

func _exit_tree():
	# Clean-up of the plugin goes here.
	remove_control_from_bottom_panel(panel)
	panel.free()
