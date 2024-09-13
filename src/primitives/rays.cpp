#include <rays.hpp>

Ray::Ray() {
    origin = Point(0, 0, 0);
    direction = Vector(0, 0, 0);
}

Ray::Ray(Tuple origin, Tuple direction) {
    this->origin = origin;
    this->direction = direction;
}

Tuple Ray::position(float t) {
    return origin + direction * t;
}

void Ray::print() {
    std::cout << "origin: ";
    origin.print();
    std::cout << "direction: ";
    direction.print();
}

Ray transform(Ray r, Matrix m) {
    return Ray(m * r.origin, m * r.direction);
}