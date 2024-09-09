#ifndef CANVASH
#define CANVASH
#include "color.hpp"

class Canvas {
    public: 
    int width, height;
    std::vector<std::vector<Color>> pixels;

    Canvas(int width, int height) {
        pixels.resize(width, std::vector<Color>(height, Color(0, 0, 0)));
        Color pixels[width][height];
        this->width = width;
        this->height = height;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                pixels[i][j] = Color(0, 0, 0);
            }
        }
    }

};


#endif