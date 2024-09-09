cmake_minimum_required(VERSION 3.25)
project(RayTracer)
enable_testing()
add_subdirectory(lib/Catch2)

include_directories(PRIVATE ${CMAKE_SOURCE_DIR}/include)


add_executable(RayTracerTests tests/tuple.cpp )  
target_link_libraries(RayTracerTests PRIVATE Catch2::Catch2WithMain)


include(CTest)
add_test(NAME RayTracerTests COMMAND RayTracerTests)

