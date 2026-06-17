#pragma once
#include <vector>
#include <span>
using namespace std;
using ll = long long;
/*
1. Matrix multiplication, when size is known at compile time
2. Matrix multiplication, dynamic size
3. Matrix multiplication, when multiplying submatrices of a larger matrix
4. defining a Matrix data structure */
template<int N, int M, int P>
void matmul(ll (&A)[N][M], ll (&B)[M][P], ll (&C)[N][P]) {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) { 
            for (int j = 0; j < P; j++) {
                C[i][j] += A_ik * B[k][j];
            }
        }
    }
}

void matmul(span<const ll> A,span<const ll> B, span<ll> C, int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            ll A_ik = A[i * m + k]; if (A_ik == 0) continue; 
            for (int j = 0; j < p; j++) {
                C[i * p + j] += A_ik * B[k * p + j];
            }
        }
    }
}

void matmul(span<const ll> A,span<const ll> B, span<ll> C, int n, int m, int p, int lda, int ldb, int ldc) {}


struct Matrix {
    int n, m;
    vector<ll> data;
    Matrix(int n, int m) : n(n), m(m), data(n * m) {}
    ll* operator[] (int i) { return &data[i * m];}
    const ll* operator[] (int i) const { return &data[i * m]; }
    Matrix operator*(const Matrix& other) const { 
        Matrix res(n, other.m);
        matmul(data, other.data, res.data, n, m, other.m);
        return res;    
    }
};
