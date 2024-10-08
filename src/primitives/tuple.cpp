#include "tuple.hpp"

bool equal(float a, float b) {
    return abs(a - b) < EPSILON;
}


Tuple::Tuple(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Tuple::Tuple() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
    this->w = 0.0;
}


bool Tuple::isVector() {
    return w == 0.0;
}

bool Tuple::isPoint() {
    return w == 1.0;
}

float Tuple::get(int index) {
    switch (index) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            return -1;
    }
}

void Tuple::print() {
    std::cout << "x: " << x << " y: " << y << " z: " << z << " w: " << w << std::endl;
}

Tuple Point(float x, float y, float z) {
    return Tuple(x, y, z, 1.0);
}

Tuple Vector(float x, float y, float z) {
    return Tuple(x, y, z, 0.0);
}

float magnitude(Tuple a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

Tuple normalize(Tuple a) {
    float mag = magnitude(a);
    return Tuple(a.x / mag, a.y / mag, a.z / mag, a.w / mag);
}

float dot(Tuple a, Tuple b) {
    float sum = a.x * b.x + a.y * b.y + a.z * b.z;
    return sum;
}

Tuple cross(Tuple a, Tuple b) {
    return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

Tuple reflect(Tuple in, Tuple normal) {
    return in - normal * 2 * dot(in, normal);
}

bool operator==(Tuple a, Tuple b) {
    return equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z) && equal(a.w,b.w);
}

Tuple operator+(Tuple a, Tuple b) {
    return Tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Tuple operator-(Tuple a, Tuple b) {
    return Tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

Tuple operator-(Tuple a) {
    return Tuple(-a.x, -a.y, -a.z, -a.w);
}

Tuple operator*(Tuple a, float b) {
    return Tuple(a.x * b, a.y * b, a.z * b, a.w * b);
}

Tuple operator/(Tuple a, float b) {
    return Tuple(a.x / b, a.y / b, a.z / b, a.w / b);
}

