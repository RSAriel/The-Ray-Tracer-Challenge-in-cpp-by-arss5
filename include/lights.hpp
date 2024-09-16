#ifndef LIGHTSH
#define LIGHTSH
#include "tuple.hpp"
#include "color.hpp"

class PointLight{
    public:
        Tuple position;
        Color intensity;
        PointLight();
        PointLight(Tuple position, Color intensity);
};

bool operator==(const PointLight& a, const PointLight& b);

#endif
