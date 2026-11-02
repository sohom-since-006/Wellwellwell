#include <iostream>
#include <string>

bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;
    int count[26] = {0};
    for (char c : s) count[c - 'a']++;
    for (char c : t) {
        if (--count[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    std::cout << "Anagram test: " << (isAnagram("listen", "silent") ? "True" : "False") << "\n";
    return 0;
}
