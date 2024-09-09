#include <catch2/catch_all.hpp>
#include "tuple.hpp"

TEST_CASE( "A tuple with w=1.0 is a point ", "[tuple]" ) {
    Tuple a(4.3, -4.2, 3.1, 1.0);
    REQUIRE( equal(a.x, 4.3) == true );
    REQUIRE( equal(a.y, -4.2) == true );
    REQUIRE( equal(a.z,3.1) == true );
    REQUIRE( equal(a.w,1.0) == true );
    REQUIRE( a.isPoint() == true );
    REQUIRE( a.isVector() == false );
}

TEST_CASE( "A tuple with w=0.0 is a vector ", "[tuple]" ) {
    Tuple a(4.3, -4.2, 3.1, 0.0);
    REQUIRE( equal(a.x, 4.3) == true );
    REQUIRE( equal(a.y, -4.2) == true );
    REQUIRE( equal(a.z,3.1) == true );
    REQUIRE( equal(a.w,0.0) == true );
    REQUIRE( a.isPoint() == false );
    REQUIRE( a.isVector() == true );
}

TEST_CASE( "point() creates tuples with w=1 ", "[tuple]" ) {
    auto p = Point(4, -4, 3);
    Tuple t (4, -4, 3, 1); 
    REQUIRE( p == t );
}

TEST_CASE( "vector() creates tuples with w=0 ", "[tuple]" ) {
    auto v = Vector(4, -4, 3);
    Tuple b (4, -4, 3, 0); 
    REQUIRE( v == b );
}

TEST_CASE( "Adding two tuples", "[tuple] " ) {
    Tuple a1(3, -2, 5, 1);
    Tuple a2(-2, 3, 1, 0);
    REQUIRE( a1 + a2 == Tuple(1, 1, 6, 1) );
}

TEST_CASE( "Subtracting two points", "[tuple] " ) {
    auto p1 = Point(3, 2, 1);
    auto p2 = Point(5, 6, 7);
    auto v = Vector(-2, -4, -6);
    REQUIRE( p1 - p2 == v );
}

TEST_CASE( "Subtracting a vector from a point", "[tuple] " ) {
    auto p = Point(3, 2, 1);
    auto v = Vector(5, 6, 7);
    auto c = Point(-2, -4, -6);
    REQUIRE( p - v == c );
}

TEST_CASE( "Subtracting two vectors", "[tuple] " ) {
    auto v1 = Vector(3, 2, 1);
    auto v2 = Vector(5, 6, 7);
    auto v3 = Vector(-2, -4, -6);
    REQUIRE( v1 - v2 == v3 );
}

TEST_CASE( "Subtracting a vector from the zero vector", "[tuple] " ) {
    auto zero = Vector(0, 0, 0);
    auto v1 = Vector(1, -2, 3);
    auto v2 = Vector(-1, 2, -3);
    REQUIRE( zero - v1 == v2 );
}

TEST_CASE( "Negating a tuple", "[tuple] " ) {
    Tuple t1(1, -2, 3, -4);
    Tuple t2(-1, 2, -3, 4);
    REQUIRE( -t1 == t2 );
}

TEST_CASE( "Multiplying a tuple by a scalar", "[tuple] " ) {
    Tuple t1(1, -2, 3, -4);
    Tuple t2(3.5, -7, 10.5, -14);
    REQUIRE( t1 * 3.5 == t2 ); 
}


TEST_CASE( "Multiplying a tuple by a fraction", "[tuple] " ) {
    Tuple t1(1, -2, 3, -4);
    Tuple t2(0.5, -1, 1.5, -2);
    REQUIRE( t1 * 0.5 == t2 ); 
}

TEST_CASE( "Dividing a tuple by a scalar", "[tuple] " ) {
    Tuple t1(1, -2, 3, -4);
    Tuple t2(0.5, -1, 1.5, -2);
    REQUIRE( t1 / 2 == t2 ); 
}

TEST_CASE( "Computing the magnitude of vector(1, 0, 0)", "[tuple] " ) {
    auto v = Vector(1, 0, 0);
    REQUIRE( equal(magnitude(v),1) );
}

TEST_CASE( "Computing the magnitude of vector(0, 1, 0)", "[tuple] " ) {
    auto v = Vector(0, 1, 0);
    REQUIRE( equal(magnitude(v), 1) );
}

TEST_CASE( "Computing the magnitude of vector(0, 0, 1)", "[tuple] " ) {
    auto v = Vector(0, 0, 1);
    REQUIRE( equal(magnitude(v), 1) );
}

TEST_CASE( "Computing the magnitude of vector(1, 2, 3)", "[tuple] " ) {
    auto v = Vector(1, 2, 3);
    REQUIRE( equal(magnitude(v), sqrt(14)) );
}

TEST_CASE( "Computing the magnitude of vector(-1, -2, -3)", "[tuple] " ) {
    auto v = Vector(-1, -2, -3);
    REQUIRE( equal(magnitude(v), sqrt(14)) );
}

TEST_CASE ("Normalizing vector(4, 0, 0) gives (1, 0, 0)", "[tuple] ") {
    auto v = Vector(4, 0, 0);
    auto n = Vector(1, 0, 0);
    REQUIRE( normalize(v) == n );
}

TEST_CASE ("Normalizing vector(1, 2, 3)", "[tuple] ") {
    auto v = Vector(1, 2, 3);
    auto n = Vector(0.26726, 0.53452, 0.80178);
    REQUIRE( normalize(v) == n );
}

TEST_CASE ("The magnitude of a normalized vector", "[tuple] ") {
    auto v = Vector(1, 2, 3);
    REQUIRE( equal(magnitude(normalize(v)), 1) );
}

TEST_CASE ("The dot product of two tuples", "[tuple] ") {
    auto a = Vector(1, 2, 3);
    auto b = Vector(2, 3, 4);
    REQUIRE( equal(dot(a, b), 20) );
}

TEST_CASE ("The cross product of two vectors", "[tuple] ") {
    auto a = Vector(1, 2, 3);
    auto b = Vector(2, 3, 4);
    REQUIRE( cross(a, b) == Vector(-1, 2, -1) );
    REQUIRE( cross(b, a) == Vector(1, -2, 1) );
}

