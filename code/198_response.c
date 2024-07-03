#include <stdio.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    
    int prev1 = 0;
    int prev2 = 0;
    int maxRobbed = 0;
    
    for (int i = 0; i < numsSize; i++) {
        maxRobbed = (prev1 > prev2 + nums[i]) ? prev1 : (prev2 + nums[i]);
        prev2 = prev1;
        prev1 = maxRobbed;
    }

    return maxRobbed;
}
