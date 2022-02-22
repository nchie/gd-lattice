//
// Created by André Terranchie on 2022-02-22.
//

#ifndef LATTICE_CHUNK_KEY_H
#define LATTICE_CHUNK_KEY_H


#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/templates/hashfuncs.hpp>

namespace lattice {

struct ChunkKey {

    union {
        struct {
            int32_t x;
            int32_t y;
            int32_t z;
        };
        int coords[3];
    };

    ChunkKey() : x(0), y(0), z(0) {};

    ChunkKey(int xyz) : x(xyz), y(xyz), z(xyz) {}

    ChunkKey(int px, int py, int pz) : x(px), y(py), z(pz) {}

    ChunkKey(const ChunkKey &other) {
        *this = other;
    }

};


// For Godot
struct ChunkKeyHasher {
    static _FORCE_INLINE_ uint32_t hash(const ChunkKey &v) {
        uint32_t hash = godot::hash_djb2_one_32(v.x);
        hash = godot::hash_djb2_one_32(v.y, hash);
        return godot::hash_djb2_one_32(v.z, hash);
    }

    std::size_t operator()(const ChunkKey &v) const {
        return hash(v);
    }
};

}

#endif //LATTICE_CHUNK_KEY_H
