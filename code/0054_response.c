#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* result = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = 0;
    if (matrixSize == 0 || *matrixColSize == 0) return result;
    
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = *matrixColSize - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }
    return result;
}
