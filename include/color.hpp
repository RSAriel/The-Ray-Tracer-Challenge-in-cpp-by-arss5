#ifndef COLORH
#define COLORH
#include "tuple.hpp"

class Color : public Tuple {
public:
    double red, green, blue;

    Color();
    Color(const Tuple& tuple);
    Color(double red, double green, double blue);
};

Color operator*(Color a, Color b);

#endif
