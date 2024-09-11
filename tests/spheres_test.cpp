#include <catch2/catch_all.hpp>
#include "spheres.hpp"
#include "rays.hpp"
#include "intersections.hpp"

TEST_CASE( "A ray intersects a sphere at two points", "[spheres]" ) {
    Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto intersections = intersect(s, r);
    REQUIRE (intersections.size() == 2);
    REQUIRE( intersections.list[0].t == 4 );
    REQUIRE( intersections.list[1].t == 6 );
}

TEST_CASE( "A ray intersects a sphere at a tangent", "[spheres]" ) {
    Ray r = Ray(Point(0, 1, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto intersections = intersect(s, r);
    REQUIRE (intersections.size() == 2);
    REQUIRE( intersections.list[0].t == 5 );
    REQUIRE( intersections.list[1].t == 5 );
}

TEST_CASE ( "A ray misses a sphere", "[spheres]" ) {
    Ray r = Ray(Point(0, 2, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto intersections = intersect(s, r);
    REQUIRE (intersections.size() == 0);
}

TEST_CASE ( "A ray originates inside a sphere", "[spheres]" ) {
    Ray r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto intersections = intersect(s, r);
    REQUIRE (intersections.size() == 2);
    REQUIRE( intersections.list[0].t == -1 );
    REQUIRE( intersections.list[1].t == 1 );
}

TEST_CASE ( "A sphere is behind a ray", "[spheres]" ) {
    Ray r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto intersections = intersect(s, r);
    REQUIRE (intersections.size() == 2);
    REQUIRE( intersections.list[0].t == -6 );
    REQUIRE( intersections.list[1].t == -4 );
}

TEST_CASE ( "Intersect sets the object on the intersection", "[spheres]" ) {
    Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    auto intersections = intersect(s, r);
    REQUIRE (intersections.size() == 2);
    REQUIRE( intersections.list[0].t == 4 );
    REQUIRE( intersections.list[1].t == 6 );
}
