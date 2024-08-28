#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtrack(int* nums, int numsSize, int** res, int* returnSize, int* tempList, int* used, int level) {
    if (level == numsSize) {
        res[*returnSize] = malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            res[*returnSize][i] = tempList[i];
        }
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        used[i] = 1;
        tempList[level] = nums[i];
        backtrack(nums, numsSize, res, returnSize, tempList, used, level + 1);
        used[i] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** res = malloc(5000 * sizeof(int*));
    int* tempList = malloc(numsSize * sizeof(int));
    int* used = malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        used[i] = 0;
    }

    *returnSize = 0;
    backtrack(nums, numsSize, res, returnSize, tempList, used, 0);

    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    free(tempList);
    free(used);
    
    return res;
}
