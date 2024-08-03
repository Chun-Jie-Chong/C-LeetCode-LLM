#include <stdbool.h>

int count;

bool isSafe(int row, int col, int *positions) {
    for (int i = 0; i < row; i++) {
        int prevCol = positions[i];
        if (prevCol == col || prevCol - col == row - i || prevCol - col == i - row) {
            return false;
        }
    }
    return true;
}

void solve(int n, int row, int *positions) {
    if (row == n) {
        count++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, positions)) {
            positions[row] = col;
            solve(n, row + 1, positions);
        }
    }
}

int totalNQueens(int n) {
    count = 0;
    int positions[n];
    solve(n, 0, positions);
    return count;
}
