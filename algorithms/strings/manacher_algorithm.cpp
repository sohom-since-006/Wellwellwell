#include <iostream>
#include <string>
#include <vector>

std::string longestPalindromeManacher(const std::string& s) {
    std::string T = "^";
    for (char c : s) { T += "#"; T += c; }
    T += "#$";

    int n = T.size();
    std::vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 1; i < n - 1; ++i) {
        int i_mirror = 2 * C - i;
        if (R > i) P[i] = std::min(R - i, P[i_mirror]);

        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - 1 - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    std::string text = "babad";
    std::cout << "Longest Palindromic Substring of '" << text << "': " 
              << longestPalindromeManacher(text) << "\n";
    return 0;
}
