#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Note: Both returned array and *returnColumnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int totalSize = intervalsSize + 1;
    int** result = (int**)malloc(totalSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalSize * sizeof(int));
    
    int i = 0, k = 0;
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[k] = (int*)malloc(2 * sizeof(int));
        result[k][0] = intervals[i][0];
        result[k][1] = intervals[i][1];
        (*returnColumnSizes)[k++] = 2;
        i++;
    }
    
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
        newInterval[1] = MAX(newInterval[1], intervals[i][1]);
        i++;
    }
    
    result[k] = (int*)malloc(2 * sizeof(int));
    result[k][0] = newInterval[0];
    result[k][1] = newInterval[1];
    (*returnColumnSizes)[k++] = 2;
    
    while (i < intervalsSize) {
        result[k] = (int*)malloc(2 * sizeof(int));
        result[k][0] = intervals[i][0];
        result[k][1] = intervals[i][1];
        (*returnColumnSizes)[k++] = 2;
        i++;
    }
    
    *returnSize = k;
    return result;
}
