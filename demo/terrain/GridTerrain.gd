extends GridTerrain


# Called when the node enters the scene tree for the first time.
func _ready():
	var res = preload("new_terrain_data.tres")
	set_terrain_data(res)
	pass # Replace with function body.
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
