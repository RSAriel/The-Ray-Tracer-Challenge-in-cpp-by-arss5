#include "camera.hpp"

Camera::Camera(int hsize, int vsize, float fov){
    Matrix identity(4,4);
    identity.set_all({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1});

    double half_view = tan(fov/2);
    double aspect = (double)hsize/(double)vsize;
    if(aspect >= 1){
        half_width = half_view;
        half_height = half_view/aspect;
    }else{
        half_width = half_view*aspect;
        half_height = half_view;
    }

    this->hsize = hsize;
    this->vsize = vsize;
    this->fov = fov;
    this->pixel_size = 0;
    this->transform = identity;
}

Ray ray_for_pixel(Camera c, int px, int py){
    double xoffset = (px + 0.5) * c.pixel_size;
    double yoffset = (py + 0.5) * c.pixel_size;
    double world_x = c.half_width - xoffset;
    double world_y = c.half_height - yoffset;
    Tuple pixel = c.transform.inverse() * Point(world_x, world_y, -1);
    Tuple origin = c.transform.inverse() * Point(0, 0, 0);
    Tuple direction = normalize(pixel - origin);
    return Ray(origin, direction);
}

Canvas render(Camera camera, World world){
    Canvas image(camera.hsize, camera.vsize);
    for(int y = 0; y < camera.vsize; y++){
        for(int x = 0; x < camera.hsize; x++){
            Ray r = ray_for_pixel(camera, x, y);
            Color color = color_at(world, r);
            image.write_pixel(x, y, color);
        }
    }
    return image;
}