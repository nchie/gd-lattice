#ifndef TERRAIN_PALETTE_CLASS_H
#define TERRAIN_PALETTE_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;


class TerrainPaletteRef : public RefCounted {
GDCLASS(TerrainPaletteRef, RefCounted);

protected:
    static void _bind_methods() {}

public:
    TerrainPaletteRef();
    ~TerrainPaletteRef();
};


class TerrainPalette : public Resource {
	GDCLASS(TerrainPalette, Resource);

protected:
	static void _bind_methods();

private:
	Vector2 custom_position;

public:
	// Constants.
	enum Constants {
		FIRST,
		ANSWER_TO_EVERYTHING = 42,
	};

	enum {
		CONSTANT_WITHOUT_ENUM = 314,
	};

	TerrainPalette();
	~TerrainPalette();

	// Functions.
	void simple_func();
	void simple_const_func() const;
	String return_something(const String &base);
	TerrainPaletteRef *return_extended_ref() const;
	Ref<TerrainPaletteRef> extended_ref_checks(Ref<TerrainPaletteRef> p_ref) const;
	Variant varargs_func(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	void emit_custom_signal(const String &name, int value);

	Array test_array() const;
	Dictionary test_dictionary() const;

	// Property.
	void set_custom_position(const Vector2 &pos);
	Vector2 get_custom_position() const;

	// Virtual function override (no need to bind manually).
//	virtual bool _has_point(const Vector2 &point) const override;
};

VARIANT_ENUM_CAST(TerrainPalette, Constants);

#endif // ! EXAMPLE_CLASS_H
