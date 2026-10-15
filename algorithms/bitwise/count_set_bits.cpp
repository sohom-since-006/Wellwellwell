#include <iostream>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int val = 29; // binary: 11101 -> 4 set bits
    std::cout << "Set bits in " << val << ": " << countSetBits(val) << "\n";
    return 0;
}
