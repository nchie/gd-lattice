//
// Created by André Terranchie on 2022-02-22.
//

#ifndef LATTICE_TERRAIN_CHUNK_MAP_H
#define LATTICE_TERRAIN_CHUNK_MAP_H


#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/vector3i.hpp> // TODO: Remove
#include <godot_cpp/templates/hashfuncs.hpp>
#include <vector>
#include <unordered_map>

#include "../core/math/chunk_key.h"
#include "terrain_chunk.h"


namespace lattice {


class TerrainChunkMap {

private:
    std::unordered_map<ChunkKey, size_t, ChunkKeyHasher> _chunk_index_map;
    std::vector<std::optional<TerrainChunk>> _terrain_chunks;

public:
    TerrainChunkMap() :
            _chunk_index_map(),
            _terrain_chunks() {
    }

};

}

#endif //LATTICE_TERRAIN_CHUNK_MAP_H
