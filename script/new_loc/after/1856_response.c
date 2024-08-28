#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long maxMinProduct(int* nums, int numsSize) {
    long long *prefixSum = (long long*)malloc((numsSize + 1) * sizeof(long long));
    int *left = (int*)malloc(numsSize * sizeof(int));
    int *right = (int*)malloc(numsSize * sizeof(int));
    
    prefixSum[0] = 0;
    for(int i = 0; i < numsSize; ++i)
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    
    for(int i = 0; i < numsSize; ++i) {
        left[i] = i;
        while(left[i] > 0 && nums[left[i] - 1] >= nums[i])
            left[i] = left[left[i] - 1];
    }
    
    for(int i = numsSize - 1; i >= 0; --i) {
        right[i] = i;
        while(right[i] < numsSize - 1 && nums[right[i] + 1] >= nums[i])
            right[i] = right[right[i] + 1];
    }

    long long maxProduct = 0;
    for(int i = 0; i < numsSize; ++i) {
        long long sum = prefixSum[right[i] + 1] - prefixSum[left[i]];
        maxProduct = maxProduct > sum * nums[i] ? maxProduct : sum * nums[i];
    }
    
    free(prefixSum);
    free(left);
    free(right);
    
    return maxProduct % MOD;
}
