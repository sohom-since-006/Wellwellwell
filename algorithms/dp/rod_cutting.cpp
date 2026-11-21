#include <iostream>
#include <vector>
#include <algorithm>

int rodCutting(const std::vector<int>& price, int n) {
    std::vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int maxVal = -1;
        for (int j = 0; j < i; ++j) {
            maxVal = std::max(maxVal, price[j] + dp[i - j - 1]);
        }
        dp[i] = maxVal;
    }
    return dp[n];
}

int main() {
    std::vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int rodLength = price.size();
    std::cout << "Max obtainable value: " << rodCutting(price, rodLength) << "\n";
    return 0;
}
