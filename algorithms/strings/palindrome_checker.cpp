#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;
        if (tolower(s[i]) != tolower(s[j])) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    std::string s = "A man, a plan, a canal: Panama";
    std::cout << "Is Palindrome: " << (isPalindrome(s) ? "Yes" : "No") << "\n";
    return 0;
}
