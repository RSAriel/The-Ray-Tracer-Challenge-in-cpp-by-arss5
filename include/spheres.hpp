#ifndef SPHERESH
#define SPHERESH
#include <tuple.hpp>
#include <transformations.hpp>
#include <materials.hpp>

class Sphere {
    public:
        Tuple center;
        float radius;
        Matrix transformation;
        Material material;

        Sphere();
        Sphere(Tuple center, float radius);
};

void set_transform(Sphere &s, Matrix t);

Tuple normal_at(Sphere s, Tuple world_point);

bool operator==(const Sphere &lhs, const Sphere &rhs);

#endif
