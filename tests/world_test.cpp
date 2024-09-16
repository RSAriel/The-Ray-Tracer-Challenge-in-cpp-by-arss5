#include <catch2/catch_all.hpp>
#include "world.hpp"
#include "lights.hpp"
#include "spheres.hpp"
#include "rays.hpp"
#include "intersections.hpp"
#include "computations.hpp"

TEST_CASE( "Creating a world", "[world]") {
    World w;
    REQUIRE(w.objects.empty());
    REQUIRE(w.light == PointLight());
}

TEST_CASE ( "The default world", "[world]") {
    PointLight light(Point(-10, 10, -10), Color(1, 1, 1));
    Sphere s1;
    s1.material.color = Color(0.8, 1.0, 0.6);
    s1.material.diffuse = 0.7;
    s1.material.specular = 0.2;
    Sphere s2;
    set_transform(s2, scaling(0.5, 0.5, 0.5));
    World w = default_world();
    REQUIRE(w.light == light);
    REQUIRE(w.objects.size() == 2);
    REQUIRE(w.objects[0] == s1);
    REQUIRE(w.objects[1] == s2);
}

TEST_CASE ( "Intersect a world with a ray", "[world]") {
    World w = default_world();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Intersections xs = intersect_world(w, r);
    REQUIRE(xs.list.size() == 4);
    REQUIRE(xs.list[0].t == 4);
    REQUIRE(xs.list[1].t == 4.5);
    REQUIRE(xs.list[2].t == 5.5);
    REQUIRE(xs.list[3].t == 6);
}

TEST_CASE ( "Precomputing the state of an intersection", "[world]" ){
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere shape = Sphere();
    Intersection i(4, shape);
    Computations comps = prepare_computations(i, r);
    REQUIRE(comps.t == i.t);
    REQUIRE(comps.object == i.object);
    REQUIRE(comps.point == Point(0, 0, -1));
    REQUIRE(comps.eyev == Vector(0, 0, -1));
    REQUIRE(comps.normalv == Vector(0, 0, -1));
}

TEST_CASE ( "The hit when an intersection occurs on the outside", "[world]" ){
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere shape = Sphere();
    Intersection i(4, shape);
    Computations comps = prepare_computations(i, r);
    REQUIRE(comps.inside == false);
}

TEST_CASE ( "The hit when an intersection occurs on the inside", "[world]" ){
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    Sphere shape = Sphere();
    Intersection i(1, shape);
    Computations comps = prepare_computations(i, r);
    REQUIRE(comps.point == Point(0, 0, 1));
    REQUIRE(comps.eyev == Vector(0, 0, -1));
    REQUIRE(comps.inside == true);
    REQUIRE(comps.normalv == Vector(0, 0, -1));
}

TEST_CASE ( "Shading an intersection", "[world]" ){
    World w = default_world();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere shape = w.objects[0];
    Intersection i(4, shape);
    Computations comps = prepare_computations(i, r);
    Color c = shade_hit(w, comps);
    REQUIRE(c == Color(0.38066, 0.47583, 0.2855));
}

TEST_CASE ( "Shading an intersection from the inside", "[world]" ){
    World w = default_world();
    w.light = PointLight(Point(0, 0.25, 0), Color(1, 1, 1));
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    Sphere shape = w.objects[1];
    Intersection i(0.5, shape);
    Computations comps = prepare_computations(i, r);
    Color c = shade_hit(w, comps);
    REQUIRE(c == Color(0.90498, 0.90498, 0.90498));
}

TEST_CASE ( "The color when a ray misses", "[world]" ){
    World w = default_world();
    Ray r(Point(0, 0, -5), Vector(0, 1, 0));
    Color c = color_at(w, r);
    REQUIRE(c == Color(0, 0, 0));
}

TEST_CASE ( "The color when a ray hits", "[world]" ){
    World w = default_world();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Color c = color_at(w, r);
    REQUIRE(c == Color(0.38066, 0.47583, 0.2855));
}

TEST_CASE ( "The color with an intersection behind the ray", "[world]" ){
    World w = default_world();
    Sphere outer = w.objects[0];
    outer.material.ambient = 1;
    Sphere inner = w.objects[1];
    inner.material.ambient = 1;
    Ray r(Point(0, 0, 0.75), Vector(0, 0, -1));
    Color c = color_at(w, r);
    REQUIRE(c == inner.material.color);
}