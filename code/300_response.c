#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int *dp = (int *)malloc(sizeof(int) * numsSize);
    int maxLength = 1;
    
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
        maxLength = dp[i] > maxLength ? dp[i] : maxLength;
    }
    
    free(dp);
    return maxLength;
}
