#ifndef RAYSH
#define RAYSH
#include <tuple.hpp>
#include <matrices.hpp>

class Ray {
    public:
        Tuple origin;
        Tuple direction;
        Ray();
        Ray(Tuple origin, Tuple direction);
        Tuple position(float t);
};

Ray transform(Ray r, Matrix m);

#endif
