#include "terrain_data.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

TerrainDataRef::TerrainDataRef() {
    UtilityFunctions::print("TerrainDataRef created.");
}

TerrainDataRef::~TerrainDataRef() {
    UtilityFunctions::print("TerrainDataRef destroyed.");
}

void TerrainData::_bind_methods() {
    // Methods.

    // Properties.

    // Signals.

    // Constants.
}

TerrainData::TerrainData() {
    UtilityFunctions::print("TerrainData constructor.");
}

TerrainData::~TerrainData() {
    UtilityFunctions::print("TerrainData destructor.");
}

// Methods.
