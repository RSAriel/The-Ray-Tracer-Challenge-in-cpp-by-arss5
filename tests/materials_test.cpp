#include <catch2/catch_all.hpp>
#include "materials.hpp"
#include "color.hpp"
#include "lights.hpp"


TEST_CASE( "The default material", "[materials]" ) {
    Material m;
    REQUIRE( m.color == Color(1, 1, 1) );
    REQUIRE( m.ambient == 0.1);
    REQUIRE( m.diffuse == 0.9);
    REQUIRE( m.specular == 0.9);
    REQUIRE( m.shininess == 200.0);
};

TEST_CASE ( "Lighting with the eye between the light and the surface", "[materials]") {
    Material m;
    Tuple position = Point(0, 0, 0);
    Tuple eyev = Vector(0, 0, -1);
    Tuple normalv = Vector(0, 0, -1);
    PointLight light = PointLight(Point(0, 0, -10), Color(1, 1, 1));
    Color result = lighting(m, light, position, eyev, normalv);
    REQUIRE( result == Color(1.9, 1.9, 1.9));
}

TEST_CASE ( "Lighting with the eye between light and surface, eye offset 45°", "[materials]") {
    Material m;
    Tuple position = Point(0, 0, 0);
    Tuple eyev = Vector(0, sqrt(2)/2, -sqrt(2)/2);
    Tuple normalv = Vector(0, 0, -1);
    PointLight light = PointLight(Point(0, 0, -10), Color(1, 1, 1));
    Color result = lighting(m, light, position, eyev, normalv);
    REQUIRE( result == Color(1.0, 1.0, 1.0));
}

TEST_CASE ( "Lighting with eye opposite surface, light offset 45°", "[materials]") {
    Material m;
    Tuple position = Point(0, 0, 0);
    Tuple eyev = Vector(0, 0, -1);
    Tuple normalv = Vector(0, 0, -1);
    PointLight light = PointLight(Point(0, 10, -10), Color(1, 1, 1));
    Color result = lighting(m, light, position, eyev, normalv);
    REQUIRE( result == Color(0.7364, 0.7364, 0.7364));
}

TEST_CASE ( "Lighting with eye in the path of the reflection vector", "[materials]") {
    Material m;
    Tuple position = Point(0, 0, 0);
    Tuple eyev = Vector(0, -sqrt(2)/2, -sqrt(2)/2);
    Tuple normalv = Vector(0, 0, -1);
    PointLight light = PointLight(Point(0, 10, -10), Color(1, 1, 1));
    Color result = lighting(m, light, position, eyev, normalv);
    REQUIRE( result == Color(1.6364, 1.6364, 1.6364));
}

TEST_CASE ( "Lighting with the light behind the surface", "[materials]") {
    Material m;
    Tuple position = Point(0, 0, 0);
    Tuple eyev = Vector(0, 0, -1);
    Tuple normalv = Vector(0, 0, -1);
    PointLight light = PointLight(Point(0, 0, 10), Color(1, 1, 1));
    Color result = lighting(m, light, position, eyev, normalv);
    REQUIRE( result == Color(0.1, 0.1, 0.1));
}