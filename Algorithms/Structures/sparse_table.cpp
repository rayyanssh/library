#include <vector>
#include <span>
#include <bit>

using ll = long long;
using namespace std;
using u64 = unsigned long long;

inline int log2_floor(u64 n) {
    return bit_width(n) - 1;
}

void build_sparse_table(span<ll> nums, auto& S, auto f) {
    int n = nums.size();  
    for (int j = 1; j < log2_floor(n); j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            S[j][i] = f(S[j - 1][i], S[j - 1][i + (1 << (j - 1))]);
        }
    }
}

template<typename T>
struct SparseTable {
    int n;
    Grid<T> st;  
    void build(span<ll> nums, auto f) {
        n = nums.size();
        st = Grid<T>(log2_floor(n), n);
        for (int i = 0; i < n; i++) st[0][i] = nums[i];
        build_sparse_table(nums, st, f);
    }
    
}