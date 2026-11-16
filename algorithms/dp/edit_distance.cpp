#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int minEditDistance(const std::string& str1, const std::string& str2) {
    int m = str1.size(), n = str2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({
                    dp[i - 1][j],      // Deletion
                    dp[i][j - 1],      // Insertion
                    dp[i - 1][j - 1]   // Substitution
                });
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::string s1 = "kitten", s2 = "sitting";
    std::cout << "Edit distance between '" << s1 << "' and '" << s2 << "': " 
              << minEditDistance(s1, s2) << "\n";
    return 0;
}
