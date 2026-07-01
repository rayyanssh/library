#pragma once
#include <vector> 
using std::vector;

template<typename T>
struct Matrix {
    int rows, cols;
    vector<T> data; 
    Matrix(int n, int m) : rows(n), cols(m), data(n*m) {}
    Matrix(const auto& nums, int n, int m) : rows(n), cols(m), data(nums.begin(), nums.end()) {}
    T& operator[](int i, int j) { return data[i * cols + j]; }
    const T& operator[](int i, int j) const { return data[i * cols + j]; }
    T* data() { return data.data(); }
};

template<typename T>
struct MatrixView {
    T* data;
    int rows, cols, stride;
    MatrixView() = default;
    MatrixView(T* d, int n, int m) : data(d), rows(n), cols(m), stride(m) {}

    MatrixView(T* d, int n, int m, int s) : data(d), rows(n), cols(m), stride(s) {}
    MatrixView(Matrix<T>& M, int r, int c, int n, int m) : data(M.data() + r * M.cols() + c), rows(n), cols(m), stride(M.cols) {}
    T& operator[](int i, int j) { return data[i * stride + j]; }
    const T& operator[](int i, int j) const { return data[i * stride + j]; }
};
 