#include <stdio.h>
#include <stdlib.h>

void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int* buffer, int bufferSize, int** result) {
    if (target < 0) return;
    if (target == 0) {
        result[*returnSize] = (int*)malloc(sizeof(int) * bufferSize);
        for (int i = 0; i < bufferSize; i++) {
            result[*returnSize][i] = buffer[i];
        }
        (*returnColumnSizes)[*returnSize] = bufferSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < candidatesSize; i++) {
        if (bufferSize > 0 && candidates[i] < buffer[bufferSize - 1]) continue;
        buffer[bufferSize] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, buffer, bufferSize + 1, result);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int maxSize = 150; // Given constraint
    int** result = (int**)malloc(sizeof(int*) * maxSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSize);
    int* buffer = (int*)malloc(sizeof(int) * (target + 1));

    dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, buffer, 0, result);

    free(buffer);
    return result;
}
