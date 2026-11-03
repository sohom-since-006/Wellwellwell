# ==============================================================================
# C/C++ Laboratory Multi-Target Makefile
# ==============================================================================

CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2
BIN_DIR ?= bin

SOURCES := $(wildcard *.cpp) $(wildcard algorithms/*/*.cpp) $(wildcard data_structures/*/*.cpp)
OBJECTS := $(patsubst %.cpp, $(BIN_DIR)/%, $(notdir $(SOURCES)))

.PHONY: all clean help bitwise arrays dsa test

all: $(BIN_DIR)
	@echo "Ready to compile laboratory targets."

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

bitwise: $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) "Swapping using Bittwise.cpp" -o $(BIN_DIR)/swap
	@$(CXX) $(CXXFLAGS) "Power of 2 bitwise.cpp" -o $(BIN_DIR)/power2
	@$(CXX) $(CXXFLAGS) "Odd Even Bitwise op.cpp" -o $(BIN_DIR)/oddeven
	@echo "Bitwise suite compiled successfully."

arrays: $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) "Magic Square.cpp" -o $(BIN_DIR)/magicsquare
	@$(CXX) $(CXXFLAGS) "Array Ex.cpp" -o $(BIN_DIR)/arrayex
	@echo "Array suite compiled successfully."

dsa: $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) "algorithms/sorting/quick_sort.cpp" -o $(BIN_DIR)/quicksort
	@$(CXX) $(CXXFLAGS) "algorithms/searching/binary_search.cpp" -o $(BIN_DIR)/binsearch
	@$(CXX) $(CXXFLAGS) "data_structures/stack/array_stack.cpp" -o $(BIN_DIR)/stack
	@echo "Core DSA suite compiled successfully."

test:
	python3 scripts/run_tests.py

clean:
	rm -rf $(BIN_DIR) *.o *.exe
	@echo "Cleaned build artifacts."

help:
	@echo "Available make targets:"
	@echo "  all       - Prepare output directory"
	@echo "  bitwise   - Compile bitwise manipulation programs"
	@echo "  arrays    - Compile array and matrix algorithms"
	@echo "  dsa       - Compile core DSA programs"
	@echo "  test      - Run Python verification tests"
	@echo "  clean     - Remove build artifacts"
