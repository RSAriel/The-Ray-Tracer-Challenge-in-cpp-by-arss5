#include <catch2/catch_all.hpp>
#include "matrices.hpp"

TEST_CASE( "Constructing and inspecting a 4x4 matrix", "[matrix]") {
    Matrix m(4, 4);
    m.set_all({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11, 12, 13.5, 14.5, 15.5, 16.5});
    REQUIRE( m.get(0, 0) == 1 );
    REQUIRE( m.get(0, 3) == 4 );
    REQUIRE( m.get(1, 0) == 5.5 );
    REQUIRE( m.get(1, 2) == 7.5 );
    REQUIRE( m.get(2, 2) == 11 );
    REQUIRE( m.get(3, 0) == 13.5 );
    REQUIRE( m.get(3, 2) == 15.5 );
}


TEST_CASE( "A 2x2 matrix ought to be representable", "[matrix]") {
    Matrix m(2, 2);
    m.set_all({-3, 5, 1, -2});
    REQUIRE( m.get(0, 0) == -3 );
    REQUIRE( m.get(0, 1) == 5 );
    REQUIRE( m.get(1, 0) == 1 );
    REQUIRE( m.get(1, 1) == -2 );
}

TEST_CASE( "A 3x3 matrix ought to be representable", "[matrix]") {
    Matrix m(3, 3);
    m.set_all({-3, 5, 0, 1, -2, -7, 0, 1, 1});
    REQUIRE( m.get(0, 0) == -3 );
    REQUIRE( m.get(1, 1) == -2 );
    REQUIRE( m.get(2, 2) == 1 );
}

TEST_CASE( "Matrix equality with identical matrices", "[matrix]"){
    Matrix a(4, 4);
    Matrix b(4, 4);
    a.set_all({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
    b.set_all({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});

    REQUIRE( a == b );
}

TEST_CASE( "Matrix equality with different matrices", "[matrix]"){
    Matrix a(4, 4);
    Matrix b(4, 4);
    a.set_all({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
    b.set_all({2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    REQUIRE( !(a == b) );
}

TEST_CASE( "Multiplying two matrices", "[matrix]"){
    Matrix a(4, 4);
    Matrix b(4, 4);
    a.set_all({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
    b.set_all({-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8});
    Matrix c(4, 4);
    c.set_all({20, 22, 50, 48, 44, 54, 114, 108, 40, 58, 110, 102, 16, 26, 46, 42});
    REQUIRE( a * b == c );
}

TEST_CASE( "A matrix multiplied by a tuple", "[matrix]"){
    Matrix a(4, 4);
    a.set_all({1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1});
    Tuple b(1, 2, 3, 1);
    Tuple c(18, 24, 33, 1);
    REQUIRE( a * b == c );
}

TEST_CASE( "Multiplying a matrix by the identity matrix", "[matrix]"){
    Matrix a(4, 4);
    a.set_all({0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32});
    Matrix b(4, 4);
    b.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    REQUIRE( a * b == a );
}

TEST_CASE ( "Multiplying the identity matrix by a tuple", "[matrix]"){
    Matrix a(4, 4);
    a.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    Tuple b(1, 2, 3, 4);
    REQUIRE( a * b == b );
}

TEST_CASE ( "Transposing a matrix", "[matrix]"){
    Matrix a(4, 4);
    a.set_all({0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8});
    Matrix b(4, 4);
    b.set_all({0, 9, 1, 0, 9, 8, 8, 0, 3, 0, 5, 5, 0, 8, 3, 8});
    REQUIRE( a.transpose() == b );
}

TEST_CASE ( "Transposing the identity matrix", "[matrix]"){
    Matrix a(4, 4);
    a.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    REQUIRE( a.transpose() == a );
}

