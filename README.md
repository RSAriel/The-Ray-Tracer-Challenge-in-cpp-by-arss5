After completing a simple Ray Tracer in my Computer Graphics class, I became really interested in the subject and decided to dive deeper. I am currently rewriting the project, adding new functionalities while following the book The Ray Tracer Challenge, which uses a Test-Driven Development approach. This has been helpful in fixing bugs and addressing unknown behaviors from the previous version. My goal is to complete the book and implement additional features not originally covered, such as Anti-Aliasing, Motion Blur, Bounding Box, and more.

Finished chapter 7, currently working in a small bug that doesn't render the objects correctly in the world.


###How to run

This project was build using CMake using Linux, may not work on Windows. You need a ppm viewer to see the images generated, that could be a VSCode extension or an image editor

To build the project, run the following commands or just run ./script.sh:
    mdkir build && cd build && cmake .. && make 
    
./RayTracer runs what is on the Main.cpp files
./RayTracerTestes[tag] run all the test suites (the "tag" argument is optional use it to run a specific test suite, like [sphere] for example
