#include <cstddef>
#include "../include/task2.hpp"


void Construct(Matrix& out, size_t n, size_t m) {
    out.n_ = n;
    out.m_ = m;
    out.data_ = new int*[m];
    for (size_t i = 0; i < m; ++i) {
        out.data_[i] = new int[n];
        for (size_t j = 0; j < n; ++j) {
            out.data_[i][j] = 0;
        }
    }
}

void Destruct(Matrix& in) {
    for (size_t i = 0; i < in.m_; ++i) {
        delete[] in.data_[i];
    }
    delete[] in.data_;
    in.data_ = nullptr;
    in.n_ = 0;
    in.m_ = 0;
}

Matrix Copy(const Matrix& matrix) {
    Matrix copy;
    Construct(copy, matrix.n_, matrix.m_);
    for (size_t i = 0; i < matrix.m_; ++i) {
        for (size_t j = 0; j < matrix.n_; ++j) {
            copy.data_[i][j] = matrix.data_[i][j];
        }
    }
    return copy;
}

Matrix Add(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.n_ || a.m_ != b.m_) {
        return Matrix();
    }
    Matrix sum;
    Construct(sum, a.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
        for (size_t j = 0; j < a.n_; ++j) {
            sum.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    return sum;
}

Matrix Sub(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.n_ || a.m_ != b.m_) {
        return Matrix();
    }
    Matrix diff;
    Construct(diff, a.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
        for (size_t j = 0; j < a.n_; ++j) {
            diff.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    return diff;
}

Matrix Mult(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.m_) {
        return Matrix();
    }
    Matrix prod;
    Construct(prod, b.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
        for (size_t j = 0; j < b.n_; ++j) {
            prod.data_[i][j] = 0;
            for (size_t k = 0; k < a.n_; ++k) {
                prod.data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }
    return prod;
}

void Transposition(Matrix& matrix) {
    Matrix transposed;
    Construct(transposed, matrix.m_, matrix.n_);
    for (size_t i = 0; i < matrix.m_; ++i) {
        for (size_t j = 0; j < matrix.n_; ++j) {
            transposed.data_[j][i] = matrix.data_[i][j];
        }
    }
    Destruct(matrix);
    matrix = transposed;
}

bool operator==(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.n_ || a.m_ != b.m_) {
        return false;
    }
    for (size_t i = 0; i < a.m_; ++i) {
        for (size_t j = 0; j < a.n_; ++j) {
            if (a.data_[i][j] != b.data_[i][j]) {
                return false;
            }
        }
    }
    return true;
}
