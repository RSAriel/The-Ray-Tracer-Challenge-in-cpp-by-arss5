#include <catch2/catch_all.hpp>
#include "intersection.hpp"
#include "intersections.hpp"
#include "spheres.hpp"

const int INT_MIN = -2147483648;

TEST_CASE ( "An intersection encapsulates t and object", "[intersections]" ) {
    Sphere s = Sphere();
    Intersection i = Intersection(3.5, s);
    REQUIRE( i.t == 3.5 );
    REQUIRE( i.object == s );
}

TEST_CASE( "Aggregating intersections", "[intersections]" ) {
    Sphere s = Sphere();
    Intersection i1 = Intersection(1, s);
    Intersection i2 = Intersection(2, s);
    Intersections intersections = {i1, i2};
    REQUIRE( intersections.list.size() == 2 );
    REQUIRE( intersections.list[0].t == 1 );
    REQUIRE( intersections.list[1].t == 2 );
}

TEST_CASE( "Intersect sets the object on the intersection", "[intersections]" ) {
    Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    Intersections xs = intersect(s, r);
    REQUIRE( xs.list.size() == 2 );
    REQUIRE( xs.list[0].object == s );
    REQUIRE( xs.list[1].object == s );
}

TEST_CASE( "The hit, when all intersections have positive t", "[intersections]" ) {
    Sphere s = Sphere();
    Intersection i1 = Intersection(1, s);
    Intersection i2 = Intersection(2, s);
    Intersections xs = {i1, i2};
    Intersection i = hit(xs);
    REQUIRE( i == i1 );
}

TEST_CASE ( "The hit, when some intersections have negative t", "[intersections]" ) {
    Sphere s = Sphere();
    Intersection i1 = Intersection(-1, s);
    Intersection i2 = Intersection(1, s);
    Intersections xs = {i2, i1};
    Intersection i = hit(xs);
    REQUIRE( i == i2 );
}

TEST_CASE( "The hit, when all intersections have negative t", "[intersections]" ) {
    Sphere s = Sphere();
    Intersection i1 = Intersection(-1, s);
    Intersection i2 = Intersection(-2, s);
    Intersections xs = {i1, i2};
    Intersection i = hit(xs);
    REQUIRE( i.t == INT_MIN);
}

TEST_CASE( "The hit is always the lowest nonnegative intersection", "[intersections]" ) {
    Sphere s = Sphere();
    Intersection i1 = Intersection(5, s);
    Intersection i2 = Intersection(7, s);
    Intersection i3 = Intersection(-3, s);
    Intersection i4 = Intersection(2, s);
    Intersections xs({i1, i2, i3, i4});
    Intersection i = hit(xs);
    REQUIRE( i == i4 );
}