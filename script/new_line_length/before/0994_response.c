#include <stdio.h>
#include <stdlib.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int fresh = 0, m = gridSize, n = gridColSize[0];
    int queue[m*n][2], front = 0, rear = 0, minutes = 0;

    // Initialize the queue with rotten oranges and count fresh oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // BFS to spread rot to fresh oranges
    while (front < rear && fresh > 0) {
        int roundSize = rear - front;
        for (int i = 0; i < roundSize; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;
            for (int j = 0; j < 4; j++) {
                int newX = x + directions[j][0];
                int newY = y + directions[j][1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    queue[rear][0] = newX;
                    queue[rear][1] = newY;
                    rear++;
                    fresh--;
                }
            }
        }
        minutes++;
    }

    return fresh == 0 ? minutes : -1;
}
