#include <catch2/catch_all.hpp>
#include "canvas.hpp"

TEST_CASE( "Creating a canvas ", "[canvas]" ) {
    Canvas c(10, 20);
    REQUIRE( c.width == 10 );
    REQUIRE( c.height == 20 );
    for (int i = 0; i < c.width; i++) {
        for (int j = 0; j < c.height; j++) {
            REQUIRE( c.pixels[i][j] == Color(0, 0, 0) );
        }
    }

}