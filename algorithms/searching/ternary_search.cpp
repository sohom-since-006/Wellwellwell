#include <iostream>
#include <vector>

int ternarySearch(const std::vector<int>& arr, int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;

        if (key < arr[mid1]) return ternarySearch(arr, left, mid1 - 1, key);
        else if (key > arr[mid2]) return ternarySearch(arr, mid2 + 1, right, key);
        else return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
    }
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 7;
    int idx = ternarySearch(arr, 0, arr.size() - 1, key);
    std::cout << "Key " << key << " found at index: " << idx << "\n";
    return 0;
}
