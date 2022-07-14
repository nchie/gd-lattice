#include "terrain_stream.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;


namespace lattice {


void TerrainStream::_bind_methods() {
    // Methods.

    // Properties.
    ADD_GROUP("Test group", "group_");
    ADD_SUBGROUP("Test subgroup", "group_subgroup_");
    ClassDB::bind_method(D_METHOD("get_terrain_palette"), &TerrainStream::get_terrain_palette);
    ClassDB::bind_method(D_METHOD("set_terrain_palette", "terrain_palette"), &TerrainStream::set_terrain_palette);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "group_subgroup_terrain_palette", PROPERTY_HINT_RESOURCE_TYPE, "TerrainPalette"), "set_terrain_palette", "get_terrain_palette");

    // Signals.

    // Constants.
}

TerrainStream::TerrainStream() {
    UtilityFunctions::print("TerrainStream constructor.");
}

TerrainStream::~TerrainStream() {
    UtilityFunctions::print("TerrainStream destructor.");
}

void TerrainStream::set_terrain_palette(const godot::Ref<TerrainPalette> &terrain_palette) {
    _terrain_palette = terrain_palette;
}

godot::Ref<TerrainPalette> TerrainStream::get_terrain_palette() const {
    return _terrain_palette;
}

// Methods.

}