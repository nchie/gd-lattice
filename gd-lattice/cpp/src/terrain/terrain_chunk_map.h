//
// Created by André Terranchie on 2022-02-22.
//

#ifndef LATTICE_TERRAIN_MESH_MAP_H
#define LATTICE_TERRAIN_MESH_MAP_H


#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/vector3i.hpp> // TODO: Remove
#include <godot_cpp/templates/hashfuncs.hpp>
#include <vector>
#include <unordered_map>

#include "../core/math/lt_vector3i.h"
#include "terrain_chunk.h"

class TerrainChunkMap {

private:
//    godot::HashMap<LtVector3i, size_t, LtVector3iHasher, godot::HashMapComparatorDefault<LtVector3i>, 3,2> _chunk_mesh_map;
    std::unordered_map<LtVector3i, size_t, LtVector3iHasher> _chunk_index_map;
    std::vector<std::optional<TerrainChunk>> _terrain_chunks;

public:
    TerrainChunkMap() :
        _chunk_index_map(),
        _terrain_chunks() {

    }



};


#endif //LATTICE_TERRAIN_MESH_MAP_H
