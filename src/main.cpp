#include "camera.hpp"
#include "canvas.hpp"
#include "color.hpp"
#include "computations.hpp"
#include "intersection.hpp"
#include "intersections.hpp"
#include "lights.hpp"
#include "materials.hpp"
#include "matrices.hpp"
#include "rays.hpp"
#include "spheres.hpp"
#include "transformations.hpp"
#include "tuple.hpp"
#include "world.hpp"


int main() {
 
    World world = World();
    world.light = PointLight(Point(-10, 10, -10), Color(1, 1, 1));

    Sphere floor = Sphere();
    set_transform(floor, scaling(10, 0.01, 10));
    floor.material = Material();
    floor.material.color = Color(1, 0.9, 0.9);
    floor.material.specular = 0;
    world.add(floor);

    Sphere left_wall = Sphere();
    set_transform(left_wall, translation(0, 0, 5)   *
                             rotation_y(-M_PI/4)    *
                             rotation_x(M_PI/2)     *
                             scaling(10, 0.01, 10));
    left_wall.material = floor.material;
    world.add(left_wall);

    Sphere right_wall = Sphere();
    set_transform(right_wall, translation(0, 0, 5)  *
                              rotation_y(M_PI/4)   *
                              rotation_x(M_PI/2)   *
                              scaling(10, 0.01, 10));
    right_wall.material = floor.material;
    world.add(right_wall);


    Sphere middle = Sphere();
    set_transform(middle, translation(-0.5, 1, 0.5));
    middle.material = Material();
    middle.material.color = Color(0.1, 1, 0.5);
    middle.material.diffuse = 0.7;
    middle.material.specular = 0.3;
    world.objects.push_back(middle);
    world.add(middle);


    Sphere right = Sphere();
    set_transform(right, translation(1.5, 0.5, -0.5) *
                         scaling(0.5, 0.5, 0.5));
    right.material = Material();
    right.material.color = Color(0.5, 1, 0.1);
    right.material.diffuse = 0.7;
    right.material.specular = 0.3;
    world.objects.push_back(right);
    world.add(right);

    Sphere left = Sphere();
    set_transform(left, translation(-1.5, 0.33, -0.75) *
                        scaling(0.33, 0.33, 0.33));
    left.material = Material();
    left.material.color = Color(1, 0.8, 0.1);
    left.material.diffuse = 0.7;
    left.material.specular = 0.3;
    world.objects.push_back(left);
    world.add(left);


    Camera camera = Camera(500, 250, M_PI/3);
    camera.transform = view_transform(Point(0, 1.5, -5), Point(0, 1, 0), Vector(0, 1, 0));

    Canvas image = render(camera, world);
    print_ppm(image.canvas_to_ppm());
    return 0;
}