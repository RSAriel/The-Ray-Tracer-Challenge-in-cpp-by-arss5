#include "color.hpp"


Color::Color() : Tuple(0.0, 0.0, 0.0, 0.0) {
    this->red = 0.0;
    this->green = 0.0;
    this->blue = 0.0;
}

Color::Color(const Tuple& tuple) : Color(tuple.x, tuple.y, tuple.z) {}


Color::Color(double red, double green, double blue) : Tuple(red, green, blue, 0.0) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color operator*(Color a, Color b) {
    return Color(a.red * b.red, a.green * b.green, a.blue * b.blue);
}
