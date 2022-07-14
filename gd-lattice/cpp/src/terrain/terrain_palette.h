//
// Created by André Terranchie on 2022-02-22.
//

#ifndef TERRAIN_PALETTE_CLASS_H
#define TERRAIN_PALETTE_CLASS_H

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/templates/list.hpp>
#include <unordered_map>

#include "terrain_type.h"

namespace lattice {


class TerrainPalette : public godot::Resource {
    GDCLASS(TerrainPalette, Resource);

    std::unordered_map<size_t, TerrainType> _terrain_types;
    godot::String _custom_string;
    godot::Vector2 custom_position;


protected:
    bool _set(const godot::StringName &p_name, const godot::Variant &p_value);
    bool _get(const godot::StringName &p_name, godot::Variant &r_ret) const;
    void _get_property_list(godot::List<godot::PropertyInfo> *p_list) const;

    void set(const godot::StringName &p_name, const godot::Variant &p_value);
    godot::Variant get(const godot::StringName &p_name) const;
    godot::Array get_property_list() const;

    // Property.
    void set_custom_string(const godot::String &custom_string);
    godot::String get_custom_string() const;

    void set_custom_position(const godot::Vector2 &pos);
    godot::Vector2 get_custom_position() const;
    static void _bind_methods();

public:
    TerrainPalette();
    ~TerrainPalette();

    // Functions.

    void create_terrain_type();

    // Property.
};


//godot::Array convert_property_list(const godot::List<godot::PropertyInfo> *p_list);
//
}

#endif
