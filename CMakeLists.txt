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

add_executable(RayTracerTests include/tuple.cpp include/color.cpp include/canvas.cpp tests/tuple_test.cpp  tests/canvas_test.cpp )  
target_link_libraries(RayTracerTests PRIVATE Catch2::Catch2WithMain)

include_directories(PRIVATE ${CMAKE_SOURCE_DIR}/include)


include(CTest)
add_test(NAME RayTracerTests COMMAND RayTracerTests)

