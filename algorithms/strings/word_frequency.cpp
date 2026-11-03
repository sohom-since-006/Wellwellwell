#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main() {
    std::string text = "computer science algorithms data structures computer algorithms";
    std::stringstream ss(text);
    std::string word;
    std::map<std::string, int> freq;

    while (ss >> word) freq[word]++;

    std::cout << "Word Frequencies:\n";
    for (const auto& pair : freq) {
        std::cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    return 0;
}
