#ifndef TERRAIN_DATA_CLASS_H
#define TERRAIN_DATA_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;


class TerrainDataRef : public RefCounted {
GDCLASS(TerrainDataRef, RefCounted);

protected:
    static void _bind_methods() {}

public:
    TerrainDataRef();
    ~TerrainDataRef();
};


class TerrainData : public Resource {
	GDCLASS(TerrainData, Resource);

protected:
	static void _bind_methods();

private:

public:
    TerrainData();
    ~TerrainData();

	// Constants.

	// Functions.

	// Property.

};

#endif
