#ifndef COLORH
#define COLORH
#include "tuple.hpp"

class Color : public Tuple {
public:
    float red, green, blue;

    Color();
    Color(float red, float green, float blue);
};

Color operator*(Color a, Color b);

#endif
