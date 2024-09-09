cmake_minimum_required(VERSION 3.25)
project(RayTracer)
enable_testing()
add_subdirectory(lib/Catch2)

add_executable(RayTracer src/main.cpp)
target_link_libraries(RayTracer PRIVATE Catch2::Catch2WithMain)

add_executable(RayTracerTests tests/test2.cpp tests/test1.cpp)  
target_link_libraries(RayTracerTests PRIVATE Catch2::Catch2WithMain)

include(CTest)
add_test(NAME RayTracerTests COMMAND RayTracerTests)

