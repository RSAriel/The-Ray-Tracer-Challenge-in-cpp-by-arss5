#include <catch2/catch_all.hpp>
#include <transformations.hpp>
#include <tuple.hpp>

TEST_CASE( "Multiplying by a translation matrix", "[transformations]"){
    Matrix transform = translation(5, -3, 2);
    auto p = Point(-3, 4, 5);
    REQUIRE(transform * p == Point(2, 1, 7));
}

TEST_CASE( "Multiplying by the inverse of a translation matrix", "[transformations]"){
    Matrix transform = translation(5, -3, 2);
    auto inv = transform.inverse();
    auto p = Point(-3, 4, 5);
    REQUIRE(inv * p == Point(-8, 7, 3));
}

TEST_CASE( "Translation does not affect vectors", "[transformations]"){
    Matrix transform = translation(5, -3, 2);
    auto v = Vector(-3, 4, 5);
    REQUIRE(transform * v == v);
}

TEST_CASE( "A scaling matrix applied to a point", "[transformations]"){
    Matrix transform = scaling(2, 3, 4);
    auto p = Point(-4, 6, 8);
    REQUIRE(transform * p == Point(-8, 18, 32));
}

TEST_CASE( "A scaling matrix applied to a vector", "[transformations]"){
    Matrix transform = scaling(2, 3, 4);
    auto v = Vector(-4, 6, 8);
    REQUIRE(transform * v == Vector(-8, 18, 32));
}

TEST_CASE( "Multiplying by the inverse of a scaling matrix", "[transformations]"){
    Matrix transform = scaling(2, 3, 4);
    auto inv = transform.inverse();
    auto v = Vector(-4, 6, 8);
    REQUIRE(inv * v == Vector(-2, 2, 2));
}

TEST_CASE( "Reflection is scaling by a negative value", "[transformations]"){
    Matrix transform = scaling(-1, 1, 1);
    auto p = Point(2, 3, 4);
    REQUIRE(transform * p == Point(-2, 3, 4));
}

TEST_CASE( "Rotating a point around the x axis", "[transformations]"){
    auto p = Point(0, 1, 0);
    auto half_quarter = rotation_x(M_PI/4);
    auto full_quarter = rotation_x(M_PI/2);
    REQUIRE(half_quarter * p == Point(0, sqrt(2)/2, sqrt(2)/2));
    REQUIRE(full_quarter * p == Point(0, 0, 1));
}

TEST_CASE( "The inverse of an x-rotation rotates in the opposite direction", "[transformations]"){
    auto p = Point(0, 1, 0);
    auto half_quarter = rotation_x(M_PI/4);
    auto inv = half_quarter.inverse();
    REQUIRE(inv * p == Point(0, sqrt(2)/2, -sqrt(2)/2));
}

TEST_CASE( "Rotating a point around the y axis", "[transformations]"){
    auto p = Point(0, 0, 1);
    auto half_quarter = rotation_y(M_PI/4);
    auto full_quarter = rotation_y(M_PI/2);
    REQUIRE(half_quarter * p == Point(sqrt(2)/2, 0, sqrt(2)/2));
    REQUIRE(full_quarter * p == Point(1, 0, 0));
}

TEST_CASE( "Rotating a point around the z axis", "[transformations]"){
    auto p = Point(0, 1, 0);
    auto half_quarter = rotation_z(M_PI/4);
    auto full_quarter = rotation_z(M_PI/2);
    REQUIRE(half_quarter * p == Point(-sqrt(2)/2, sqrt(2)/2, 0));
    REQUIRE(full_quarter * p == Point(-1, 0, 0));
}

TEST_CASE ( "A shearing transformation moves x in proportion to y", "[transformations]"){
    Matrix transform = shearing(1, 0, 0, 0, 0, 0);
    auto p = Point(2, 3, 4);
    REQUIRE(transform * p == Point(5, 3, 4));
}

