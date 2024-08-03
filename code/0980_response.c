#include <stdio.h>

void dfs(int** grid, int gridSize, int* gridColSize, int x, int y, int zeroCount, int* pathCount) {
    if (x < 0 || x >= gridSize || y < 0 || y >= gridColSize[x] || grid[x][y] == -1) return;
    if (grid[x][y] == 2) {
        if (zeroCount == -1) (*pathCount)++;
        return;
    }
    
    int temp = grid[x][y];
    grid[x][y] = -1;
    dfs(grid, gridSize, gridColSize, x+1, y, zeroCount-1, pathCount);
    dfs(grid, gridSize, gridColSize, x-1, y, zeroCount-1, pathCount);
    dfs(grid, gridSize, gridColSize, x, y+1, zeroCount-1, pathCount);
    dfs(grid, gridSize, gridColSize, x, y-1, zeroCount-1, pathCount);
    grid[x][y] = temp;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int startX, startY, zeroCount = 0, pathCount = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    dfs(grid, gridSize, gridColSize, startX, startY, zeroCount, &pathCount);
    return pathCount;
}

