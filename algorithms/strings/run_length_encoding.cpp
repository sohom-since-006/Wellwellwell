#include <iostream>
#include <string>

std::string encodeRLE(const std::string& src) {
    std::string dest = "";
    int n = src.length();
    for (int i = 0; i < n; ++i) {
        dest += src[i];
        int count = 1;
        while (i + 1 < n && src[i] == src[i + 1]) {
            count++;
            i++;
        }
        dest += std::to_string(count);
    }
    return dest;
}

int main() {
    std::string s = "wwwwaaadexxxxxxywww";
    std::cout << "RLE Encoded: " << encodeRLE(s) << "\n";
    return 0;
}