TEST_CASE ( "A shearing transformation moves x in proportion to z", "[transformations]"){
    Matrix transform = shearing(0, 1, 0, 0, 0, 0);
    auto p = Point(2, 3, 4);
    REQUIRE(transform * p == Point(6, 3, 4));
}

TEST_CASE ( "A shearing transformation moves y in proportion to x", "[transformations]"){
    Matrix transform = shearing(0, 0, 1, 0, 0, 0);
    auto p = Point(2, 3, 4);
    REQUIRE(transform * p == Point(2, 5, 4));
}

TEST_CASE ( "A shearing transformation moves y in proportion to z", "[transformations]"){
    Matrix transform = shearing(0, 0, 0, 1, 0, 0);
    auto p = Point(2, 3, 4);
    REQUIRE(transform * p == Point(2, 7, 4));
}

TEST_CASE ( "A shearing transformation moves z in proportion to x", "[transformations]"){
    Matrix transform = shearing(0, 0, 0, 0, 1, 0);
    auto p = Point(2, 3, 4);
    REQUIRE(transform * p == Point(2, 3, 6));
}

TEST_CASE ( "A shearing transformation moves z in proportion to y", "[transformations]"){
    Matrix transform = shearing(0, 0, 0, 0, 0, 1);
    auto p = Point(2, 3, 4);
    REQUIRE(transform * p == Point(2, 3, 7));
}

TEST_CASE ( "Individual transformations are applied in sequence", "[transformations]"){
    auto p = Point(1, 0, 1);
    auto A = rotation_x(M_PI/2);
    auto B = scaling(5, 5, 5);
    auto C = translation(10, 5, 7);
    auto p2 = A * p;
    REQUIRE(p2 == Point(1, -1, 0));
    auto p3 = B * p2;
    REQUIRE(p3 == Point(5, -5, 0));
    auto p4 = C * p3;
    REQUIRE(p4 == Point(15, 0, 7));
}

TEST_CASE ( "Chained transformations must be applied in reverse order", "[transformations]"){
    auto p = Point(1, 0, 1);
    auto A = rotation_x(M_PI/2);
    auto B = scaling(5, 5, 5);
    auto C = translation(10, 5, 7);
    auto T = C * B * A;
    REQUIRE(T * p == Point(15, 0, 7));
}

TEST_CASE ( "The transformation matrix for the default orientation", "[transformations]"){
    auto from = Point(0, 0, 0);
    auto to = Point(0, 0, -1);
    auto up = Vector(0, 1, 0);
    auto t = view_transform(from, to, up);
    Matrix identity(4, 4);
    identity.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    REQUIRE(t == identity);
}

TEST_CASE ( "A view transformation matrix looking in positive z direction", "[transformations]"){
    auto from = Point(0, 0, 0);
    auto to = Point(0, 0, 1);
    auto up = Vector(0, 1, 0);
    auto t = view_transform(from, to, up);
    REQUIRE(t == scaling(-1, 1, -1));
}

TEST_CASE ( "The view transformation moves the world", "[transformations]"){
    auto from = Point(0, 0, 8);
    auto to = Point(0, 0, 0);
    auto up = Vector(0, 1, 0);
    auto t = view_transform(from, to, up);
    REQUIRE(t == translation(0, 0, -8));
}

TEST_CASE ( "An arbitrary view transformation", "[transformations]"){
    auto from = Point(1, 3, 2);
    auto to = Point(4, -2, 8);
    auto up = Vector(1, 1, 0);
    auto t = view_transform(from, to, up);
    Matrix expected(4,4);
    expected.set_all({-0.50709, 0.50709, 0.67612, -2.36643,
                      0.76772, 0.60609, 0.12122, -2.82843,
                      -0.35857, 0.59761, -0.71714, 0.00000,
                      0.00000, 0.00000, 0.00000, 1.00000});

    REQUIRE(t == expected);
}