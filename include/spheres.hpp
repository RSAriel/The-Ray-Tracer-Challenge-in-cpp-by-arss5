#ifndef SPHERESH
#define SPHERESH
#include <tuple.hpp>
#include <transformations.hpp>

class Sphere {
    public:
        Tuple center;
        float radius;
        Matrix transformation;

        Sphere();
        Sphere(Tuple center, float radius);
};

void set_transform(Sphere &s, Matrix t);

bool operator==(const Sphere &lhs, const Sphere &rhs);

#endif
