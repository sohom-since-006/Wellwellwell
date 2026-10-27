#include <iostream>
#include <vector>

bool isSafe(const std::vector<int>& board, int row, int col) {
    for (int r = 0; r < row; ++r) {
        int c = board[r];
        if (c == col || abs(r - row) == abs(c - col)) return false;
    }
    return true;
}

int solveNQueens(int n, int row, std::vector<int>& board) {
    if (row == n) return 1;
    int count = 0;
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            count += solveNQueens(n, row + 1, board);
        }
    }
    return count;
}

int main() {
    int n = 4;
    std::vector<int> board(n);
    std::cout << "Total solutions for " << n << "-Queens: " << solveNQueens(n, 0, board) << "\n";
    return 0;
}
