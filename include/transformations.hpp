#ifndef TRANSFORMATIONSH
#define TRANSFORMATIONSH
#include "matrices.hpp"
class Matrix;

Matrix identity();

Matrix translation(float x, float y, float z);

Matrix scaling(float x, float y, float z); 

Matrix rotation_x(float r);

Matrix rotation_y(float r);

Matrix rotation_z(float r);

Matrix shearing(float xy, float xz, float yx, float yz, float zx, float zy);

#endif

