#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char ***result = NULL;
    int *columns = malloc(n * sizeof(int));
    int *d1 = malloc(2 * n * sizeof(int));
    int *d2 = malloc(2 * n * sizeof(int));
    *returnSize = 0;
    
    void backtrack(int row) {
        if (row == n) {
            result = realloc(result, (*returnSize + 1) * sizeof(char **));
            result[*returnSize] = malloc(n * sizeof(char *));
            for (int i = 0; i < n; i++) {
                result[*returnSize][i] = malloc((n + 1) * sizeof(char));
                memset(result[*returnSize][i], '.', n);
                result[*returnSize][i][columns[i]] = 'Q';
                result[*returnSize][i][n] = '\0';
            }
            (*returnSize)++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int idx1 = row - col + n, idx2 = 2 * n - row - col - 1;
            if (columns[col] || d1[idx1] || d2[idx2])
                continue;
            columns[col] = d1[idx1] = d2[idx2] = 1;
            backtrack(row + 1);
            columns[col] = d1[idx1] = d2[idx2] = 0;
        }
    }
    
    memset(columns, 0, n * sizeof(int));
    memset(d1, 0, 2 * n * sizeof(int));
    memset(d2, 0, 2 * n * sizeof(int));

    backtrack(0);

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    free(columns);
    free(d1);
    free(d2);

    return result;
}
