cmake_minimum_required(VERSION 3.21)
project(gridworld)

set(CMAKE_CXX_STANDARD 20)

set(GODOT_HEADERS_PATH  ../../../godot-headers/)
set(CPP_BINDINGS_PATH ../../../godot-cpp)

# Change the output directory to the bin directory
set(BUILD_PATH ${CMAKE_SOURCE_DIR}/bin/${TARGET_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_PATH}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")


file(GLOB_RECURSE SOURCES src/*.c**)
file(GLOB_RECURSE HEADERS src/*.h**)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${GODOT_CPP})
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

