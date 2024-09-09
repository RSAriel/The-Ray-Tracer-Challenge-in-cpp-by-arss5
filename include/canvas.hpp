#ifndef CANVASH
#define CANVASH
#include "color.hpp"
#include <vector>

class Canvas {
public: 
    int width, height;
    std::vector<std::vector<Color>> pixels;

    Canvas(int width, int height);

};


#endif