#include <iostream>

long long countTotalSetBits(long long n) {
    long long total = 0;
    n++;
    for (long long i = 1; i < n; i <<= 1) {
        long long fullGroups = n / (i << 1);
        total += fullGroups * i;
        long long remainder = n % (i << 1);
        if (remainder > i) total += remainder - i;
    }
    return total;
}

int main() {
    long long n = 17;
    std::cout << "Total set bits from 1 to " << n << ": " << countTotalSetBits(n) << "\n";
    return 0;
}
