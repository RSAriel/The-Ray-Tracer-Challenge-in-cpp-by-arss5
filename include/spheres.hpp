#ifndef SPHERESH
#define SPHERESH
#include <tuple.hpp>

class Sphere {
    public:
        Tuple center;
        float radius;

        Sphere();
        Sphere(Tuple center, float radius);
};


bool operator==(const Sphere &lhs, const Sphere &rhs);

#endif
