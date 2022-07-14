#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "terrain/grid_terrain.h"
#include "terrain/terrain_palette.h"
#include "terrain/terrain_stream.h"
#include "example.h"

using namespace godot;

void register_types(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    ClassDB::register_class<ExampleRef>();
    ClassDB::register_class<Example>();
    ClassDB::register_class<lattice::TerrainStream>();
    ClassDB::register_class<lattice::GridTerrain>();
    ClassDB::register_class<lattice::TerrainPalette>();
}

void unregister_types(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {

// Initialization.
GDNativeBool GDN_EXPORT init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

    init_obj.register_initializer(register_types);
    init_obj.register_terminator(unregister_types);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}
