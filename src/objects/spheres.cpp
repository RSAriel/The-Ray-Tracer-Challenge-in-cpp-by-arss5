#include "spheres.hpp"
#
Sphere::Sphere() {
    Matrix identity = Matrix(4, 4);
    identity.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    center = Point(0, 0, 0);
    radius = 1;
    this->transformation = identity;
}

Sphere::Sphere(Tuple center, float radius) {
    Matrix identity = Matrix(4, 4);
    identity.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    this->center = center;
    this->radius = radius;
    this->transformation = identity;

}
    

void set_transform(Sphere &s, Matrix t) {
    s.transformation = s.transformation * t;
    
}

bool operator==(const Sphere &lhs, const Sphere &rhs) {
    return lhs.center == rhs.center && lhs.radius == rhs.radius;
}