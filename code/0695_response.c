#include <stdio.h>

int dfs(int** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i] || grid[i][j] == 0)
        return 0;
    
    grid[i][j] = 0; // mark visited
    int area = 1;
    
    area += dfs(grid, gridSize, gridColSize, i - 1, j); // up
    area += dfs(grid, gridSize, gridColSize, i + 1, j); // down
    area += dfs(grid, gridSize, gridColSize, i, j - 1); // left
    area += dfs(grid, gridSize, gridColSize, i, j + 1); // right
    
    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int max_area = 0;
    
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[i]; ++j) {
            if (grid[i][j] == 1) {
                int area = dfs(grid, gridSize, gridColSize, i, j);
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
    }
    
    return max_area;
}
