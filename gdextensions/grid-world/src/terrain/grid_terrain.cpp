#include "grid_terrain.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

GridTerrainRef::GridTerrainRef() {
    UtilityFunctions::print("GridTerrainRef created.");
}

GridTerrainRef::~GridTerrainRef() {
    UtilityFunctions::print("GridTerrainRef destroyed.");
}

void GridTerrain::_bind_methods() {
    // Methods.
    // ...

    // Properties.
    ADD_GROUP("Test group", "group_");
    ADD_SUBGROUP("Test subgroup", "group_subgroup_");

    ClassDB::bind_method(D_METHOD("get_terrain_data"), &GridTerrain::get_terrain_data);
    ClassDB::bind_method(D_METHOD("set_terrain_data", "position"), &GridTerrain::set_terrain_data);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "terrain_data", PROPERTY_HINT_RESOURCE_TYPE, "TerrainData"), "set_terrain_data", "get_terrain_data");

    // Signals.
    // ...
}

GridTerrain::GridTerrain() {
    UtilityFunctions::print("Constructor ran!");
}

GridTerrain::~GridTerrain() {
    UtilityFunctions::print("Destructoar.");
}

// Methods.
void GridTerrain::set_terrain_data(const Ref<TerrainData> &terrain_data) {
    this->terrain_data = terrain_data;
}

Ref<TerrainData> GridTerrain::get_terrain_data() const {
    return terrain_data;
}
