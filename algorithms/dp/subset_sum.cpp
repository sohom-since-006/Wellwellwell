#include <iostream>
#include <vector>

bool isSubsetSum(const std::vector<int>& set, int sum) {
    int n = set.size();
    std::vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int num : set) {
        for (int j = sum; j >= num; --j) {
            if (dp[j - num]) dp[j] = true;
        }
    }
    return dp[sum];
}

int main() {
    std::vector<int> set = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    std::cout << "Subset with sum " << sum << " exists: " 
              << (isSubsetSum(set, sum) ? "True" : "False") << "\n";
    return 0;
}
