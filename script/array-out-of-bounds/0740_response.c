#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int deleteAndEarn(int* nums, int numsSize) {
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    
    int *sum = (int *)calloc(maxVal + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        sum[nums[i]] += nums[i];
    }
    
    int prev = 0, curr = 0;
    for (int i = 0; i <= maxVal; i++) {
        int temp = curr;
        curr = max(curr, prev + sum[i]);
        prev = temp;
    }
    
    free(sum);
    return curr;
}
