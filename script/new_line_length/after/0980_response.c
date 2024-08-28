#include <stdio.h>

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int m, n, total_steps, result;

void dfs(int** grid, int x, int y, int steps) {
    if (x < 0 || y < 0 || x >= m || y >= n ||
        grid[x][y] == -1) return;
    if (grid[x][y] == 2) {
        if (steps == total_steps) result++;
        return;
    }
    int temp = grid[x][y];
    grid[x][y] = -1; // mark as visited
    for (int i = 0; i < 4; i++)
        dfs(grid, x + dir[i][0], y + dir[i][1], steps + 1);
    grid[x][y] = temp; // unmark
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    result = 0;
    m = gridSize;
    n = gridColSize[0];
    total_steps = 1; // count empty cells + start cell
    int start_x, start_y;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != -1) total_steps++;
            if (grid[i][j] == 1) {
                start_x = i;
                start_y = j;
            }
        }
    }
    dfs(grid, start_x, start_y, 0);
    return result;
}
