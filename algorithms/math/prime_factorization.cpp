#include <iostream>
#include <vector>

std::vector<int> primeFactors(int n) {
    std::vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) factors.push_back(n);
    return factors;
}

int main() {
    int num = 315;
    auto f = primeFactors(num);
    std::cout << "Prime factors of " << num << ": ";
    for (int x : f) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
