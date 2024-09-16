#include <matrices.hpp>

Matrix::Matrix(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->matrix = std::vector<std::vector<double>>(rows, std::vector<double>(cols, 0));
}

Matrix::Matrix(){
    this->rows = 0;
    this->cols = 0;
    this->matrix = std::vector<std::vector<double>>();
}

double Matrix::get(int row, int col){
    return this->matrix[row][col];
}

void Matrix::set(int row, int col, double value){
    this->matrix[row][col] = value;
}

void Matrix::set_all(std::vector<double> values){
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

double Matrix::determinant(){
    if (rows == 2 && cols == 2){
        return get(0, 0) * get(1, 1) - get(0, 1) * get(1, 0);
    }
    double sum = 0;
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

double Matrix::minor(int row, int col){
    return submatrix(row, col).determinant();
};

double Matrix::cofactor(int row, int col){
    return (row + col) % 2 == 0 ? minor(row, col) : -minor(row, col);
};

bool Matrix::is_invertible(){
    return determinant() != 0;
};

Matrix Matrix::inverse(){
    Matrix result(this->rows, this->cols);
    double det = this->determinant();
    for (int i = 0; i < this->rows; i++){
        for (int j = 0; j < this->cols; j++){
            double cofactor = this->cofactor(i, j);
            result.set(j, i, cofactor / det);
        }
    }
    return result;
};

void Matrix::identity(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            set(i, j, i == j ? 1 : 0);
        }
    }
};

void Matrix::print(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
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
            double sum = 0;
            for (int k = 0; k < a.cols; k++){
                double ik = a.get(i, k);
                double kj = b.get(k, j);
                sum += ik * kj;
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

Tuple operator*(Matrix a, Tuple b){
    Matrix result(4, 1);
    for (int i = 0; i < 4; i++){
        double sum = 0;
        for (int j = 0; j < 4; j++){
            sum += a.get(i, j) * b.get(j);
        }
        result.set(i, 0, sum);
    }
    return Tuple(result.get(0, 0), result.get(1, 0), result.get(2, 0), result.get(3, 0));
}