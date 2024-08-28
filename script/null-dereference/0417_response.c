#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_M 200
#define MAX_N 200

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int **result;
int resultSize;
int *resultColSize;
int m, n;

void dfs(int r, int c, bool visited[m][n], int prevHeight, int heights[m][n]) {
    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || heights[r][c] < prevHeight) {
        return;
    }
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int newRow = r + directions[i][0];
        int newCol = c + directions[i][1];
        dfs(newRow, newCol, visited, heights[r][c], heights);
    }
}

void initResult() {
    resultSize = 0;
    result = (int **)malloc(m * n * sizeof(int *));
    resultColSize = (int *)malloc(m * n * sizeof(int));
}

void addToResult(int r, int c) {
    result[resultSize] = (int *)malloc(2 * sizeof(int));
    result[resultSize][0] = r;
    result[resultSize][1] = c;
    resultColSize[resultSize] = 2;
    resultSize++;
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    m = heightsSize;
    n = heightsColSize[0];
    bool pacificVisited[m][n];
    bool atlanticVisited[m][n];
    memset(pacificVisited, 0, sizeof(pacificVisited));
    memset(atlanticVisited, 0, sizeof(atlanticVisited));

    for (int i = 0; i < m; i++) {
        dfs(i, 0, pacificVisited, heights[i][0], heights);
        dfs(i, n - 1, atlanticVisited, heights[i][n - 1], heights);
    }

    for (int i = 0; i < n; i++) {
        dfs(0, i, pacificVisited, heights[0][i], heights);
        dfs(m - 1, i, atlanticVisited, heights[m - 1][i], heights);
    }

    initResult();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                addToResult(i, j);
            }
        }
    }

    *returnSize = resultSize;
    *returnColumnSizes = resultColSize;
    return result;
}
