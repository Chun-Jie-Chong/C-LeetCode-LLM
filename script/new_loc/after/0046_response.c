#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permuteHelper(int* nums, int numsSize, int** result, int* returnSize, int start) {
    if (start == numsSize) {
        result[*returnSize] = malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) result[*returnSize][i] = nums[i];
        (*returnSize)++;
        return;
    }
    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);
        permuteHelper(nums, numsSize, result, returnSize, start + 1);
        swap(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(720 * sizeof(int*));  // Since numsSize maximum is 6, max permutations = 6! = 720
    *returnSize = 0;
    permuteHelper(nums, numsSize, result, returnSize, 0);
    
    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = numsSize;
    
    return result;
}
