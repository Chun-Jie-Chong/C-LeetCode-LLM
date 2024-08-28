#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int dfs(int** matrix, int** cache, int rows, int cols, int i, int j) {
    if (cache[i][j]) return cache[i][j];
    int maxPath = 1, dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    for (int d = 0; d < 4; d++) {
        int x = i + dirs[d][0], y = j + dirs[d][1];
        if (x >= 0 && y >= 0 && x < rows && y < cols && matrix[x][y] > matrix[i][j]) 
            maxPath = max(maxPath, 1 + dfs(matrix, cache, rows, cols, x, y));
    }
    return cache[i][j] = maxPath;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize, cols = matrixColSize[0], maxLen = 0;
    int** cache = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        cache[i] = (int*)calloc(cols, sizeof(int));
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maxLen = max(maxLen, dfs(matrix, cache, rows, cols, i, j));
        }
    }
    
    for (int i = 0; i < rows; i++) free(cache[i]);
    free(cache);
    return maxLen;
}
