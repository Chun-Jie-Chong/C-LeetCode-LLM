#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes);

void dfs(int** heights, int heightsSize, int* heightsColSize, bool** visited, int row, int col);

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    if (heightsSize == 0 || *heightsColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int m = heightsSize;
    int n = *heightsColSize;

    bool** pacificReachable = (bool**)malloc(m * sizeof(bool*));
    bool** atlanticReachable = (bool**)malloc(m * sizeof(bool*));
    int** result = (int**)malloc(m * n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * n * sizeof(int));

    for (int i = 0; i < m; i++) {
        pacificReachable[i] = (bool*)calloc(n, sizeof(bool));
        atlanticReachable[i] = (bool*)calloc(n, sizeof(bool));
    }

    for (int i = 0; i < m; i++) {
        dfs(heights, heightsSize, heightsColSize, pacificReachable, i, 0);
        dfs(heights, heightsSize, heightsColSize, atlanticReachable, i, n - 1);
    }

    for (int j = 0; j < n; j++) {
        dfs(heights, heightsSize, heightsColSize, pacificReachable, 0, j);
        dfs(heights, heightsSize, heightsColSize, atlanticReachable, m - 1, j);
    }

    *returnSize = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = i;
                result[*returnSize][1] = j;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        free(pacificReachable[i]);
        free(atlanticReachable[i]);
    }
    free(pacificReachable);
    free(atlanticReachable);

    return result;
}

void dfs(int** heights, int heightsSize, int* heightsColSize, bool** visited, int row, int col) {
    static int dirs[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    visited[row][col] = true;

    for (int i = 0; i < 4; i++) {
        int newRow = row + dirs[i][0];
        int newCol = col + dirs[i][1];
        if (newRow >= 0 && newRow < heightsSize && newCol >= 0 && newCol < *heightsColSize
            && !visited[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
            dfs(heights, heightsSize, heightsColSize, visited, newRow, newCol);
        }
    }
}
