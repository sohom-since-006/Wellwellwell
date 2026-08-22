# 📊 Algorithm Complexity & Optimization Reference Guide

This reference documents the asymptotic time and space complexities, bitwise tricks, and invariants for the algorithms implemented in this repository.

---

## 1. Bitwise Mechanics

| Algorithm / Problem | Bitwise Expression | Time Complexity | Auxiliary Space | Key Invariant |
| :--- | :--- | :---: | :---: | :--- |
| **Power of 2 Check** | `(n > 0) && ((n & (n - 1)) == 0)` | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Binary representation of $2^k$ has exactly one set bit. Clearing it produces 0. |
| **Fast Parity Check** | `(n & 1) == 0` | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Lowest Significant Bit (LSB) indicates divisibility by 2. |
| **XOR Swapping** | `a ^= b; b ^= a; a ^= b;` | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Self-inverse property: $x \oplus x = 0$ and $x \oplus 0 = x$. |
| **Bit Position Inspection** | `(n >> k) & 1` | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Right shifts target bit into LSB position, then masks with 1. |
| **Multiple of 4** | `(n & 3) == 0` | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Bitmask `3` (`0b11`) checks the last two bits. |

---

## 2. Matrix & Array Algorithms

### Magic Square (Siamese Method)
- **Time Complexity**: $\mathcal{O}(N^2)$ to populate an $N \times N$ matrix.
- **Space Complexity**: $\mathcal{O}(N^2)$ for matrix storage.
- **Magic Constant Formula**:
  $$M = \frac{N(N^2 + 1)}{2}$$
- **Traversing Logic**:
  - Begin at position $(0, \lfloor N/2 \rfloor)$.
  - Move up and right diagonally: $(r - 1, c + 1) \pmod N$.
  - If target position is occupied or exceeds boundaries, move down one cell: $(r + 1, c)$.

---

## 3. Dynamic Memory & Systems Execution

- **Heap Allocation (`malloc`)**: Requesting memory from the operating system brk/mmap heaps with runtime boundary validation against `NULL`.
- **Calling Conventions**:
  - Caller vs callee stack frames.
  - Value vs pointer passing semantics.
  - Reentrancy and stack preservation.
