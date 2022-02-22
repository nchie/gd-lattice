//
// Created by André Terranchie on 2022-02-22.
//

#ifndef LATTICE_TERRAIN_CHUNK_H
#define LATTICE_TERRAIN_CHUNK_H


#include <godot_cpp/variant/rid.hpp>

namespace lattice {


class TerrainChunk {

    struct MultimeshInstance {
        godot::RID instance;
        godot::RID multimesh;
    };

};
}

#endif //LATTICE_TERRAIN_CHUNK_H
