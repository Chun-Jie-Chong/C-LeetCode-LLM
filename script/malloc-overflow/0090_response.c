#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int** result, int* resultSize, int* columnSizes, int* tempList, int tempListSize, int* nums, int numsSize, int start) {
    result[*resultSize] = malloc(tempListSize * sizeof(int));
    for (int i = 0; i < tempListSize; i++) {
        result[*resultSize][i] = tempList[i];
    }
    columnSizes[*resultSize] = tempListSize;
    (*resultSize)++;
    
    for (int i = start; i < numsSize; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        tempList[tempListSize] = nums[i];
        backtrack(result, resultSize, columnSizes, tempList, tempListSize + 1, nums, numsSize, i + 1);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int maxSubsets = 1 << numsSize;
    int** result = malloc(maxSubsets * sizeof(int*));
    *returnColumnSizes = malloc(maxSubsets * sizeof(int));
    int* tempList = malloc(numsSize * sizeof(int));
    
    *returnSize = 0;
    backtrack(result, returnSize, *returnColumnSizes, tempList, 0, nums, numsSize, 0);
    
    free(tempList);
    return result;
}
