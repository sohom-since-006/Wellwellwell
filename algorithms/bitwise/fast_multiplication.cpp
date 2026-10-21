#include <iostream>

long long fastMultiplyByPowerOfTwo(long long n, int power) {
    return n << power;
}

long long fastDivideByPowerOfTwo(long long n, int power) {
    return n >> power;
}

int main() {
    long long n = 25;
    std::cout << n << " * 8 = " << fastMultiplyByPowerOfTwo(n, 3) << "\n";
    std::cout << n << " / 4 = " << fastDivideByPowerOfTwo(n, 2) << "\n";
    return 0;
}
