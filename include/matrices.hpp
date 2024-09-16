#ifndef MATRICESH
#define MATRICESH
#include <vector>
#include "tuple.hpp"

class Matrix {
public:
    int rows, cols;
    std::vector<std::vector<double>> matrix;

    Matrix(int rows, int cols);
    Matrix();    //Problem in matrix instatiation without parameters

    double get(int row, int col);
    void set(int row, int col, double value);
    void set_all(std::vector<double> values);
    Matrix transpose();
    double determinant();
    Matrix submatrix(int row, int col);
    double minor(int row, int col);
    double cofactor(int row, int col);
    bool is_invertible();
    Matrix inverse();
    void identity();
    void print();
};


bool operator==(Matrix a, Matrix b);
bool operator==(Matrix a, Tuple b);
Matrix operator*(Matrix a, Matrix b);
Tuple operator*(Matrix a, Tuple b);

#endif
