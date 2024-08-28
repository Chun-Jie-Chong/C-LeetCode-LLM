#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addSolution(int n, char ***solutions, int *returnSize, 
                 char **board) {
    solutions[*returnSize] = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        solutions[*returnSize][i] = strdup(board[i]);
    }
    (*returnSize)++;
}

int isValid(char **board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return 0;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
    return 1;
}

void solve(int n, char **board, char ***solutions, 
           int *returnSize, int row) {
    if (row == n) {
        addSolution(n, solutions, returnSize, board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(n, board, solutions, returnSize, row + 1);
            board[row][col] = '.';
        }
    }
}

char ***solveNQueens(int n, int *returnSize) {
    *returnSize = 0;
    if (n <= 0) {
        return NULL;
    }
    char ***solutions = (char ***)malloc(500 * sizeof(char **));
    char **board = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        board[i] = (char *)malloc((n + 1) * sizeof(char));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }
    solve(n, board, solutions, returnSize, 0);
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    return solutions;
}
