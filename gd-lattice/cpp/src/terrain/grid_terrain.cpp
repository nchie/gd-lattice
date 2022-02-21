#include "grid_terrain.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void GridTerrain::_bind_methods() {
    // Methods.
    // ...

    // Properties.
    ADD_GROUP("Test group", "group_");
    ADD_SUBGROUP("Test subgroup", "group_subgroup_");

    ClassDB::bind_method(D_METHOD("get_terrain_data"), &GridTerrain::get_terrain_data);
    ClassDB::bind_method(D_METHOD("set_terrain_data", "terrain_data"), &GridTerrain::set_terrain_data);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "terrain_data", godot::PROPERTY_HINT_RESOURCE_TYPE, TerrainData::get_class_static()), "set_terrain_data", "get_terrain_data");

    // Signals.
    // ...
}

GridTerrain::GridTerrain() {
    UtilityFunctions::print("GridTerrain constructor.");
}

GridTerrain::~GridTerrain() {
    UtilityFunctions::print("GridTerrain destructor.");
}

// Methods.
void GridTerrain::set_terrain_data(const Ref<TerrainData> &p_terrain_data) {
    UtilityFunctions::print("Set terrain data.");
    _terrain_data = p_terrain_data;
}

Ref<TerrainData> GridTerrain::get_terrain_data() const {
    return _terrain_data;
}
