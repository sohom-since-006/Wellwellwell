#include <iostream>
#include <vector>
#include <algorithm>

int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    std::cout << "Min coins for " << amount << ": " << coinChange(coins, amount) << "\n";
    return 0;
}
