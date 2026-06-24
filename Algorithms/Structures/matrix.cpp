#pragma once
#include <vector>
#include <span>
#include <mdspan>
using std::span, std::vector, std::mdspan;

template<typename T>
struct Matrix {
    int rows, cols;
    vector<T> data; 
    Matrix(int n, int m) : rows(n), cols(m), data(n*m) {}
    Matrix(span<const T> nums, int n, int m) : rows(n), cols(m), data(nums.begin(), nums.end()) {}
    
    auto view() { return mdspan(data.data(), rows, cols); }
    auto view() const { return mdspan(data.data(), rows, cols); }
    T& operator[](int i, int j) { return view()[i, j]; }
    const T& operator[](int i, int j) const { return view()[i, j]; }
};
