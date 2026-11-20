#include <iostream>
#include <vector>

long long countCoinCombinations(const std::vector<int>& coins, int target) {
    std::vector<long long> dp(target + 1, 0);
    dp[0] = 1; // Base case: 1 way to form 0 amount

    for (int coin : coins) {
        for (int i = coin; i <= target; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[target];
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int target = 5;
    std::cout << "Distinct coin combinations to make " << target << ": " 
              << countCoinCombinations(coins, target) << "\n";
    return 0;
}
