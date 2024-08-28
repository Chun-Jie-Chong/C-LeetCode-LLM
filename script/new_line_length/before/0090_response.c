#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int** result, int* returnColumnSizes, int* tempList, int tempListSize, int start, int* returnSize) {
    result[*returnSize] = (int*)malloc(tempListSize * sizeof(int));
    for (int i = 0; i < tempListSize; i++) {
        result[*returnSize][i] = tempList[i];
    }
    returnColumnSizes[*returnSize] = tempListSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        tempList[tempListSize] = nums[i];
        backtrack(nums, numsSize, result, returnColumnSizes, tempList, tempListSize + 1, i + 1, returnSize);
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = 0;
    int maxCombinations = 1 << numsSize;
    int** result = (int**)malloc(maxCombinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCombinations * sizeof(int));
    int* tempList = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, result, *returnColumnSizes, tempList, 0, 0, returnSize);

    free(tempList);
    return result;
}
