#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ***res;
int resSize, *col, *diag1, *diag2;

void addSolution(char **board, int n) {
    res = realloc(res, (resSize + 1) * sizeof(char**));
    res[resSize] = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        res[resSize][i] = malloc((n + 1) * sizeof(char));
        strcpy(res[resSize][i], board[i]);
    }
    resSize++;
}

void solve(char **board, int row, int n) {
    if (row == n) {
        addSolution(board, n);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (col[i] || diag1[row + i] || diag2[row - i + n - 1]) continue;
        board[row][i] = 'Q';
        col[i] = diag1[row + i] = diag2[row - i + n - 1] = 1;
        solve(board, row + 1, n);
        board[row][i] = '.';
        col[i] = diag1[row + i] = diag2[row - i + n - 1] = 0;
    }
}

char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes) {
    col = calloc(n, sizeof(int));
    diag1 = calloc(2 * n, sizeof(int));
    diag2 = calloc(2 * n, sizeof(int));
    res = NULL;
    resSize = 0;
    char **board = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = malloc((n + 1) * sizeof(char));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }
    solve(board, 0, n);
    *returnSize = resSize;
    *returnColumnSizes = malloc(resSize * sizeof(int));
    for (int i = 0; i < resSize; i++) (*returnColumnSizes)[i] = n;
    for (int i = 0; i < n; i++) free(board[i]);
    free(board);
    free(col);
    free(diag1);
    free(diag2);
    return res;
}
