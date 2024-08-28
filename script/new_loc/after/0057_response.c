#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int i = 0, k = 0;

    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[k] = intervals[i];
        (*returnColumnSizes)[k++] = 2;
        i++;
    }

    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        i++;
    }

    result[k] = newInterval;
    (*returnColumnSizes)[k++] = 2;

    while (i < intervalsSize) {
        result[k] = intervals[i];
        (*returnColumnSizes)[k++] = 2;
        i++;
    }

    *returnSize = k;
    return result;
}
