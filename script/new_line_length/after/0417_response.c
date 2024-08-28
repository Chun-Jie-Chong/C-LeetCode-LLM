#include <stdbool.h>
#include <stdlib.h>

void dfs(int** heights, int heightsSize, int* heightsColSize, bool** ocean, int i, int j) {
    ocean[i][j] = true;
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for (int k = 0; k < 4; k++) {
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];
        if (x >= 0 && y >= 0 && x < heightsSize && y < heightsColSize[0] && 
            !ocean[x][y] && heights[x][y] >= heights[i][j]) {
            dfs(heights, heightsSize, heightsColSize, ocean, x, y);
        }
    }
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int** colSizes, int* returnSize) {
    *returnSize = 0;
    if (heightsSize == 0 || heightsColSize[0] == 0) return NULL;

    int m = heightsSize, n = heightsColSize[0];
    bool** pacific = (bool**)malloc(m * sizeof(bool*));
    bool** atlantic = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        pacific[i] = (bool*)calloc(n, sizeof(bool));
        atlantic[i] = (bool*)calloc(n, sizeof(bool));
    }

    for (int i = 0; i < m; i++) {
        dfs(heights, m, heightsColSize, pacific, i, 0);
        dfs(heights, m, heightsColSize, atlantic, i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        dfs(heights, m, heightsColSize, pacific, 0, j);
        dfs(heights, m, heightsColSize, atlantic, m - 1, j);
    }

    int** result = (int**)malloc(m * n * sizeof(int*));
    *colSizes = (int*)malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = i;
                result[*returnSize][1] = j;
                (*colSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        free(pacific[i]);
        free(atlantic[i]);
    }
    free(pacific);
    free(atlantic);

    return result;
}
