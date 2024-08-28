#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int **result = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int i = 0, idx = 0;
    
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[idx] = (int*)malloc(2 * sizeof(int));
        result[idx][0] = intervals[i][0];
        result[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }
    
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmin(newInterval[1], intervals[i][1]);
        i++;
    }
    
    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = newInterval[0];
    result[idx][1] = newInterval[1];
    (*returnColumnSizes)[idx] = 2;
    idx++;
    
    while (i < intervalsSize) {
        result[idx] = (int*)malloc(2 * sizeof(int));
        result[idx][0] = intervals[i][0];
        result[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }
    
    *returnSize = idx;
    return result;
}
