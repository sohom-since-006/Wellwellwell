#include <iostream>

long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    std::cout << "2^10 mod 1000 = " << modExp(2, 10, 1000) << "\n";
    return 0;
}
