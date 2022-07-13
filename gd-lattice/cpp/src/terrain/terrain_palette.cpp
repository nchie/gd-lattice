#include "terrain_palette.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;


namespace lattice {


bool TerrainPalette::_set(const StringName &p_name, const Variant &p_value) {
    String name = p_name;

    return false;
}

bool TerrainPalette::_get(const StringName &p_name, Variant &r_ret) const {
    String name = p_name;

    if (name == "test_string") {
        r_ret = godot::String("test_name");
    } else {
        return false;
    }

    return true;
}

void TerrainPalette::_get_property_list(List<PropertyInfo> *p_list) const {
    p_list->push_back(PropertyInfo(Variant::STRING, "test_string"));
//    p_list->push_back(PropertyInfo(Variant::OBJECT, name + "mesh", PROPERTY_HINT_RESOURCE_TYPE, "Mesh"));
//    p_list->push_back(PropertyInfo(Variant::TRANSFORM3D, name + "mesh_transform"));
//    p_list->push_back(PropertyInfo(Variant::ARRAY, name + "shapes"));
//    p_list->push_back(PropertyInfo(Variant::OBJECT, name + "navmesh", PROPERTY_HINT_RESOURCE_TYPE, "NavigationMesh"));
//    p_list->push_back(PropertyInfo(Variant::TRANSFORM3D, name + "navmesh_transform"));
//    p_list->push_back(PropertyInfo(Variant::OBJECT, name + "preview", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_HELPER));
}


Array TerrainPalette::get_property_list() const {
    List<PropertyInfo> lpi;
    _get_property_list(&lpi);
    return convert_property_list(&lpi);
}

Array convert_property_list(const List<PropertyInfo> *p_list) {
    Array va;
    for (const List<PropertyInfo>::Element *E = p_list->front(); E; E = E->next()) {
//        va.push_back(godot::Dictionary(E->get()));

        PropertyInfo info = E->get();
        const Dictionary value = godot::Dictionary(info);
        va.push_back(value);
    }

    return va;
}


void TerrainPalette::_bind_methods() {
    // Methods.
//    ClassDB::bind_method(D_METHOD("set", "property", "value"), &TerrainPalette::set);
//    ClassDB::bind_method(D_METHOD("get", "property"), &TerrainPalette::get);
//    ClassDB::bind_method(D_METHOD("get_property_list"), &TerrainPalette::_get_property_list_bind);

    // Properties.


    // Signals.

    // Constants.
}

TerrainPalette::TerrainPalette() {
    UtilityFunctions::print("TerrainPalette constructor.");
}

TerrainPalette::~TerrainPalette() {
    UtilityFunctions::print("TerrainPalette Destructor.");
}

// Methods.

// Properties.

}