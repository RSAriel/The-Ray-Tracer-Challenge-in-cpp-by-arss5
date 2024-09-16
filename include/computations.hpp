#ifndef COMPUTATIONSH
#define COMPUTATIONSH

#include "intersections.hpp"

class Computations {
    public:
        double t;
        Sphere object;
        Tuple point;
        Tuple eyev;
        Tuple normalv;
        bool inside;

        Computations(double t, Sphere object, Tuple point, Tuple eyev, Tuple normalv);
};

Computations prepare_computations(Intersection i, Ray r);

#endif
