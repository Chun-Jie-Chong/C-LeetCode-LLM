#include <stdio.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                if (i == 0 || grid[i-1][j] == 0) perimeter++;
                if (i == gridSize-1 || grid[i+1][j] == 0) perimeter++;
                if (j == 0 || grid[i][j-1] == 0) perimeter++;
                if (j == gridColSize[i]-1 || grid[i][j+1] == 0) perimeter++;
            }
        }
    }
    
    return perimeter;
}
