#include <iostream>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    long long a = 48, b = 18;
    std::cout << "GCD: " << gcd(a, b) << ", LCM: " << lcm(a, b) << "\n";
    return 0;
}
