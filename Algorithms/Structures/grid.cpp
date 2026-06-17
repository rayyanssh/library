#pragma once
#include <vector>
#include <span>
using namespace std;

template<typename T>
struct Grid {
    int n, m;
    vector<T> data;
    Grid(int n, int m) : n(n), m(m), data(n * m) {}
    Grid(int n, int m, T val) : n(n), m(m), data(n * m, val) {}
    T* operator[] (int i) { return &data[i * m];}
    const T* operator[] (int i) const { return &data[i * m]; }
};