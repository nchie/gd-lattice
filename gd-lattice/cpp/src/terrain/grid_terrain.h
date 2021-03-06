//
// Created by André Terranchie on 2022-02-22.
//

#ifndef GRID_TERRAIN_CLASS_H
#define GRID_TERRAIN_CLASS_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include "terrain_stream.h"
#include "terrain_chunk_map.h"

namespace lattice {


class GridTerrain : public godot::Node3D {
GDCLASS(GridTerrain, Node3D);

private:
    TerrainChunkMap _terrain_chunk_map;

    godot::Ref<TerrainStream> _terrain_stream;
    uint32_t _collision_layer = 1;
    uint32_t _collision_mask = 1;

protected:
    static void _bind_methods();

public:
    GridTerrain();
    ~GridTerrain();

    // Functions.
    void set_terrain_stream(const godot::Ref<TerrainStream> &p_terrain_stream);
    godot::Ref<TerrainStream> get_terrain_stream() const;
    void set_collision_layer(uint32_t p_collision_layer);
    uint32_t get_collision_layer() const;
    void set_collision_mask(uint32_t p_collision_mask);
    uint32_t get_collision_mask() const;
};

}

#endif
