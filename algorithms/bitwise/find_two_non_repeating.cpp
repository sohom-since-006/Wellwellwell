#include <iostream>
#include <vector>

std::pair<int, int> findTwoUnique(const std::vector<int>& arr) {
    int xorSum = 0;
    for (int num : arr) xorSum ^= num;

    // Isolate rightmost set bit
    int rightmostBit = xorSum & (-xorSum);

    int num1 = 0, num2 = 0;
    for (int num : arr) {
        if (num & rightmostBit) num1 ^= num;
        else num2 ^= num;
    }
    return {num1, num2};
}

int main() {
    std::vector<int> arr = {2, 4, 7, 9, 2, 4};
    auto [u1, u2] = findTwoUnique(arr);
    std::cout << "Two non-repeating numbers: " << u1 << " and " << u2 << "\n";
    return 0;
}
