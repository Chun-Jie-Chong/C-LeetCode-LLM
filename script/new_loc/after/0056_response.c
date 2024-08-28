#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int idx = 0;
    result[0] = intervals[0];
    (*returnColumnSizes)[0] = 2;
    for (int i = 1; i < intervalsSize; i++) {
        if (result[idx][1] >= intervals[i][0]) {
            result[idx][1] = result[idx][1] > intervals[i][1] ? result[idx][1] : intervals[i][1];
        } else {
            idx++;
            result[idx] = intervals[i];
            (*returnColumnSizes)[idx] = 2;
        }
    }
    *returnSize = idx + 1;
    return result;
}
