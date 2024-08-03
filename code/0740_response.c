#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int deleteAndEarn(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int max_val = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }

    int *sum = (int *)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        sum[nums[i]] += nums[i];
    }

    int *dp = (int *)calloc(max_val + 1, sizeof(int));
    dp[1] = sum[1];
    for (int i = 2; i <= max_val; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
    }

    int result = dp[max_val];
    free(sum);
    free(dp);

    return result;
}
