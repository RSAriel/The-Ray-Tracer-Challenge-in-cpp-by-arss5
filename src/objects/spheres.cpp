#include "spheres.hpp"

Sphere::Sphere() {
    center = Point(0, 0, 0);
    radius = 1;
}

Sphere::Sphere(Tuple center, float radius) {
    this->center = center;
    this->radius = radius;
}
    

bool operator==(const Sphere &lhs, const Sphere &rhs) {
    return lhs.center == rhs.center && lhs.radius == rhs.radius;
}