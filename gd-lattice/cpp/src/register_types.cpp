#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "terrain/grid_terrain.h"
#include "terrain/terrain_palette.h"
#include "terrain/terrain_stream.h"

using namespace godot;

void register_types() {
    ClassDB::register_class<TerrainStream>();
    ClassDB::register_class<GridTerrain>();
    ClassDB::register_class<TerrainPalette>();
}

void unregister_types() {}

extern "C" {

// Initialization.
GDNativeBool GDN_EXPORT init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

    init_obj.register_scene_initializer(register_types);
    init_obj.register_scene_terminator(unregister_types);

    return init_obj.init();
}
}
