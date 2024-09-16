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
    double wall_z = 10;
    double wall_size = 7;
    int canvas_pixels = 200;
    double pixel_size = wall_size / canvas_pixels;
    double half = wall_size / 2;

    Canvas canvas = Canvas(canvas_pixels, canvas_pixels);
    // canvas.set_color(Color(0, 1, 1));
    Color color = Color(1, 0, 0);
    Sphere s = Sphere((Point(0, 0, 0)), 1);
    s.material = Material();
    s.material.color = Color(0.5, 0.2, 1);
    s.material.shininess = 120;
    Tuple light_postion = Point(-10, 10, -10);
    Color light_color (1, 1, 1);
    PointLight light = PointLight(light_postion, light_color);

    double world_y;
    double world_x;
    Ray r;
    Intersections xs;
    for(int y=0; y < canvas_pixels; y++){
        world_y = half - pixel_size * y;
        for(int x=0; x < canvas_pixels; x++){
            world_x = -half + pixel_size * x;
            Tuple position = Point(world_x, world_y, wall_z);
            Tuple direction_normal = normalize(position - ray_origin);
            r = Ray(ray_origin, direction_normal);
            xs = intersect(s, r);
            if (xs.is_empty()){
                continue;
            }else if (hit(xs).t > 0){
                Tuple point = r.position(hit(xs).t);
                Tuple normal = normal_at(s, point); //Esse S precisa ser o objeto que foi atingido (hit(xs).object)
                Tuple eye = -r.direction;
                color = lighting(s.material, light, point, eye, normal); //Aqui também
                canvas.write_pixel(x, y, color);
            }
        }
    }
    print_ppm(canvas.canvas_to_ppm());
    return 0;
}

