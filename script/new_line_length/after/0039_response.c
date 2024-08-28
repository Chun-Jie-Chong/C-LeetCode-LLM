#include <stdio.h>
#include <stdlib.h>

void dfs(int* candidates, int candidatesSize, int target, int* current, 
         int currSize, int** result, int* returnSize, int* returnColSizes, 
         int start) {
    if (target == 0) {
        result[*returnSize] = (int*)malloc(currSize * sizeof(int));
        for (int i = 0; i < currSize; i++)
            result[*returnSize][i] = current[i];
        returnColSizes[*returnSize] = currSize;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            current[currSize] = candidates[i];
            dfs(candidates, candidatesSize, target - candidates[i], current, 
                currSize + 1, result, returnSize, returnColSizes, i);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, 
                     int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(150 * sizeof(int*));
    int* current = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(150 * sizeof(int));
    dfs(candidates, candidatesSize, target, current, 0, result, returnSize, 
        *returnColumnSizes, 0);
    free(current);
    return result;
}
