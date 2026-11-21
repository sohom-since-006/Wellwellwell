#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int minPalindromeCuts(const std::string& s) {
    int n = s.size();
    std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));
    std::vector<int> cuts(n, 0);

    for (int i = 0; i < n; ++i) {
        int minC = i;
        for (int j = 0; j <= i; ++j) {
            if (s[j] == s[i] && (i - j <= 2 || isPal[j + 1][i - 1])) {
                isPal[j][i] = true;
                minC = (j == 0) ? 0 : std::min(minC, cuts[j - 1] + 1);
            }
        }
        cuts[i] = minC;
    }
    return cuts[n - 1];
}

int main() {
    std::string str = "ababbbabbababa";
    std::cout << "Min cuts for '" << str << "': " << minPalindromeCuts(str) << "\n";
    return 0;
}
