#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
#include <cmath>

const float EPSILON = 0.00001;

bool equal(float a, float b);

class Tuple {
public:
    float x, y, z, w;

    Tuple(float x, float y, float z, float w);
    Tuple();

    bool isVector();
    bool isPoint();
    void print();
};

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

float magnitude(Tuple a);
Tuple normalize(Tuple a);
float dot(Tuple a, Tuple b);
Tuple cross(Tuple a, Tuple b);

bool operator==(Tuple a, Tuple b);
Tuple operator+(Tuple a, Tuple b);
Tuple operator-(Tuple a, Tuple b);
Tuple operator-(Tuple a);
Tuple operator*(Tuple a, float b);
Tuple operator/(Tuple a, float b);

#endif // TUPLE_H
