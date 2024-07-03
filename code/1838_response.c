#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxFrequency(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    long sum = 0;
    int start = 0;
    int maxFreq = 0;

    for (int end = 0; end < numsSize; end++) {
        sum += nums[end];
        
        while (nums[end] * (end - start + 1) - sum > k) {
            sum -= nums[start];
            start++;
        }
        
        maxFreq = (end - start + 1) > maxFreq ? (end - start + 1) : maxFreq;
    }

    return maxFreq;
}
