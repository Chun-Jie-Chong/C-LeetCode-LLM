#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    int idx = 0;

    merged[idx] = (int*)malloc(2 * sizeof(int));
    merged[idx][0] = intervals[0][0];
    merged[idx][1] = intervals[0][1];
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    (*returnColumnSizes)[idx] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        if (merged[idx][1] >= intervals[i][0]) {
            if (merged[idx][1] < intervals[i][1]) {
                merged[idx][1] = intervals[i][1];
            }
        } else {
            idx++;
            merged[idx] = (int*)malloc(2 * sizeof(int));
            merged[idx][0] = intervals[i][0];
            merged[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return merged;
}
