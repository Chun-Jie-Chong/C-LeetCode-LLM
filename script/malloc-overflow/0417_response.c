#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIM 200

void dfs(int **heights, int m, int n, int i, int j, bool visited[][MAX_DIM]) {
    visited[i][j] = true;
    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for (int d = 0; d < 4; d++) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
            dfs(heights, m, n, ni, nj, visited);
        }
    }
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    int m = heightsSize, n = *heightsColSize;
    *returnSize = 0;
    if (m == 0 || n == 0) return NULL;

    bool pacific[MAX_DIM][MAX_DIM] = {false};
    bool atlantic[MAX_DIM][MAX_DIM] = {false};

    for (int i = 0; i < m; i++) {
        dfs(heights, m, n, i, 0, pacific);
        dfs(heights, m, n, i, n - 1, atlantic);
    }

    for (int j = 0; j < n; j++) {
        dfs(heights, m, n, 0, j, pacific);
        dfs(heights, m, n, m - 1, j, atlantic);
    }

    int **result = (int **)malloc(m * n * sizeof(int *));
    *returnColumnSizes = (int *)malloc(m * n * sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result[*returnSize] = (int *)malloc(2 * sizeof(int));
                result[*returnSize][0] = i;
                result[*returnSize][1] = j;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
        }
    }

    return result;
}
