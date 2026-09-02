<div align="center">

# 💻 C & C++ Core Programming Laboratory
### 🚀 Comprehensive Repository of Algorithms, Bitwise Mechanics, Memory Management & Systems Logic

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C/C++" />
  <img src="https://img.shields.io/badge/Focus-Data%20Structures%20%26%20Systems-00F0FF?style=for-the-badge" alt="Focus" />
  <img src="https://img.shields.io/badge/Author-Sohom%20Paul-FF007F?style=for-the-badge" alt="Author" />
  <img src="https://img.shields.io/badge/CI-GitHub%20Actions-blue?style=for-the-badge&logo=githubactions&logoColor=white" alt="CI" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License" />
</p>

<p align="center">
  Curated collection of foundational C and C++ programs exploring low-level memory allocation, bit-level manipulation, matrix generation algorithms, functions, strings, and mathematical series.
</p>

---

</div>

## 📑 Program Index by Category

```text
C-Programs/
├── ⚡ Bitwise Operations & Manipulation
├── 🔢 Arrays & 2D Matrix Algorithms (Magic Square)
├── 🧠 Pointers & Dynamic Memory Allocation (malloc)
├── 🔄 Functions, Prototypes & Calling Conventions
├── 🔤 String Handling & Manipulation
├── 🧮 Mathematical Series, Factorials & Calculations
└── 📁 File I/O & Stream Handling
```

---

## ⚡ 1. Bitwise Operations & Manipulation

Techniques for direct bit-level arithmetic, masking, and optimization:

| Program File | Description | Core Bitwise Technique |
| :--- | :--- | :--- |
| **`Swapping using Bittwise.cpp`** | Swaps two integers without temporary variables. | `a ^= b; b ^= a; a ^= b;` (XOR swap) |
| **`Power of 2 bitwise.cpp`** | Determines if a number is a power of 2 in $O(1)$. | `(n > 0) && ((n & (n - 1)) == 0)` |
| **`Odd Even Bitwise op.cpp`** | Fast parity check without modulo operator. | `(n & 1) == 0` for even |
| **`Number and bit position.cpp`** | Checks or inspects specific bit flags in an integer. | Bit shifting `(n >> pos) & 1` |
| **`Multiple of 4.cpp`** | Validates if a number is divisible by 4 using bitmasking. | `(n & 3) == 0` |
| **`Bitwise 2.cpp`** | Exploration of binary AND, OR, XOR, and bitshifts. | Bitwise truth tables |

---

## 🔢 2. Arrays & 2D Matrix Algorithms

Matrix algorithms, array traversal, and dynamic patterns:

| Program File | Description | Algorithmic Highlights |
| :--- | :--- | :--- |
| **`Magic Square.cpp`** | Generalized Magic Square generator for any odd order $N \times N$. | Siamese method: pre-calculated magic sum $M = \frac{N(N^2 + 1)}{2}$. |
| **`Magic Square (sum=65).cpp`** | Specialized $5 \times 5$ Magic Square generator. | Row and column wrap-around logic yielding constant sum $65$. |
| **`Array Ex.cpp`** | Basic array input, storage, and traversal demonstrations. | Contiguous memory traversal. |
| **`Array Q.cpp`** & **`Array Q2.cpp`** | Array search, element comparison, and manipulation exercises. | Linear scan & array transformations. |
| **`Array Q3.cpp`** | Advanced indexing and element filtering tasks. | Condition-based array partitioning. |

---

## 🧠 3. Pointers & Dynamic Memory Management

Low-level memory allocation on the heap and pointer mechanics:

| Program File | Description | Memory Concept |
| :--- | :--- | :--- |
| **`Malloc Code.cpp`** | Allocates dynamic memory on the heap for $N$ integers. | `ptr = (int*)malloc(n * sizeof(int));` with `NULL` validation. |
| **`ptr 1.cpp`** | Basic pointer declarations, address-of (`&`), and dereferencing (`*`). | Pointer arithmetic & direct memory access. |

---

## 🔄 4. Functions & Calling Conventions

Comprehensive demonstration of the four functional design patterns in C:

