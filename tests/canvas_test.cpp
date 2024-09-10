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

TEST_CASE( "Writing pixels to a canvas ", "[canvas]" ) {
    Canvas c(10, 20);
    Color red(1, 0, 0);
    c.write_pixel(2, 3, red);
    REQUIRE( c.pixels[2][3] == red );
}

TEST_CASE( "Constructing the PPM header ", "[canvas]" ) {
    Canvas c(5, 3);
    std::string ppm = c.canvas_to_ppm();
    REQUIRE( ppm.substr(0, 11) == "P3\n5 3\n255\n" );
}

TEST_CASE( "Constructing the PPM pixel data ", "[canvas]" ) {
    Canvas c(5, 3);
    Color c1(1.5, 0, 0);
    Color c2(0, 0.5, 0);
    Color c3(-0.5, 0, 1);
    c.write_pixel(0, 0, c1);
    c.write_pixel(2, 1, c2);
    c.write_pixel(4, 2, c3);
    std::string ppm = c.canvas_to_ppm();
    std::string expected = "P3\n5 3\n255\n"
                           "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
                           "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
                           "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";
    REQUIRE( ppm == expected );
}

TEST_CASE ( "Splitting long lines in PPM files ", "[canvas]" ) {
    Canvas c(10, 2);
    Color c1(1, 0.8, 0.6);
    for (int i = 0; i < c.width; i++) {
        for (int j = 0; j < c.height; j++) {
            c.write_pixel(i, j, c1);
        }
    }
    std::string ppm = c.canvas_to_ppm();
    std::string expected =  "\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 \n"
                            "153 255 204 153 255 204 153 255 204 153 255 204 153\n"
                            "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 \n"
                            "153 255 204 153 255 204 153 255 204 153 255 204 153\n";
    REQUIRE( ppm.substr(11) == expected );
    print_ppm(ppm);
}

TEST_CASE( "PPM files are terminated by a newline character ", "[canvas]" ) {
    Canvas c(5, 3);
    std::string ppm = c.canvas_to_ppm();
    REQUIRE( ppm.back() == '\n' );
}