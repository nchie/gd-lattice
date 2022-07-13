//
// Created by André Terranchie on 2022-02-22.
//

#ifndef TERRAIN_STREAM_CLASS_H
#define TERRAIN_STREAM_CLASS_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

namespace lattice {


class TerrainStream : public godot::Resource {
GDCLASS(TerrainStream, Resource);

protected:
    static void _bind_methods();

public:
    TerrainStream();

    ~TerrainStream();

    // Constants.

    // Functions.

    // Property.

};

}

#endif
