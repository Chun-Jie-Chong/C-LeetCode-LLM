#include <stdbool.h>

void dfs(int** grid2, int** grid1, int m, int n, int i, int j, bool* isSubIsland) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) 
        return;
    
    if (grid1[i][j] == 0) 
        *isSubIsland = false;
    
    grid2[i][j] = 0;
    
    dfs(grid2, grid1, m, n, i+1, j, isSubIsland);
    dfs(grid2, grid1, m, n, i-1, j, isSubIsland);
    dfs(grid2, grid1, m, n, i, j+1, isSubIsland);
    dfs(grid2, grid1, m, n, i, j-1, isSubIsland);
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, 
                    int** grid2, int grid2Size, int* grid2ColSize) {
    int m = grid1Size, n = *grid1ColSize;
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 1) {
                bool isSubIsland = true;
                dfs(grid2, grid1, m, n, i, j, &isSubIsland);
                if (isSubIsland)
                    count++;
            }
        }
    }
    
    return count;
}
