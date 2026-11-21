#include <iostream>
#include <vector>

long long extGCD(long long a, long long b, long long& x, long long& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return (x % m + m) % m;
}

long long findCRT(const std::vector<long long>& num, const std::vector<long long>& rem) {
    long long prod = 1;
    for (long long n : num) prod *= n;

    long long result = 0;
    for (size_t i = 0; i < num.size(); ++i) {
        long long pp = prod / num[i];
        result = (result + rem[i] * modInverse(pp, num[i]) * pp) % prod;
    }
    return (result + prod) % prod;
}

int main() {
    std::vector<long long> num = {3, 4, 5};
    std::vector<long long> rem = {2, 3, 1};
    std::cout << "Solution to congruence system: " << findCRT(num, rem) << "\n";
    return 0;
}
