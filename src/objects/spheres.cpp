#include "spheres.hpp"
#
Sphere::Sphere() {
    Matrix identity = Matrix(4, 4);
    identity.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    center = Point(0, 0, 0);
    radius = 1;
    this->transformation = identity;
    this->material = Material();
}

Sphere::Sphere(Tuple center, float radius) {
    Matrix identity = Matrix(4, 4);
    identity.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    this->center = center;
    this->radius = radius;
    this->transformation = identity;
    this->material = Material();

}
    

void set_transform(Sphere &s, Matrix t) {
    s.transformation = s.transformation * t;
    
}

Tuple normal_at(Sphere s, Tuple world_point) {
    Tuple object_point = s.transformation.inverse() * world_point;
    Tuple object_normal = object_point - Point(0, 0, 0);
    Tuple world_normal = s.transformation.inverse().transpose() * object_normal;
    world_normal.w = 0;
    return normalize(world_normal);
}

bool operator==(const Sphere &lhs, const Sphere &rhs) {
    return lhs.center == rhs.center && lhs.radius == rhs.radius;
}