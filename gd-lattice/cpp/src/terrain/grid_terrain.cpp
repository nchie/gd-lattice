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

    ClassDB::bind_method(D_METHOD("get_terrain_stream"), &GridTerrain::get_terrain_stream);
    ClassDB::bind_method(D_METHOD("set_terrain_stream", "terrain_stream"), &GridTerrain::set_terrain_stream);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "terrain_stream", godot::PROPERTY_HINT_RESOURCE_TYPE, TerrainStream::get_class_static()), "set_terrain_stream", "get_terrain_stream");

    ClassDB::bind_method(D_METHOD("get_collision_layer"), &GridTerrain::get_collision_layer);
    ClassDB::bind_method(D_METHOD("set_collision_layer", "mask"), &GridTerrain::set_collision_layer);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "collision_layer", godot::PROPERTY_HINT_LAYERS_3D_PHYSICS), "set_collision_layer", "get_collision_layer");

    ClassDB::bind_method(D_METHOD("get_collision_mask"), &GridTerrain::get_collision_mask);
    ClassDB::bind_method(D_METHOD("set_collision_mask", "mask"), &GridTerrain::set_collision_mask);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "collision_mask", godot::PROPERTY_HINT_LAYERS_3D_PHYSICS), "set_collision_mask", "get_collision_mask");


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
void GridTerrain::set_terrain_stream(const Ref<TerrainStream> &p_terrain_stream) {
    UtilityFunctions::print("Set terrain data.");
    _terrain_stream = p_terrain_stream;
}

Ref<TerrainStream> GridTerrain::get_terrain_stream() const {
    return _terrain_stream;
}


void GridTerrain::set_collision_layer(uint32_t p_collision_layer) {
    _collision_layer = p_collision_layer;
    // TODO: Iterate meshes
}

uint32_t GridTerrain::get_collision_layer() const {
    return _collision_layer;
}

void GridTerrain::set_collision_mask(uint32_t p_collision_mask) {
    _collision_mask = p_collision_mask;
    // TODO: Iterate meshes
}

uint32_t GridTerrain::get_collision_mask() const {
    return _collision_mask;
}
