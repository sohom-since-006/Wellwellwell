# Contributing to the C & C++ Laboratory

Thank you for your interest in contributing to this algorithmic laboratory repository!

## Guidelines for Contributions

1. **Code Standards**:
   - Write clean, well-commented C and C++ programs.
   - Use standard headers (`<stdio.h>`, `<stdlib.h>`, `<iostream>`).
   - Prefer portable standard C11 / C++17 constructs.

2. **File Organization**:
   - Place algorithmic source files in descriptive categories or root modules.
   - Do not commit compiled executables (`.exe`, `.o`, `.obj`).

3. **Validation**:
   - Compile code with strict warnings enabled:
     ```bash
     g++ -std=c++17 -Wall -Wextra <filename>.cpp -o output
     ```
   - Run the Python test suite:
     ```bash
     python3 scripts/run_tests.py
     ```

4. **Pull Requests**:
   - Fork the repository.
   - Create a feature branch (`git checkout -b feature/new-algorithm`).
   - Follow conventional commit style (`feat:`, `fix:`, `docs:`, `chore:`).
   - Open a Pull Request for review.
