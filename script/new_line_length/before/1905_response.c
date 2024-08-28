#include <stdbool.h>

void dfs(int** grid1, int** grid2, int grid1Size, int* grid1ColSize, int x, int y, bool* isSubIsland) {
    if (x < 0 || y < 0 || x >= grid1Size || y >= grid1ColSize[x] || grid2[x][y] == 0) 
        return;

    if (grid1[x][y] == 0) 
        *isSubIsland = false;

    grid2[x][y] = 0;

    dfs(grid1, grid2, grid1Size, grid1ColSize, x + 1, y, isSubIsland);
    dfs(grid1, grid2, grid1Size, grid1ColSize, x - 1, y, isSubIsland);
    dfs(grid1, grid2, grid1Size, grid1ColSize, x, y + 1, isSubIsland);
    dfs(grid1, grid2, grid1Size, grid1ColSize, x, y - 1, isSubIsland);
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
    int subIslands = 0;

    for (int i = 0; i < grid1Size; ++i) {
        for (int j = 0; j < grid1ColSize[i]; ++j) {
            if (grid2[i][j] == 1) {
                bool isSubIsland = true;
                dfs(grid1, grid2, grid1Size, grid1ColSize, i, j, &isSubIsland);
                if (isSubIsland)
                    subIslands++;
            }
        }
    }

    return subIslands;
}
