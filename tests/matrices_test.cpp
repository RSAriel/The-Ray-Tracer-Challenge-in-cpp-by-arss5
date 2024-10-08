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

TEST_CASE ( "Calculating the determinant of a 2x2 matrix", "[matrix]"){
    Matrix a(2, 2);
    a.set_all({1, 5, -3, 2});
    REQUIRE( a.determinant() == 17 );
}

TEST_CASE ( "A submatrix of a 3x3 matrix is a 2x2 matrix", "[matrix]"){
    Matrix a(3, 3);
    Matrix b(2, 2);
    a.set_all({1, 5, 0, -3, 2, 7, 0, 6, -3});
    b.set_all({-3, 2, 0, 6});
    REQUIRE( a.submatrix(0, 2) == b );
}

TEST_CASE ( "A submatrix of a 4x4 matrix is a 3x3 matrix", "[matrix]"){
    Matrix a(4, 4);
    Matrix b(3, 3);
    a.set_all({-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1});
    b.set_all({-6, 1, 6, -8, 8, 6, -7, -1, 1});
    REQUIRE( a.submatrix(2, 1) == b );
}

TEST_CASE ( "Calculating a minor of a 3x3 matrix", "[matrix]"){
    Matrix a(3, 3);
    a.set_all({3, 5, 0, 2, -1, -7, 6, -1, 5});
    Matrix b(2, 2);
    b = a.submatrix(1, 0);
    REQUIRE( b.determinant() == 25 );
    REQUIRE( a.minor(1, 0) == 25 );
}

TEST_CASE ( "Calculating a cofactor of a 3x3 matrix", "[matrix]"){
    Matrix a(3, 3);
    a.set_all({3, 5, 0, 2, -1, -7, 6, -1, 5});
    REQUIRE( a.minor(0, 0) == -12 );
    REQUIRE( a.cofactor(0, 0) == -12 );
    REQUIRE( a.minor(1, 0) == 25 );
    REQUIRE( a.cofactor(1, 0) == -25 );
}

TEST_CASE ( "Calculating the determinant of a 3x3 matrix", "[matrix]"){
    Matrix a(3, 3);
    a.set_all({1, 2, 6, -5, 8, -4, 2, 6, 4});
    std::cout << a.determinant();
    REQUIRE( a.cofactor(0, 0) == 56 );
    REQUIRE( a.cofactor(0, 1) == 12 );
    REQUIRE( a.cofactor(0, 2) == -46 );
    REQUIRE( a.determinant() == -196 );
}

TEST_CASE ( "Calculating the determinant of a 4x4 matrix", "[matrix]"){
    Matrix a(4, 4);
    a.set_all({-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9});
    REQUIRE( a.cofactor(0, 0) == 690 );
    REQUIRE( a.cofactor(0, 1) == 447 );
    REQUIRE( a.cofactor(0, 2) == 210 );
    REQUIRE( a.cofactor(0, 3) == 51 );
    REQUIRE( a.determinant() == -4071 );
}

TEST_CASE ( "Testing an invertible matrix for invertibility", "[matrix]"){
    Matrix a(4, 4);
    a.set_all({6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6});
    REQUIRE( a.determinant() == -2120 );
    REQUIRE( a.is_invertible() );
}

TEST_CASE ( "Testing a non-invertible matrix for invertibility", "[matrix]"){
    Matrix a(4, 4);
    a.set_all({-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1, -5, 0, 0, 0, 0});
    REQUIRE( a.determinant() == 0 );
    REQUIRE( !a.is_invertible() );
}

TEST_CASE ( "Calculating the inverse of a matrix", "[matrix]"){
    Matrix a(4, 4);
    Matrix b(4, 4);
    a.set_all({-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4});
    b.set_all({0.21805, 0.45113, 0.24060, -0.04511, -0.80827, -1.45677, -0.44361, 0.52068, -0.07895, -0.22368, -0.05263, 0.19737, -0.52256, -0.81391, -0.30075, 0.30639});
    REQUIRE( a.inverse() == b );
}

TEST_CASE ( "Calculating the inverse of another matrix", "[matrix]"){
    Matrix a(4, 4);
    Matrix b(4, 4);
    a.set_all({8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4});
    b.set_all({-0.15385, -0.15385, -0.28205, -0.53846, -0.07692, 0.12308, 0.02564, 0.03077, 0.35897, 0.35897, 0.43590, 0.92308, -0.69231, -0.69231, -0.76923, -1.92308});
    REQUIRE( a.inverse() == b );
}

TEST_CASE ( "Calculating the inverse of a third matrix", "[matrix]"){
    Matrix a(4, 4);
    Matrix b(4, 4);
    a.set_all({9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2});
    b.set_all({-0.04074, -0.07778, 0.14444, -0.22222, -0.07778, 0.03333, 0.36667, -0.33333, -0.02901, -0.14630, -0.10926, 0.12963, 0.17778, 0.06667, -0.26667, 0.33333});
    REQUIRE( a.inverse() == b );
}

TEST_CASE ( "Multiplying a product by its inverse", "[matrix]"){
    Matrix a(4, 4);
    Matrix b(4, 4);
    Matrix c(4, 4);
    a.set_all({3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1});
    b.set_all({8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5});
    c = a * b;
    REQUIRE( c * b.inverse() == a );
}