#include <intersection.hpp>
#define INT_MAX 2147483647

Intersection::Intersection() {
    this->t = INT_MAX;
    this->object = Sphere();
}

Intersection::Intersection(double t, Sphere object) {
    this->t = t;
    this->object = object;
}

void Intersection::print() {
    std::cout << "Intersection(t: " << t << ")";
}

bool operator==(Intersection const& i1, Intersection const& i2) {
    return i1.t == i2.t && i1.object == i2.object;
}
