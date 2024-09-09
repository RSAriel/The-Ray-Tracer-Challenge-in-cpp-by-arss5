to build the project, run the following commands:
    cd build
    cmake ..
    make
or just use script.sh

I should add each test case inside 
    add_executable(RayTracerTests tests/test2.cpp tests/test1.cpp)  
    from the CMakeLists.txt file.