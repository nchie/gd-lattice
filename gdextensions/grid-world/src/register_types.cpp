#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "grid_terrain.h"
#include "terrain_palette.h"
#include "terrain_data.h"

using namespace godot;

void register_example_types() {
	ClassDB::register_class<GridTerrainRef>();
	ClassDB::register_class<GridTerrain>();

    ClassDB::register_class<TerrainPaletteRef>();
    ClassDB::register_class<TerrainPalette>();

    ClassDB::register_class<TerrainDataRef>();
    ClassDB::register_class<TerrainData>();
}

void unregister_example_types() {}

extern "C" {

// Initialization.

GDNativeBool GDN_EXPORT example_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_scene_initializer(register_example_types);
	init_obj.register_scene_terminator(unregister_example_types);

	return init_obj.init();
}
}
