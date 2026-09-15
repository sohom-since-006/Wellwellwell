#include <iostream>
#include <vector>
#include <cmath>

int jumpSearch(const std::vector<int>& arr, int x) {
    int n = static_cast<int>(arr.size());
    int step = static_cast<int>(std::sqrt(n));
    int prev = 0;

    while (arr[std::min(step, n) - 1] < x) {
        prev = step;
        step += static_cast<int>(std::sqrt(n));
        if (prev >= n) return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == std::min(step, n)) return -1;
    }

    if (arr[prev] == x) return prev;
    return -1;
}

int main() {
    std::vector<int> arr = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int target = 55;
    std::cout << "Jump search found index: " << jumpSearch(arr, target) << "\n";
    return 0;
}
