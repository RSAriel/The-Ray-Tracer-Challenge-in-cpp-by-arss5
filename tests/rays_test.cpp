#include <catch2/catch_all.hpp>
#include "rays.hpp"
#include "tuple.hpp"
#include "transformations.hpp"

TEST_CASE( "Creating and querying a ray", "[rays]" ) {
    auto origin = Point(1, 2, 3);
    auto direction = Vector(4, 5, 6);
    Ray r = Ray(origin, direction);
    REQUIRE( r.origin == origin );
    REQUIRE( r.direction == direction );
}

TEST_CASE ( "Computing a point from a distance", "[rays]" ) {
    Ray r = Ray(Point(2, 3, 4), Vector(1, 0, 0));
    REQUIRE( r.position(0) == Point(2, 3, 4) );
    REQUIRE( r.position(1) == Point(3, 3, 4) );
    REQUIRE( r.position(-1) == Point(1, 3, 4) );
    REQUIRE( r.position(2.5) == Point(4.5, 3, 4) );
}

TEST_CASE ( "Translating a ray", "[rays]" ) {
    Ray r = Ray(Point(1, 2, 3), Vector(0, 1, 0));
    Matrix m = translation(3, 4, 5);
    Ray r2 = transform(r,m);
    REQUIRE( r2.origin == Point(4, 6, 8) );
    REQUIRE( r2.direction == Vector(0, 1, 0) );
}

TEST_CASE ( "Scaling a ray", "[rays]" ) {
    Ray r = Ray(Point(1, 2, 3), Vector(0, 1, 0));
    Matrix m = scaling(2, 3, 4);
    Ray r2 = transform(r, m);
    REQUIRE( r2.origin == Point(2, 6, 12) );
    REQUIRE( r2.direction == Vector(0, 3, 0) );
}