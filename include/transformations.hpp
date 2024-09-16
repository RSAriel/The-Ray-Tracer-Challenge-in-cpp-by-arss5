#ifndef TRANSFORMATIONSH
#define TRANSFORMATIONSH
#include "matrices.hpp"
class Matrix;

Matrix identity();

Matrix translation(double x, double y, double z);

Matrix scaling(double x, double y, double z); 

Matrix rotation_x(double r);

Matrix rotation_y(double r);

Matrix rotation_z(double r);

Matrix shearing(double xy, double xz, double yx, double yz, double zx, double zy);

Matrix view_transform(Tuple from, Tuple to, Tuple up);

#endif

