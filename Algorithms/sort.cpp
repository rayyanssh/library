#include <span>
#include <vector>
using namespace std;

void mergesort(span<int> A, span<int>) {
    int n = A.size();
    if (n <= 1) return;
    int mid = n / 2;
    mergesort(A.first(mid),);
    mergesort(A.subspan(mid));
    vector<int> temp(n);
    merge(A.first(mid).begin(), A.first(mid).end(), A.subspan(mid).begin(), A.subspan(mid).end(), temp.begin());
    copy(temp.begin(), temp.end(), A.begin());
}
