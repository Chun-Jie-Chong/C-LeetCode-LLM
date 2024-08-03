#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    int* result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[(*returnSize)++] = i + 1;
        }
    }

    return result;
}
