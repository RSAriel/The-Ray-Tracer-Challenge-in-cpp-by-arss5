#ifndef LIGHTSH
#define LIGHTSH
#include "tuple.hpp"
#include "color.hpp"

class PointLight{
    public:
        Tuple position;
        Color intensity;

        PointLight(Tuple position, Color intensity);
};


#endif
