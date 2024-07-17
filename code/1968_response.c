#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmp);

    // Allocate memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // Use two pointers to fill the result array in a zigzag manner
    int left = 0, right = (numsSize + 1) / 2, index = 0;
    while (left < (numsSize + 1) / 2 || right < numsSize) {
        if (left < (numsSize + 1) / 2) {
            result[index++] = nums[left++];
        }
        if (right < numsSize) {
            result[index++] = nums[right++];
        }
    }
    
    // Set the return size
    *returnSize = numsSize;
    return result;
}