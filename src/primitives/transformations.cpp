#include <transformations.hpp>

Matrix identity(){
    Matrix identity = Matrix(4, 4);
    identity.set_all({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    return identity;
}

Matrix translation(double x, double y, double z){
    Matrix translation = Matrix(4, 4);
    translation.set_all({1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z, 0, 0, 0, 1});
    return translation;
}

Matrix scaling(double x, double y, double z){
    Matrix scaling = Matrix(4, 4);
    scaling.set_all({x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1});
    return scaling;
}

Matrix rotation_x(double r){
    Matrix rotation = Matrix(4, 4);
    rotation.set_all({1, 0, 0, 0, 0, static_cast<double>(cos(r)), static_cast<double>(-sin(r)), 0, 0, static_cast<double>(sin(r)), static_cast<double>(cos(r)), 0, 0, 0, 0, 1});
    return rotation;
}

Matrix rotation_y(double r){
    Matrix rotation = Matrix(4, 4);
    rotation.set_all({static_cast<double>(cos(r)), 0, static_cast<double>(sin(r)), 0, 0, 1, 0, 0, static_cast<double>(-sin(r)), 0, static_cast<double>(cos(r)), 0, 0, 0, 0, 1});
    return rotation;
}

Matrix rotation_z(double r){
    Matrix rotation = Matrix(4, 4);
    rotation.set_all({static_cast<double>(cos(r)), static_cast<double>(-sin(r)), 0, 0, static_cast<double>(sin(r)), static_cast<double>(cos(r)), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    return rotation;
}

Matrix shearing (double xy, double xz, double yx, double yz, double zx, double zy){
    Matrix shearing = Matrix(4, 4);
    shearing.set_all({1, xy, xz, 0, yx, 1, yz, 0, zx, zy, 1, 0, 0, 0, 0, 1});
    return shearing;
}

Matrix view_transform(Tuple from, Tuple to, Tuple up){
    auto forward = normalize(to - from);
    auto upn = normalize(up);
    auto left = cross(forward, upn);
    auto true_up = cross(left, forward);
    auto orientation = Matrix(4, 4);
    orientation.set_all({left.x, left.y, left.z, 0, true_up.x, true_up.y, true_up.z, 0, -forward.x, -forward.y, -forward.z, 0, 0, 0, 0, 1});
    return orientation * translation(-from.x, -from.y, -from.z);
}