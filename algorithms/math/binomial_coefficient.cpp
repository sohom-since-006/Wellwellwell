#include <iostream>
#include <vector>

long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;

    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    std::cout << "10 C 3 = " << nCr(10, 3) << "\n";
    return 0;
}
