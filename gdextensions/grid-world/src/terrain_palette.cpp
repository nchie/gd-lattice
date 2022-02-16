#include "terrain_palette.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

TerrainPaletteRef::TerrainPaletteRef() {
    UtilityFunctions::print("TerrainPaletteRef created.");
}

TerrainPaletteRef::~TerrainPaletteRef() {
    UtilityFunctions::print("TerrainPaletteRef destroyed.");
}

void TerrainPalette::_bind_methods() {
	// Methods.
	ClassDB::bind_method(D_METHOD("simple_func"), &TerrainPalette::simple_func);
	ClassDB::bind_method(D_METHOD("simple_const_func"), &TerrainPalette::simple_const_func);
	ClassDB::bind_method(D_METHOD("return_something"), &TerrainPalette::return_something);
	ClassDB::bind_method(D_METHOD("return_extended_ref"), &TerrainPalette::return_extended_ref);
	ClassDB::bind_method(D_METHOD("extended_ref_checks"), &TerrainPalette::extended_ref_checks);

	ClassDB::bind_method(D_METHOD("test_array"), &TerrainPalette::test_array);
	ClassDB::bind_method(D_METHOD("test_dictionary"), &TerrainPalette::test_dictionary);

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func", &TerrainPalette::varargs_func, mi);
	}

	// Properties.
	ADD_GROUP("Test group", "group_");
	ADD_SUBGROUP("Test subgroup", "group_subgroup_");

	ClassDB::bind_method(D_METHOD("get_custom_position"), &TerrainPalette::get_custom_position);
	ClassDB::bind_method(D_METHOD("set_custom_position", "position"), &TerrainPalette::set_custom_position);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "group_subgroup_custom_position"), "set_custom_position", "get_custom_position");

	// Signals.
	ADD_SIGNAL(MethodInfo("custom_signal", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::INT, "value")));
	ClassDB::bind_method(D_METHOD("emit_custom_signal", "name", "value"), &TerrainPalette::emit_custom_signal);

	// Constants.
	BIND_ENUM_CONSTANT(FIRST);
	BIND_ENUM_CONSTANT(ANSWER_TO_EVERYTHING);

	BIND_CONSTANT(CONSTANT_WITHOUT_ENUM);
}

TerrainPalette::TerrainPalette() {
	UtilityFunctions::print("Constructor ran!");
}

TerrainPalette::~TerrainPalette() {
	UtilityFunctions::print("Destructoar.");
}

// Methods.
void TerrainPalette::simple_func() {
	UtilityFunctions::print("Simple func called.");
}

void TerrainPalette::simple_const_func() const {
	UtilityFunctions::print("Simple const func called.");
}

String TerrainPalette::return_something(const String &base) {
	UtilityFunctions::print("Return something called.");
	return base;
}

TerrainPaletteRef *TerrainPalette::return_extended_ref() const {
	return memnew(TerrainPaletteRef());
}

Ref<TerrainPaletteRef> TerrainPalette::extended_ref_checks(Ref<TerrainPaletteRef> p_ref) const {
	Ref<TerrainPaletteRef> ref;
	ref.instantiate();
	// TODO the returned value gets dereferenced too early and return a null object otherwise.
	ref->reference();
	UtilityFunctions::print("TerrainPalette ref checks called with value: ", p_ref->get_instance_id(), ", returning value: ", ref->get_instance_id());
	return ref;
}

Variant TerrainPalette::varargs_func(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error) {
	UtilityFunctions::print("Varargs called with ", String::num((double)arg_count), " arguments");
	return arg_count;
}

void TerrainPalette::emit_custom_signal(const String &name, int value) {
	emit_signal("custom_signal", name, value);
}

Array TerrainPalette::test_array() const {
	Array arr;

	arr.resize(2);
	arr[0] = Variant(1);
	arr[1] = Variant(2);

	return arr;
}

Dictionary TerrainPalette::test_dictionary() const {
	Dictionary dict;

	dict["hello"] = "world";
	dict["foo"] = "bar";

	return dict;
}

// Properties.
void TerrainPalette::set_custom_position(const Vector2 &pos) {
	custom_position = pos;
}

Vector2 TerrainPalette::get_custom_position() const {
	return custom_position;
}
