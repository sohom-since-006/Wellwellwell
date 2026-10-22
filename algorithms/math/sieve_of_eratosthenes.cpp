#include <iostream>
#include <vector>

std::vector<int> sieve(int limit) {
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) isPrime[i] = false;
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) if (isPrime[i]) primes.push_back(i);
    return primes;
}

int main() {
    auto primes = sieve(50);
    std::cout << "Primes up to 50: ";
    for (int p : primes) std::cout << p << " ";
    std::cout << "\n";
    return 0;
}
