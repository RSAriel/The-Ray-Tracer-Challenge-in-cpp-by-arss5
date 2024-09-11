#include <transformations.hpp>

Matrix identity(){
    Matrix identity = Matrix(4, 4);
    identity.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    return identity;
}

Matrix translation(float x, float y, float z){
    Matrix translation = Matrix(4, 4);
    translation.set_all({1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z, 0, 0, 0, 1});
    return translation;
}

Matrix scaling(float x, float y, float z){
    Matrix scaling = Matrix(4, 4);
    scaling.set_all({x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1});
    return scaling;
}

Matrix rotation_x(float r){
    Matrix rotation = Matrix(4, 4);
    rotation.set_all({1, 0, 0, 0, 0, static_cast<float>(cos(r)), static_cast<float>(-sin(r)), 0, 0, static_cast<float>(sin(r)), static_cast<float>(cos(r)), 0, 0, 0, 0, 1});
    return rotation;
}

Matrix rotation_y(float r){
    Matrix rotation = Matrix(4, 4);
    rotation.set_all({static_cast<float>(cos(r)), 0, static_cast<float>(sin(r)), 0, 0, 1, 0, 0, static_cast<float>(-sin(r)), 0, static_cast<float>(cos(r)), 0, 0, 0, 0, 1});
    return rotation;
}

Matrix rotation_z(float r){
    Matrix rotation = Matrix(4, 4);
    rotation.set_all({static_cast<float>(cos(r)), static_cast<float>(-sin(r)), 0, 0, static_cast<float>(sin(r)), static_cast<float>(cos(r)), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    return rotation;
}

Matrix shearing (float xy, float xz, float yx, float yz, float zx, float zy){
    Matrix shearing = Matrix(4, 4);
    shearing.set_all({1, xy, xz, 0, yx, 1, yz, 0, zx, zy, 1, 0, 0, 0, 0, 1});
    return shearing;
}