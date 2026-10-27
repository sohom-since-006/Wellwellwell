#include <iostream>
#include <vector>

long long fibTabulation(int n) {
    if (n <= 1) return n;
    long long prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; ++i) {
        long long curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n = 15;
    std::cout << "Fibonacci(" << n << ") = " << fibTabulation(n) << "\n";
    return 0;
}
