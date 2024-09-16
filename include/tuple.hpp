#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
#include <cmath>

const double EPSILON = 0.00001;

bool equal(double a, double b);

class Tuple {
public:
    double x, y, z, w;

    Tuple(double x, double y, double z, double w);
    Tuple();
    bool isVector();
    bool isPoint();
    double get(int index);
    void print();
};

Tuple Point(double x, double y, double z);
Tuple Vector(double x, double y, double z);

double magnitude(Tuple a);
Tuple normalize(Tuple a);
double dot(Tuple a, Tuple b);
Tuple cross(Tuple a, Tuple b);
Tuple reflect(Tuple in, Tuple normal);

bool operator==(Tuple a, Tuple b);
Tuple operator+(Tuple a, Tuple b);
Tuple operator-(Tuple a, Tuple b);
Tuple operator-(Tuple a);
Tuple operator*(Tuple a, double b);
Tuple operator/(Tuple a, double b);


#endif // TUPLE_H
