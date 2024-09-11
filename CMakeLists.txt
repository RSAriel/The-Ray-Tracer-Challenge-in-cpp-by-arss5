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

include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_library(Primitives
    src/primitives/tuple.cpp
    src/primitives/color.cpp
    src/primitives/canvas.cpp
    src/primitives/matrices.cpp
    src/primitives/transformations.cpp
)

add_executable(RayTracerTests tests/tuple_test.cpp  tests/canvas_test.cpp tests/matrices_test.cpp tests/transformations_test.cpp)  
target_link_libraries(RayTracerTests PRIVATE Primitives Catch2::Catch2WithMain)


include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/include)


include(CTest)
add_test(NAME RayTracerTests COMMAND RayTracerTests)

