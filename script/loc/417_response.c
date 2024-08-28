#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int** heights, int rows, int cols, int r, int c, int** visited) {
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int x = r + dirs[i][0], y = c + dirs[i][1];
        if (x >= 0 && x < rows && y >= 0 && y < cols && visited[x][y] == 0 && heights[x][y] >= heights[r][c])
            dfs(heights, rows, cols, x, y, visited);
    }
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    int rows = heightsSize;
    int cols = heightsColSize[0];
    int** pac = (int**)malloc(rows * sizeof(int*));
    int** atl = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        pac[i] = (int*)calloc(cols, sizeof(int));
        atl[i] = (int*)calloc(cols, sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        dfs(heights, rows, cols, i, 0, pac);
        dfs(heights, rows, cols, i, cols - 1, atl);
    }
    for (int j = 0; j < cols; j++) {
        dfs(heights, rows, cols, 0, j, pac);
        dfs(heights, rows, cols, rows - 1, j, atl);
    }

    int** result = (int**)malloc(rows * cols * sizeof(int*));
    *returnSize = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pac[i][j] && atl[i][j]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = i;
                result[*returnSize][1] = j;
                (*returnSize)++;
            }
        }
    }
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = 2;

    for (int i = 0; i < rows; i++) {
        free(pac[i]);
        free(atl[i]);
    }
    free(pac);
    free(atl);

    return result;
}