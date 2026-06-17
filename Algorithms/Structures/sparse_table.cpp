#include <vector>
#include <span>

using namespace std;

template<typename T>
struct SparseTable {
    int n;
    SparseTable(span<T> nums) : n(nums.size()) {
        
    }
}