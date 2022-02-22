//
// Created by André Terranchie on 2022-02-22.
//

#ifndef LATTICE_LT_VECTOR3I_H
#define LATTICE_LT_VECTOR3I_H


#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/templates/hashfuncs.hpp>

struct LtVector3i {

    union {
        struct {
            int32_t x;
            int32_t y;
            int32_t z;
        };
        int coords[3];
    };

    LtVector3i() : x(0), y(0), z(0) {};
    LtVector3i(int xyz) : x(xyz), y(xyz), z(xyz) {}
    LtVector3i(int px, int py, int pz) : x(px), y(py), z(pz) {}
    LtVector3i(const LtVector3i &other) {
        *this = other;
    }

};


// For Godot
struct LtVector3iHasher {
    static _FORCE_INLINE_ uint32_t hash(const LtVector3i &v) {
        uint32_t hash = godot::hash_djb2_one_32(v.x);
        hash = godot::hash_djb2_one_32(v.y, hash);
        return godot::hash_djb2_one_32(v.z, hash);
    }

//    template <class T1, class T2>
//    std::size_t operator () (std::pair<T1, T2> const &v) const
//    {
//        return std::hash<T1>()(v.size());
//    }

    std::size_t operator () (const LtVector3i &v) const
    {
        return hash(v);
    }
};


#endif //LATTICE_LT_VECTOR3I_H
