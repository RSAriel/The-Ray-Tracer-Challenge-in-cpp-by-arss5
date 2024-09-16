cmake_minimum_required(VERSION 3.25)
project(RayTracer)
enable_testing()

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

set(TEST_SOURCES
    tests/tuple_test.cpp 
    tests/canvas_test.cpp
    tests/matrices_test.cpp
    tests/transformations_test.cpp
    tests/rays_test.cpp
    tests/spheres_test.cpp
    tests/intersections_test.cpp
    tests/lights_test.cpp
    tests/materials_test.cpp
    tests/world_test.cpp
    
)

include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_library(Primitives
    src/primitives/tuple.cpp
    src/primitives/color.cpp
    src/primitives/canvas.cpp
    src/primitives/matrices.cpp
    src/primitives/transformations.cpp
    src/primitives/rays.cpp
    src/primitives/intersection.cpp
    src/primitives/intersections.cpp
)

add_library(Objects
    src/objects/spheres.cpp
    src/objects/materials.cpp
)

add_library(Lights
    src/lights/lights.cpp
)

add_library(Scene
    src/scene/world.cpp
    src/scene/computations.cpp
)

add_executable(RayTracer src/main.cpp)  
target_link_libraries(RayTracer PRIVATE Primitives Objects Lights Scene Catch2::Catch2WithMain)

add_executable(RayTracerTests ${TEST_SOURCES})  
target_link_libraries(RayTracerTests PRIVATE Primitives Objects Lights Scene Catch2::Catch2WithMain)


include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/include)


include(CTest)
add_test(NAME RayTracerTests COMMAND RayTracerTests)

