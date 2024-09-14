#ifndef INTERSECTIONSH
#define INTERSECTIONSH
#include <vector>
#include "spheres.hpp"
#include "rays.hpp"
#include "intersection.hpp"


class Intersections {
    public:
        std::vector<Intersection> list;

        Intersections();
        Intersections(std::vector<Intersection> xs);
        Intersections(Intersection i);
        Intersections(Intersection i1, Intersection i2);
        int size();
        void print();
        bool is_empty();
};

Intersections intersect(Sphere s, Ray r);

Intersection hit(Intersections xs);

#endif
