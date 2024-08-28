#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int** matrix, int** cache, int m, int n, int i, int j, int prev) {
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prev) {
        return 0;
    }
    
    if (cache[i][j]) {
        return cache[i][j];
    }
    
    int left = dfs(matrix, cache, m, n, i, j - 1, matrix[i][j]);
    int right = dfs(matrix, cache, m, n, i, j + 1, matrix[i][j]);
    int up = dfs(matrix, cache, m, n, i - 1, j, matrix[i][j]);
    int down = dfs(matrix, cache, m, n, i + 1, j, matrix[i][j]);
    
    cache[i][j] = 1 + max(max(left, right), max(up, down));
    
    return cache[i][j];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    
    int m = matrixSize;
    int n = matrixColSize[0];
    
    int** cache = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        cache[i] = (int*)calloc(n, sizeof(int));
    }
    
    int maxLength = 0;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            maxLength = max(maxLength, dfs(matrix, cache, m, n, i, j, -1));
        }
    }
    
    for (int i = 0; i < m; ++i) {
        free(cache[i]);
    }
    free(cache);
    
    return maxLength;
}
