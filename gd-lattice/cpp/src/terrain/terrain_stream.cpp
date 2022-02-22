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

    // Signals.

    // Constants.
}

TerrainStream::TerrainStream() {
    UtilityFunctions::print("TerrainStream constructor.");
}

TerrainStream::~TerrainStream() {
    UtilityFunctions::print("TerrainStream destructor.");
}

// Methods.

}