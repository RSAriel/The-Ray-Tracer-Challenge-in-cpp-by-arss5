#include "world.hpp"



World::World(){
    this->objects = std::vector<Sphere>(); 
    this->light = PointLight();
}

void World::add(Sphere s){
    this->objects.push_back(s);
}

World default_world(){
    World w;
    w.light = PointLight(Point(-10, 10, -10), Color(1, 1, 1));
    Sphere s1;
    s1.material.color = Color(0.8, 1.0, 0.6);
    s1.material.diffuse = 0.7;
    s1.material.specular = 0.2;
    Sphere s2;
    set_transform(s2, scaling(0.5, 0.5, 0.5));
    w.objects.push_back(s1);
    w.objects.push_back(s2);
    return w;
}

Intersections intersect_world(World w, Ray r){
    Intersections xs;
    for (Sphere s : w.objects){
        Intersections temp = intersect(s, r);
        for (Intersection i : temp.list){
            xs.add(i);
        }
    }
    xs.sort();
    return xs;
}

Color shade_hit(World world, Computations comps){
    return lighting(comps.object.material, world.light, comps.point, comps.eyev, comps.normalv);
}

Color color_at(World world, Ray r){
    Intersections xs = intersect_world(world, r);
    if (xs.is_empty()){
        return Color(0, 0, 0);
    }
    Intersection i = hit(xs);
    Computations comps = prepare_computations(i, r);
    return shade_hit(world, comps);
}