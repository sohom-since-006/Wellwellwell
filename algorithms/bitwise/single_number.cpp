#include <iostream>
#include <vector>

int findSingleNumber(const std::vector<int>& arr) {
    int res = 0;
    for (int x : arr) res ^= x;
    return res;
}

int main() {
    std::vector<int> nums = {4, 1, 2, 1, 2};
    std::cout << "Single unique number: " << findSingleNumber(nums) << "\n";
    return 0;
}
