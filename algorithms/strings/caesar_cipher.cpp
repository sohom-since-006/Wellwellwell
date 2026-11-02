#include <iostream>
#include <string>

std::string encryptCaesar(std::string text, int s) {
    std::string result = "";
    for (char c : text) {
        if (isupper(c)) result += char(int(c + s - 65) % 26 + 65);
        else if (islower(c)) result += char(int(c + s - 97) % 26 + 97);
        else result += c;
    }
    return result;
}

int main() {
    std::string text = "ATTACK AT ONCE";
    int s = 4;
    std::cout << "Encrypted: " << encryptCaesar(text, s) << "\n";
    return 0;
}
