#include <stdio.h>
#include <stdlib.h>

void dfs(int* candidates, int candidatesSize, int target, 
         int* stack, int stackSize, int** results, 
         int* returnSize, int** returnColumnSizes, int start) {
    if (target == 0) {
        results[*returnSize] = (int*)malloc(stackSize * sizeof(int));
        for (int i = 0; i < stackSize; ++i)
            results[*returnSize][i] = stack[i];
        (*returnColumnSizes)[*returnSize] = stackSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; ++i) {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        stack[stackSize] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], 
            stack, stackSize + 1, results, returnSize, 
            returnColumnSizes, i + 1);
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** combinationSum2(int* candidates, int candidatesSize, 
                      int target, int* returnSize, 
                      int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int** results = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));

    int* stack = (int*)malloc(candidatesSize * sizeof(int));
    *returnSize = 0;

    dfs(candidates, candidatesSize, target, stack, 0, 
        results, returnSize, returnColumnSizes, 0);

    free(stack);
    return results;
}