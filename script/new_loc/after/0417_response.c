#include <stdio.h>
#include <stdlib.h>

void dfs(int** heights, int m, int n, int r, int c, int** visited, int prevHeight) {
    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || heights[r][c] < prevHeight) 
        return;
    visited[r][c] = 1;
    dfs(heights, m, n, r+1, c, visited, heights[r][c]);
    dfs(heights, m, n, r-1, c, visited, heights[r][c]);
    dfs(heights, m, n, r, c+1, visited, heights[r][c]);
    dfs(heights, m, n, r, c-1, visited, heights[r][c]);
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    int m = heightsSize, n = *heightsColSize;
    int** res = (int**)malloc(m * n * sizeof(int*));
    int (*visitedPacific)[n] = calloc(m, sizeof *visitedPacific);
    int (*visitedAtlantic)[n] = calloc(m, sizeof *visitedAtlantic);
    *returnSize = 0;

    for (int i = 0; i < m; i++) {
        dfs(heights, m, n, i, 0, (int**)visitedPacific, heights[i][0]);
        dfs(heights, m, n, i, n-1, (int**)visitedAtlantic, heights[i][n-1]);
    }

    for (int i = 0; i < n; i++) {
        dfs(heights, m, n, 0, i, (int**)visitedPacific, heights[0][i]);
        dfs(heights, m, n, m-1, i, (int**)visitedAtlantic, heights[m-1][i]);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (visitedPacific[i][j] && visitedAtlantic[i][j]) {
                res[*returnSize] = (int*)malloc(2 * sizeof(int));
                res[*returnSize][0] = i;
                res[*returnSize][1] = j;
                (*returnSize)++;
            }
        }
    }
    
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) 
        (*returnColumnSizes)[i] = 2;

    free(visitedPacific);
    free(visitedAtlantic);
    return res;
}
