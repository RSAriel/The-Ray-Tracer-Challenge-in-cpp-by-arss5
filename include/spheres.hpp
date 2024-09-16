#ifndef SPHERESH
#define SPHERESH
#include <tuple.hpp>
#include <transformations.hpp>
#include <materials.hpp>

class Sphere {
    public:
        Tuple center;
        double radius;
        Matrix transformation;
        Material material;

        Sphere();
        Sphere(Tuple center, double radius);
};

void set_transform(Sphere &s, Matrix t);

Tuple normal_at(Sphere s, Tuple world_point);

bool operator==(const Sphere &lhs, const Sphere &rhs);

#endif
