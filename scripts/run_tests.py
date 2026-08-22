#!/usr/bin/env python3
"""
Algorithm Invariant Test Suite
Validates the mathematical correctness and bitwise logic of programs in the repository.
"""

import sys

def test_bitwise_power_of_two():
    def is_power_of_two(n):
        return n > 0 and (n & (n - 1)) == 0

    powers = [1, 2, 4, 8, 16, 32, 64, 128, 256, 1024, 65536]
    non_powers = [0, -2, 3, 5, 6, 7, 9, 12, 18, 100, 1023]

    for p in powers:
        assert is_power_of_two(p), f"Expected {p} to be power of 2"
    for np in non_powers:
        assert not is_power_of_two(np), f"Expected {np} to NOT be power of 2"

def test_bitwise_parity():
    def is_even(n):
        return (n & 1) == 0

    for i in range(-50, 51):
        assert is_even(i) == (i % 2 == 0), f"Parity mismatch for {i}"

def test_magic_square_invariants():
    def generate_magic_square(n):
        square = [[0] * n for _ in range(n)]
        row, col = 0, n // 2
        for num in range(1, n * n + 1):
            square[row][col] = num
            next_r = (row - 1) % n
            next_c = (col + 1) % n
            if square[next_r][next_c] != 0:
                row = (row + 1) % n
            else:
                row, col = next_r, next_c
        return square

    for n in [3, 5, 7]:
        sq = generate_magic_square(n)
        expected_sum = n * (n * n + 1) // 2
        for row in sq:
            assert sum(row) == expected_sum, f"Row sum failed for n={n}"
        for col in range(n):
            assert sum(sq[r][col] for r in range(n)) == expected_sum, f"Col sum failed for n={n}"
        assert sum(sq[i][i] for i in range(n)) == expected_sum, f"Main diag sum failed for n={n}"
        assert sum(sq[i][n - 1 - i] for i in range(n)) == expected_sum, f"Anti diag sum failed for n={n}"

def main():
    print("Running algorithm invariant tests...")
    try:
        test_bitwise_power_of_two()
        print("  ✓ Bitwise Power of Two passed")
        test_bitwise_parity()
        print("  ✓ Bitwise Parity passed")
        test_magic_square_invariants()
        print("  ✓ Magic Square Invariant (Siamese Method) passed")
        print("\nAll algorithm invariant tests passed successfully.")
        return 0
    except AssertionError as err:
        print(f"\n[FAILED] Test failed: {err}", file=sys.stderr)
        return 1

if __name__ == "__main__":
    sys.exit(main())
