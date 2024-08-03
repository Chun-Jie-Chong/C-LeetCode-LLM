#include <stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int target) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (abs(target) > sum || (target + sum) % 2 != 0) {
        return 0;
    }
    int newTarget = (target + sum) / 2;

    int* dp = (int*)calloc(newTarget + 1, sizeof(int));
    dp[0] = 1;

    for (int i = 0; i < numsSize; i++) {
        for (int j = newTarget; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }

    int result = dp[newTarget];
    free(dp);
    return result;
}
