#ifndef CANVASH
#define CANVASH
#include "color.hpp"
#include <vector>
#include <fstream>
#include <cstdlib>

class Canvas {
public: 
    int width, height;
    std::vector<std::vector<Color>> pixels;

    Canvas(int width, int height);
    void write_pixel(int x, int y, Color color);
    std::string canvas_to_ppm();
    void set_color(Color color);
    Color pixel_at(int x, int y);
};

    void print_ppm(std::string ppm);



#endif