| Program File | Category | Signature Pattern |
| :--- | :--- | :--- |
| **`No Argument No Return Value.cpp`** | Type 1 | `void functionName(void);` |
| **`No argument and Value Return.cpp`** | Type 2 | `int functionName(void);` |
| **`Argument and No Return Type.cpp`** | Type 3 | `void functionName(int, int);` |
| **`Argument and Return Value.cpp`** | Type 4 | `int functionName(int, int);` |
| **`prototype.cpp`** | Prototypes | Forward declaration syntax and linker resolution. |
| **`Functions and Call.cpp`** | Execution Flow | Call stacks and scope isolation. |

---

## 🔤 5. Strings & Character Processing

String manipulation using character arrays and standard library functions:

| Program File | Description | Technique |
| :--- | :--- | :--- |
| **`Reverse a String.cpp`** | Reverses an input string in-place or via index traversal. | Two-pointer or reverse loop from `strlen(s) - 1`. |
| **`Length of string using gets.cpp`** | String input reading and length counting. | Null-terminator `\0` detection. |

---

## 🧮 6. Mathematical Series, Factorials & Calculations

Iterative algorithms for mathematical sequences and arithmetic operations:

| Program File | Description | Mathematical Expression |
| :--- | :--- | :--- |
| **`Factorial of a Number Using Function.cpp`** | Computes $n!$ using modular function architecture. | $n! = \prod_{i=1}^n i$ |
| **`Factorial add for Even.cpp`** | Calculates series sum of factorials of even numbers. | $\sum (2i)!$ |
| **`Factorial and sum of Odd terms.cpp`** | Calculates series sum of factorials of odd numbers. | $\sum (2i - 1)!$ |
| **`Factorial sum of n.cpp`** | Progressive sum of factorials from $1!$ to $n!$. | $\sum_{i=1}^n i!$ |
| **`WAP to Reverse Number.cpp`** | Reverses an integer digit-by-digit. | `rev = rev * 10 + n % 10; n /= 10;` |
| **`WAP to Reverse Number With functions.cpp`** | Functional implementation of integer reversal. | Modular decomposition of digit inversion. |
| **`Calculator.cpp`** | Interactive menu-driven console calculator. | `switch-case` arithmetic dispatch. |
| **`Sum of @ num.cpp`** | Basic arithmetic addition of numbers. | Standard input / output streams. |

---

## 📁 7. File Handling & Streams (`File Problems/`)

Demonstrations of persistent storage access in C:

| Program File | Description | Standard APIs |
| :--- | :--- | :--- |
| **`File Problems/Open File.cpp`** | Opening, checking pointer validity, and closing files. | `fopen()`, `fclose()`, `NULL` check |
| **`File Problems/Sample.cpp`** | Reading and writing character data to/from disk files. | `fprintf()`, `fscanf()`, `fgetc()` |

---

## 🛠️ How to Compile & Run

You can compile any of these programs using GCC / MinGW (`gcc` or `g++`) from the command line:

### Using GCC / G++:
```bash
# Compile a C / C++ program
g++ "Magic Square.cpp" -o MagicSquare.exe

# Run the executable
./MagicSquare.exe
```

### Automated Build & Test Tools:
```bash
# 1. Using GNU Make:
make all        # Compile all programs into bin/
make bitwise    # Compile bitwise manipulation programs
make arrays     # Compile array algorithms
make clean      # Clean all binaries

# 2. Using PowerShell Build Script:
pwsh scripts/build_all.ps1

# 3. Running Algorithm Correctness Tests:
python3 scripts/run_tests.py
```

### 📚 Additional Documentation:
- [Algorithm Complexity & Bitwise Invariant Guide](docs/COMPLEXITY_GUIDE.md)
- [Open Source Contributing Guidelines](CONTRIBUTING.md)

---

## 👨‍💻 Author & Academic Background

- **Author**: **Sohom Paul** ([@sohom-since-006](https://github.com/sohom-since-006))
- **Degree**: B.Tech in Computer Science & Engineering (2025 – 2029)
- **Institution**: Asansol Engineering College, West Bengal, India
- **Agency Portfolio**: [Clips Kinetics](https://clipskinetics.vercel.app/)
- **Contact**: [paulsohom777@gmail.com](mailto:paulsohom777@gmail.com) | [LinkedIn](https://www.linkedin.com/in/sohompaul06)

---

<div align="center">
  <sub>Part of the <b>C & Systems Engineering Foundation</b> series by Sohom Paul.</sub>
</div>
