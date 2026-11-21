#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

using Matrix = std::vector<std::vector<long long>>;

Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C(2, std::vector<long long>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, long long p) {
    Matrix res = {{1, 0}, {0, 1}};
    while (p > 0) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}

long long fibMatrix(long long n) {
    if (n <= 0) return 0;
    Matrix T = {{1, 1}, {1, 0}};
    T = power(T, n - 1);
    return T[0][0];
}

int main() {
    long long n = 100;
    std::cout << "Fibonacci(" << n << ") mod 10^9+7: " << fibMatrix(n) << "\n";
    return 0;
}
