#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int** res, int* returnSize, int* returnColumnSizes, 
               int* subset, int subsetSize, int* nums, int numsSize, 
               int start) {
    int* newSubset = malloc(subsetSize * sizeof(int));
    for (int i = 0; i < subsetSize; i++) {
        newSubset[i] = subset[i];
    }
    res[*returnSize] = newSubset;
    returnColumnSizes[*returnSize] = subsetSize;
    (*returnSize)++;
    
    for (int i = start; i < numsSize; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        subset[subsetSize] = nums[i];
        backtrack(res, returnSize, returnColumnSizes, subset, subsetSize + 1, 
                  nums, numsSize, i + 1);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, 
                     int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int subset[numsSize];
    int** res = malloc(1000 * sizeof(int*));
    *returnColumnSizes = malloc(1000 * sizeof(int));
    *returnSize = 0;
    
    backtrack(res, returnSize, *returnColumnSizes, subset, 0, nums, 
              numsSize, 0);
    return res;
}
