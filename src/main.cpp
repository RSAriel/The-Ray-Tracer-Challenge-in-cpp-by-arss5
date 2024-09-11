#include <iostream>
#include <tuple.hpp>
#include <canvas.hpp>
#include <color.hpp>
#include <rays.hpp>
#include <spheres.hpp>
#include <intersection.hpp>
#include <intersections.hpp>

int main() {
    Tuple ray_origin = Point(0, 0, -5);
    float wall_z = 10;
    float wall_size = 7;
    int canvas_pixels = 100;
    float pixel_size = wall_size / canvas_pixels;
    float half = wall_size / 2;

    Canvas canvas = Canvas(canvas_pixels, canvas_pixels);
    Color color = Color(1, 0, 0);
    Sphere s = Sphere(Point(0, 0, 0), 1);

    float world_y;
    float world_x;
    Tuple position;
    Ray r;
    Intersections xs;
    for(int y=0; y < canvas_pixels-1; y++){
        world_y = half - pixel_size * y;
        for(int x=0; x < canvas_pixels-1; x++){
            world_x = -half + pixel_size * x;
            position = Point(world_x, world_y, wall_z);
            r = Ray(ray_origin, normalize(position - ray_origin));
            xs = intersect(s, r);
            if (hit(xs).t > 0){
                canvas.write_pixel(x, y, color);
            }
        }
    }

    print_ppm(canvas.canvas_to_ppm());
    return 0;
}

