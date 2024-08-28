#include <stdio.h>
#include <stdlib.h>

void dfs(int* candidates, int candidatesSize, int target,
         int* current, int currentSize, int start,
         int*** result, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        (*result)[*returnSize] = (int*)malloc(currentSize * sizeof(int));
        for (int i = 0; i < currentSize; i++) {
            (*result)[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            current[currentSize] = candidates[i];
            dfs(candidates, candidatesSize, target - candidates[i], current, currentSize + 1,
                i, result, returnSize, returnColumnSizes);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize,
                     int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(150 * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(150 * sizeof(int));
    int* current = (int*)malloc(target * sizeof(int));
    dfs(candidates, candidatesSize, target, current, 0, 0, &result, returnSize, returnColumnSizes);
    free(current);
    return result;
}

