#include <stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    bool firstRow = false, firstCol = false;
    int i, j;
    
    for (i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            firstCol = true;
            break;
        }
    }
    
    for (j = 0; j < matrixColSize[0]; j++) {
        if (matrix[0][j] == 0) {
            firstRow = true;
            break;
        }
    }
    
    for (i = 1; i < matrixSize; i++) {
        for (j = 1; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for (i = 1; i < matrixSize; i++) {
        for (j = 1; j < matrixColSize[0]; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if (firstRow) {
        for (j = 0; j < matrixColSize[0]; j++) {
            matrix[0][j] = 0;
        }
    }
    
    if (firstCol) {
        for (i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}
