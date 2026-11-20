#include <iostream>
#include <string>
#include <vector>

std::vector<int> computeZArray(const std::string& s) {
    int n = s.length();
    std::vector<int> Z(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= R) Z[i] = std::min(R - i + 1, Z[i - L]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

void searchZ(const std::string& text, const std::string& pattern) {
    std::string concat = pattern + "$" + text;
    auto Z = computeZArray(concat);
    int pLen = pattern.length();

    std::cout << "Pattern '" << pattern << "' found at indices: ";
    for (size_t i = 0; i < Z.size(); ++i) {
        if (Z[i] == pLen) {
            std::cout << (i - pLen - 1) << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::string text = "AABAACAADAABAABA";
    std::string pattern = "AABA";
    searchZ(text, pattern);
    return 0;
}
