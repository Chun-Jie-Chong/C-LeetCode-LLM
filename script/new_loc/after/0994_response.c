#include <stdio.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int fresh = 0, mins = 0;
    int dirs[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int queue[100], front = 0, rear = 0;
    for (int i = 0; i < gridSize; ++i)
        for (int j = 0; j < gridColSize[i]; ++j)
            if (grid[i][j] == 1) ++fresh;
            else if (grid[i][j] == 2) queue[rear++] = i * 10 + j;
    while (fresh && front < rear) {
        int size = rear - front;
        while (size--) {
            int r = queue[front] / 10, c = queue[front] % 10;
            front++;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0], nc = c + dirs[i][1];
                if (nr < 0 || nr >= gridSize || nc < 0 || nc >= gridColSize[r] || grid[nr][nc] != 1) continue;
                grid[nr][nc] = 2;
                queue[rear++] = nr * 10 + nc;
                if (--fresh == 0) break;
            }
        }
        mins++;
    }
    return fresh ? -1 : mins;
}
