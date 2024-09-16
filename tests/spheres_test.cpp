#include <catch2/catch_all.hpp>
#include "spheres.hpp"
#include "rays.hpp"
#include "intersections.hpp"
#include "transformations.hpp"
#include "materials.hpp"

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

TEST_CASE ( "A spheres's default transformation", "[spheres]" ) {
    Sphere s = Sphere();
    REQUIRE( s.transformation == identity());
}

TEST_CASE ( "Changing a sphere's transformation", "[spheres]" ) {
    Sphere s = Sphere();
    auto t = translation(2, 3, 4);
    set_transform(s, t);
    REQUIRE( s.transformation == t);
}

TEST_CASE ( "Intersecting a scaled sphere with a ray", "[spheres]") {
    Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    set_transform(s, scaling(2, 2, 2));
    auto xs = intersect(s, r);
    REQUIRE( xs.size() == 2);
    REQUIRE( xs.list[0].t == 3);
    REQUIRE( xs.list[1].t == 7);
}

TEST_CASE ( "Intersecting a translated sphere with a ray", "[spheres]") {
    Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    set_transform(s, translation(5, 0, 0));
    auto xs = intersect(s, r);
    REQUIRE( xs.size() == 0);
}

TEST_CASE ( "The normal on a sphere at a point on the x axis", "[spheres]") {
    Sphere s = Sphere();
    auto n = normal_at(s, Point(1, 0, 0));
    REQUIRE( n == Vector(1, 0, 0));   
}

TEST_CASE ( "The normal on a sphere at a point on the y axis", "[spheres]") {
    Sphere s = Sphere();
    auto n = normal_at(s, Point(0, 1, 0));
    REQUIRE( n == Vector(0, 1, 0));   
}

TEST_CASE ( "The normal on a sphere at a point on the z axis", "[spheres]") {
    Sphere s = Sphere();
    auto n = normal_at(s, Point(0, 0, 1));
    REQUIRE( n == Vector(0, 0, 1));   
}

TEST_CASE ( "The normal on a sphere at a nonaxial point", "[spheres]") {
    Sphere s = Sphere();
    auto n = normal_at(s, Point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
    REQUIRE( n == Vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));   
}

TEST_CASE ( "The normal is a normalized vector", "[spheres]") {
    Sphere s = Sphere();
    auto n = normal_at(s, Point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
    REQUIRE( n == normalize(n));   
}

TEST_CASE ( "Computing the normal on a translated sphere", "[spheres]") {
    Sphere s = Sphere();
    set_transform(s, translation(0, 1, 0));
    auto n = normal_at(s, Point(0, 1.70711, -0.70711));
    REQUIRE( n == Vector(0, 0.70711, -0.70711));   
}

TEST_CASE ( "Computing the normal on a transformed sphere", "[spheres]") {
    Sphere s = Sphere();
    auto m = scaling(1, 0.5, 1) * rotation_z(M_PI/5);
    set_transform(s, m);
    auto n = normal_at(s, Point(0, sqrt(2)/2, -sqrt(2)/2));
    REQUIRE( n == Vector(0, 0.97014, -0.24254));   
}

TEST_CASE ( "A sphere has a default material", "[spheres]") {
    Sphere s = Sphere();
    auto m = s.material;
    REQUIRE( m == Material());
}

TEST_CASE ( "A sphere may be assigned a material", "[spheres]") {
    Sphere s = Sphere();
    Material m;
    m.ambient = 1;
    s.material = m;
    REQUIRE( s.material == m);
}