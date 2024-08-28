#include <stdio.h>
#include <stdlib.h>

void dfs(int* nums, int numsSize, int start, int* subset, int subsetSize, int** result, int* returnSize, int* returnColumnSizes) {
    // Allocate space for the current subset in the result
    result[*returnSize] = (int*)malloc(subsetSize * sizeof(int));
    returnColumnSizes[*returnSize] = subsetSize;
    for (int i = 0; i < subsetSize; i++) {
        result[*returnSize][i] = subset[i];
    }
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        subset[subsetSize] = nums[i];
        dfs(nums, numsSize, i + 1, subset, subsetSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxSubsets = 1 << numsSize; // 2^numsSize
    int** result = (int**)malloc(maxSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSubsets * sizeof(int));
    *returnSize = 0;
    
    int* subset = (int*)malloc(numsSize * sizeof(int));
    dfs(nums, numsSize, 0, subset, 0, result, returnSize, *returnColumnSizes);

    free(subset);
    return result;
}
