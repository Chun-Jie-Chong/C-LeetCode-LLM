#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, 
                int* matrixColSize, int* returnSize) { 
    int m = matrixSize;
    int n = *matrixColSize;
    int* result = (int*)malloc(m * n * sizeof(int));
    *returnSize = 0;
    
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) 
            result[(*returnSize)++] = matrix[top][i];
        top++;
        for(int i = top; i <= bottom; i++) 
            result[(*returnSize)++] = matrix[i][right];
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--) 
                result[(*returnSize)++] = matrix[bottom][i];
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--) 
                result[(*returnSize)++] = matrix[i][left];
            left++;
        }
    }
    return result;
}
