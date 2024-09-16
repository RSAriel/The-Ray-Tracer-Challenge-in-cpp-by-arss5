#include <catch2/catch_all.hpp>
#include "camera.hpp"
#include <cmath>
#include "matrices.hpp"
#include "transformations.hpp"
#include "world.hpp"
#include "canvas.hpp"

TEST_CASE (" Constructing a camera", "[camera]"){
    Matrix identity(4,4);
    identity.set_all({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1});
    int hsize = 160;
    int vsize = 120;
    float fov = M_PI/2;
    Camera c(hsize, vsize, fov);
    REQUIRE(c.hsize == 160);
    REQUIRE(c.vsize == 120);
    REQUIRE(equal(c.fov, M_PI/2 ));
    REQUIRE(c.transform == identity);
}

TEST_CASE ("The pixel size for a horizontal canvas", "[camera]"){
    Camera c(200, 125, M_PI/2);
    REQUIRE(equal(c.pixel_size, 0.01));
}

TEST_CASE ("The pixel size for a vertical canvas", "[camera]"){
    Camera c(125, 200, M_PI/2);
    REQUIRE(equal(c.pixel_size, 0.01));
}

TEST_CASE ( "Constructing a ray through the center of the canvas", "[camera]"){
    Camera c(201, 101, M_PI/2);
    Ray r = ray_for_pixel(c, 100, 50);
    REQUIRE(r.origin == Point(0,0,0));
    REQUIRE(r.direction == Vector(0,0,-1));
}

TEST_CASE ( "Constructing a ray through a corner of the canvas", "[camera]"){
    Camera c(201, 101, M_PI/2);
    Ray r = ray_for_pixel(c, 0, 0);
    REQUIRE(r.origin == Point(0,0,0));
    REQUIRE(r.direction == Vector(0.66519, 0.33259, -0.66851));
}

TEST_CASE ( "Constructing a ray when the camera is transformed", "[camera]"){
    Camera c(201, 101, M_PI/2);
    c.transform = rotation_y(M_PI/4) * translation(0, -2, 5);
    Ray r = ray_for_pixel(c, 100, 50);
    REQUIRE(r.origin == Point(0, 2, -5));
    REQUIRE(r.direction == Vector(sqrt(2)/2, 0, -sqrt(2)/2));
}

TEST_CASE ( "Rendering a world with a camera", "[camera]") {
    World w = default_world();
    Camera c(11, 11, M_PI/2);
    Tuple from = Point(0, 0, -5);
    Tuple to = Point(0, 0, 0);
    Tuple up = Vector(0, 1, 0);
    c.transform = view_transform(from, to, up);
    Canvas image = render(c, w);
    REQUIRE(image.pixel_at(5, 5) == Color(0.38066, 0.47583, 0.2855));
}