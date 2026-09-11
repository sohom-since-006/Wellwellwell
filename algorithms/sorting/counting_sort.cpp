#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    std::vector<int> count(range, 0);
    for (int x : arr) count[x - minVal]++;

    int idx = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i]-- > 0) {
            arr[idx++] = i + minVal;
        }
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);
    std::cout << "Counting Sorted Array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
