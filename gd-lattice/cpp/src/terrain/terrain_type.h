//
// Created by André Terranchie on 2022-02-23.
//

#ifndef LATTICE_TERRAIN_TYPE_H
#define LATTICE_TERRAIN_TYPE_H

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <unordered_map>

namespace lattice {


const size_t TILE_AMOUNT = 45;

class TerrainType {
    enum TileId {
        // Middle
        _0_0,
        _0_1,
        _0_5,
        _0_7,
        _0_17,
        _0_21,
        _0_23,
        _0_29,
        _0_31,
        _0_85,
        _0_87,
        _0_95,
        _0_119,
        _0_127,
        _0_255,

        // Top
        _1_0,
        _1_1,
        _1_5,
        _1_7,
        _1_17,
        _1_21,
        _1_23,
        _1_29,
        _1_31,
        _1_85,
        _1_87,
        _1_95,
        _1_119,
        _1_127,
        _1_255,

        // Bottom
        _2_0,
        _2_1,
        _2_5,
        _2_7,
        _2_17,
        _2_21,
        _2_23,
        _2_29,
        _2_31,
        _2_85,
        _2_87,
        _2_95,
        _2_119,
        _2_127,
        _2_255
    };

    struct Tile {
        std::string name;
        godot::Ref<godot::Mesh> mesh;
        godot::Transform3D mesh_transform;

//        Ref<NavigationMesh> navmesh;
//        Transform3D navmesh_transform;
    };

    std::unordered_map<TileId, std::vector<Tile>> _tile_map;

public:


};

}

#endif //LATTICE_TERRAIN_TYPE_H
