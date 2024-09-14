#ifndef INTERSECTIONH
#define INTERSECTIONH
#include "spheres.hpp"

class Intersection {
    public:
        float t;
        Sphere object;
        Intersection();
        Intersection(float t, Sphere object);
        void print();
};

bool operator ==(Intersection const& i1, Intersection const& i2);

#endif
