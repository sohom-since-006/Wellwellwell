#include <iostream>
#include <vector>

long long powerMod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}

bool millerTest(long long d, long long n, long long a) {
    long long x = powerMod(a, d, n);
    if (x == 1 || x == n - 1) return true;

    while (d != n - 1) {
        x = (__int128)x * x % n;
        d *= 2;
        if (x == n - 1) return true;
        if (x == 1) return false;
    }
    return false;
}

bool isPrimeMillerRabin(long long n) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    long long d = n - 1;
    while (d % 2 == 0) d /= 2;

    std::vector<long long> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (long long a : bases) {
        if (n <= a) break;
        if (!millerTest(d, n, a)) return false;
    }
    return true;
}

int main() {
    long long p = 1000000007;
    std::cout << p << " is prime: " << (isPrimeMillerRabin(p) ? "Yes" : "No") << "\n";
    return 0;
}
