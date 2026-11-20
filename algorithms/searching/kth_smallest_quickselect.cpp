#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; ++j) {
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[r]);
    return i;
}

int quickSelect(std::vector<int>& arr, int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        if (index - l == k - 1) return arr[index];
        if (index - l > k - 1) return quickSelect(arr, l, index - 1, k);
        return quickSelect(arr, index + 1, r, k - index + l - 1);
    }
    return -1;
}

int main() {
    std::vector<int> nums = {12, 3, 5, 7, 4, 19, 26};
    int k = 3;
    std::cout << k << "-th smallest element: " << quickSelect(nums, 0, nums.size() - 1, k) << "\n";
    return 0;
}
