#include <stdlib.h>

int combinationSum4(int* nums, int numsSize, int target) {
    int* dp = (int*)calloc(target + 1, sizeof(int));
    if(dp == NULL) return 0;
    
    dp[0] = 1;

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i - nums[j] >= 0) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }

    int result = dp[target];
    free(dp);
    return result;
}
