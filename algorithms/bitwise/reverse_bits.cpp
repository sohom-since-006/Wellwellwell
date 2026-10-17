#include <iostream>
#include <cstdint>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

int main() {
    uint32_t n = 43261596;
    std::cout << "Reversed 32-bit integer: " << reverseBits(n) << "\n";
    return 0;
}
