#ifndef WORLDH
#define WORLDH
#include <vector>
#include "lights.hpp"
#include "spheres.hpp"
#include "intersections.hpp"
#include "materials.hpp"
#include "computations.hpp"

class World {
    public:
        std::vector<Sphere> objects;
        PointLight light;

        World();
        void add(Sphere s);
};

World default_world();
Intersections intersect_world(World w, Ray r);
Color shade_hit(World world, Computations comps);
Color color_at(World world, Ray r);

#endif