# ==============================================================================
# C/C++ Laboratory Multi-Target Makefile
# ==============================================================================

CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2
BIN_DIR ?= bin

SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp, $(BIN_DIR)/%, $(SOURCES))

.PHONY: all clean help bitwise arrays

all: $(BIN_DIR) $(OBJECTS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: %.cpp | $(BIN_DIR)
	@echo "Compiling $< -> $@"
	@$(CXX) $(CXXFLAGS) "$<" -o "$@"

bitwise: $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) "Swapping using Bittwise.cpp" -o $(BIN_DIR)/swap
	@$(CXX) $(CXXFLAGS) "Power of 2 bitwise.cpp" -o $(BIN_DIR)/power2
	@$(CXX) $(CXXFLAGS) "Odd Even Bitwise op.cpp" -o $(BIN_DIR)/oddeven
	@echo "Bitwise suite compiled successfully."

arrays: $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) "Magic Square.cpp" -o $(BIN_DIR)/magicsquare
	@$(CXX) $(CXXFLAGS) "Array Ex.cpp" -o $(BIN_DIR)/arrayex
	@echo "Array suite compiled successfully."

clean:
	rm -rf $(BIN_DIR) *.o *.exe
	@echo "Cleaned build artifacts."

help:
	@echo "Available make targets:"
	@echo "  all       - Compile all .cpp laboratory sources into $(BIN_DIR)/"
	@echo "  bitwise   - Compile bitwise manipulation programs"
	@echo "  arrays    - Compile array and matrix algorithm programs"
	@echo "  clean     - Remove generated binaries and objects"
	@echo "  help      - Display this help message"
