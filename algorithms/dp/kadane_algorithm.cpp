#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int>& nums) {
    int maxSoFar = nums[0];
    int currMax = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        currMax = std::max(nums[i], currMax + nums[i]);
        maxSoFar = std::max(maxSoFar, currMax);
    }
    return maxSoFar;
}

int main() {
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Maximum contiguous sum: " << maxSubArray(arr) << "\n";
    return 0;
}
