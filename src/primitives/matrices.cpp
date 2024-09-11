#include <matrices.hpp>

Matrix::Matrix(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->matrix = std::vector<std::vector<float>>(rows, std::vector<float>(cols, 0));
}

Matrix::Matrix(){
    this->rows = 0;
    this->cols = 0;
    this->matrix = std::vector<std::vector<float>>();
}

float Matrix::get(int row, int col){
    return this->matrix[row][col];
}

void Matrix::set(int row, int col, float value){
    this->matrix[row][col] = value;
}

void Matrix::set_all(std::vector<float> values){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->matrix[i][j] = values[i * this->cols + j];
        }
    }
}

Matrix Matrix::transpose(){
    Matrix result(cols, rows);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result.set(j, i, get(i, j));
        }
    }
    return result;
};

float Matrix::determinant(){
    if (rows == 2 && cols == 2){
        return get(0, 0) * get(1, 1) - get(0, 1) * get(1, 0);
    }
    float sum = 0;
    for (int i = 0; i < cols; i++){
        sum += get(0, i) * cofactor(0, i);
    }
    return sum;
};

Matrix Matrix::submatrix(int row, int col){
    Matrix result(rows - 1, cols - 1);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (i != row && j != col){
                result.set(i < row ? i : i - 1, j < col ? j : j - 1, get(i, j));
            }
        }
    }
    return result;
};

float Matrix::minor(int row, int col){
    return submatrix(row, col).determinant();
};

float Matrix::cofactor(int row, int col){
    return (row + col) % 2 == 0 ? minor(row, col) : -minor(row, col);
};

bool Matrix::is_invertible(){
    return determinant() != 0;
};

Matrix Matrix::inverse(){
    Matrix result(rows, cols);
    float det = determinant();
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result.set(j, i, cofactor(i, j) / det);
        }
    }
    return result;
};

bool operator==(Matrix a, Matrix b){
    if (a.rows != b.rows || a.cols != b.cols){
        return false;
    }
    for (int i = 0; i < a.rows; i++){
        for (int j = 0; j < a.cols; j++){
            if (!equal(a.get(i, j),b.get(i, j))){
                return false;
            }
        }
    }
    return true;
}

bool operator==(Matrix a, Tuple b){
    if (a.rows != 4 || a.cols != 1){
        return false;
    }
    return equal(a.get(0, 0), b.x) && equal(a.get(1, 0), b.y) && equal(a.get(2, 0), b.z) && equal(a.get(3, 0), b.w);
}

Matrix operator*(Matrix a, Matrix b){
    Matrix result(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++){
        for (int j = 0; j < b.cols; j++){
            float sum = 0;
            for (int k = 0; k < a.cols; k++){
                sum += a.get(i, k) * b.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

Matrix operator*(Matrix a, Tuple b){
    Matrix result(a.rows, 1);
    for (int i = 0; i < a.rows; i++){
        float sum = 0;
        for (int j = 0; j < a.cols; j++){
            sum += a.get(i, j) * b.get(j);
        }
        result.set(i, 0, sum);
    }
    return result;
}