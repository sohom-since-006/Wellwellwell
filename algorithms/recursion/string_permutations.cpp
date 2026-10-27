#include <iostream>
#include <string>
#include <algorithm>

void permute(std::string& str, int l, int r) {
    if (l == r) {
        std::cout << str << " ";
        return;
    }
    for (int i = l; i <= r; ++i) {
        std::swap(str[l], str[i]);
        permute(str, l + 1, r);
        std::swap(str[l], str[i]);
    }
}

int main() {
    std::string s = "ABC";
    std::cout << "Permutations of " << s << ": ";
    permute(s, 0, s.size() - 1);
    std::cout << "\n";
    return 0;
}
