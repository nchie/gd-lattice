cmake_minimum_required(VERSION 3.21)
project(lattice)

set(CMAKE_CXX_STANDARD 20)

set(GODOT_HEADERS_PATH  ../../../godot-cpp/godot-headers/)
set(CPP_BINDINGS_PATH ../../../godot-cpp)

string(TOLOWER ${CMAKE_SYSTEM_NAME} SYSTEM_NAME)
string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(OUTPUT_NAME lib${PROJECT_NAME}.${BUILD_TYPE})
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(OUTPUT_NAME ${PROJECT_NAME}.${BUILD_TYPE})
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(OUTPUT_NAME ${PROJECT_NAME}.${BUILD_TYPE})
else()
    message(FATAL_ERROR "Not implemented support for ${CMAKE_SYSTEM_NAME}")
endif()


# Change the output directory to the bin directory
set(BUILD_PATH ${CMAKE_SOURCE_DIR}/../bin/${TARGET_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_PATH}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_ARCHIVEOUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")


file(GLOB_RECURSE SOURCES src/*.c**)
file(GLOB_RECURSE HEADERS src/*.h**)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS} src/terrain/terrain_chunk_map.cpp src/terrain/terrain_chunk_map.h src/core/math/chunk_key.h src/terrain/terrain_chunk.cpp src/terrain/terrain_chunk.h src/terrain/terrain_type.cpp src/terrain/terrain_type.h)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DDEBUG_ENABLED -DDEBUG_METHODS_ENABLED)
set_target_properties(${PROJECT_NAME} PROPERTIES
        FRAMEWORK TRUE
        FRAMEWORK_VERSION C
        )
target_link_directories(${PROJECT_NAME}
        PRIVATE
        ${CPP_BINDINGS_PATH}/bin/
        )
target_link_libraries(${PROJECT_NAME}
        libgodot-cpp.osx.debug.universal.a
        )
target_include_directories(${PROJECT_NAME} SYSTEM
        PRIVATE
        ${CPP_BINDINGS_PATH}/include
        ${CPP_BINDINGS_PATH}/gen/include
        ${GODOT_HEADERS_PATH}
        )
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${OUTPUT_NAME})

