#include <stdlib.h>

void backtrack(int *nums, int numsSize, int **result, int *returnSize, int **colSizes, int *subset, int subsetSize, int start) {
    result[*returnSize] = malloc(subsetSize * sizeof(int));
    for (int i = 0; i < subsetSize; i++) {
        result[*returnSize][i] = subset[i];
    }
    (*colSizes)[*returnSize] = subsetSize;
    (*returnSize)++;
    
    for (int i = start; i < numsSize; i++) {
        subset[subsetSize] = nums[i];
        backtrack(nums, numsSize, result, returnSize, colSizes, subset, subsetSize + 1, i + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxSize = 1 << numsSize;
    int **result = malloc(maxSize * sizeof(int*));
    *returnColumnSizes = malloc(maxSize * sizeof(int));
    *returnSize = 0;
    int *subset = malloc(numsSize * sizeof(int));
    
    backtrack(nums, numsSize, result, returnSize, returnColumnSizes, subset, 0, 0);
    
    free(subset);
    return result;
}
