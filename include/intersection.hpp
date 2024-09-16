#ifndef INTERSECTIONH
#define INTERSECTIONH
#include "spheres.hpp"

class Intersection {
    public:
        double t;
        Sphere object;
        Intersection();
        Intersection(double t, Sphere object);
        void print();
};

bool operator ==(Intersection const& i1, Intersection const& i2);

#endif
