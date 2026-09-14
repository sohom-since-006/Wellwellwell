#include <iostream>
#include <vector>
#include <algorithm>

void countSortForRadix(std::vector<int>& arr, int exp) {
    int n = static_cast<int>(arr.size());
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; ++i) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; ++i) arr[i] = output[i];
}

void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int m = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSortForRadix(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    std::cout << "Radix Sorted Array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
