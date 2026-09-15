#include <iostream>
#include <vector>
#include <algorithm>

int binarySearchHelper(const std::vector<int>& arr, int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int exponentialSearch(const std::vector<int>& arr, int x) {
    int n = static_cast<int>(arr.size());
    if (n == 0) return -1;
    if (arr[0] == x) return 0;
    int i = 1;
    while (i < n && arr[i] <= x) i *= 2;
    return binarySearchHelper(arr, i / 2, std::min(i, n - 1), x);
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40, 50, 60, 70, 80};
    int x = 40;
    std::cout << "Exponential search index: " << exponentialSearch(arr, x) << "\n";
    return 0;
}
