#include <cstddef>


struct Matrix {
  int** data_ = nullptr;
  size_t n_ = 0u;               // количество столбцов
  size_t m_ = 0u;               // количество строк
};

void Construct(Matrix& out, size_t n, size_t m);

void Destruct(Matrix& in);

Matrix Copy(const Matrix& matrix);

Matrix Add(const Matrix& a, const Matrix& b);

Matrix Sub(const Matrix& a, const Matrix& b);

Matrix Mult(const Matrix& a, const Matrix& b);

void Transposition(Matrix& matrix);

bool operator==(const Matrix& a, const Matrix& b);