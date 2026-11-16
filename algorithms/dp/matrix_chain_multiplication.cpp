#include <iostream>
#include <vector>
#include <climits>

int matrixChainMultiplication(const std::vector<int>& p) {
    int n = p.size() - 1;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    // Matrices dimensions: 40x20, 20x30, 30x10, 10x30
    std::vector<int> arr = {40, 20, 30, 10, 30};
    int minOps = matrixChainMultiplication(arr);
    std::cout << "Minimum scalar multiplications: " << minOps << "\n";
    return 0;
}
