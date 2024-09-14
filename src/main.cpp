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
    int canvas_pixels = 1000;
    float pixel_size = wall_size / canvas_pixels;
    float half = wall_size / 2;

    Canvas canvas = Canvas(canvas_pixels, canvas_pixels);
    // canvas.set_color(Color(0, 1, 1));
    Color color = Color(1, 0, 0);
    Sphere s = Sphere((Point(0, 0, 0)), 1);

    float world_y;
    float world_x;
    Ray r;
    Intersections xs;
    for(int y=0; y < canvas_pixels; y++){
        world_y = half - pixel_size * y;
        for(int x=0; x < canvas_pixels; x++){
            world_x = -half + pixel_size * x;
            Tuple position = Point(world_x, world_y, wall_z);
            Tuple test = normalize(position - ray_origin);
            r = Ray(ray_origin, test);
            xs = intersect(s, r);
            if (xs.is_empty()){
                continue;
            }else if (hit(xs).t > 0){
                canvas.write_pixel(x, y, color);
            }
        }
    }
    print_ppm(canvas.canvas_to_ppm());
    return 0;
}

