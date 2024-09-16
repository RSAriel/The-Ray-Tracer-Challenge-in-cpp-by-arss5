#ifndef CAMERAH
#define CAMERAH
#include "matrices.hpp"
#include "rays.hpp"
#include "canvas.hpp"
#include "world.hpp"

class Camera {
public:
    int hsize, vsize;
    double half_width, half_height;
    double fov;
    double pixel_size;
    Matrix transform;
    Camera(int hsize, int vsize, float fov);
};

Ray ray_for_pixel(Camera c, int px, int py);
Canvas render(Camera camera, World world);


#endif

