#include <catch2/catch_all.hpp>
#include "tuple.hpp"
#include "color.hpp"
#include "lights.hpp"

TEST_CASE( "A point light has a position and intensity", "[lights]" ) {
    Color intensity(1, 1, 1);
    Tuple position = Point(0, 0, 0);
    PointLight light(position, intensity);
    REQUIRE( light.position == position );
    REQUIRE( light.intensity == intensity );
}