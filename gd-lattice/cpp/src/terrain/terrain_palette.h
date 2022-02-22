//
// Created by André Terranchie on 2022-02-22.
//

#ifndef TERRAIN_PALETTE_CLASS_H
#define TERRAIN_PALETTE_CLASS_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include "terrain_stream.h"

using namespace godot;

namespace lattice {


class TerrainPalette : public Resource {
GDCLASS(TerrainPalette, Resource);

protected:
    static void _bind_methods();

private:

public:
    TerrainPalette();

    ~TerrainPalette();

    // Constants.

    // Functions.

    // Property.
};

}

#endif
