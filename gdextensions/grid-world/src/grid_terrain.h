#ifndef GRID_TERRAIN_CLASS_H
#define GRID_TERRAIN_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include "terrain_data.h"

using namespace godot;

class GridTerrainRef : public RefCounted {
	GDCLASS(GridTerrainRef, RefCounted);

protected:
	static void _bind_methods() {}

public:
	GridTerrainRef();
	~GridTerrainRef();
};

class GridTerrain : public Node3D {
	GDCLASS(GridTerrain, Node3D);

protected:
	static void _bind_methods();

private:
	Vector2 custom_position;

    Ref<TerrainData> terrain_data;

public:
	GridTerrain();
	~GridTerrain();

	// Functions.
    void set_terrain_data(const Ref<TerrainData> &terrain_data);
    Ref<TerrainData> get_terrain_data() const;
};

#endif
