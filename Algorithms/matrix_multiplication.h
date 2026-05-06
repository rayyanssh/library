#pragma once
using namespace std;
using ll = long long;

template<int N, int M, int P>
void matmul(ll A[N][M], ll B[M][P], ll C[N][P]) {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            for (int j = 0; j < P; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
