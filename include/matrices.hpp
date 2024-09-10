#ifndef MATRICESH
#define MATRICESH
#include <vector>
#include "tuple.hpp"

class Matrix {
public:
    int rows, cols;
    std::vector<std::vector<float>> matrix;

    Matrix(int rows, int cols);
    Matrix();

    float get(int row, int col);
    void set(int row, int col, float value);
    void set_all(std::vector<float> values);
    Matrix transpose();
};

bool operator==(Matrix a, Matrix b);
bool operator==(Matrix a, Tuple b);
Matrix operator*(Matrix a, Matrix b);
Matrix operator*(Matrix a, Tuple b);

#endif
