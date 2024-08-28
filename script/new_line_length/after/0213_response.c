#include <stdio.h>
#include <string.h>

int robSingle(int* nums, int numsSize) {
    int prev1 = 0, prev2 = 0;
    for (int i = 0; i < numsSize; ++i) {
        int temp = prev1;
        prev1 = prev2 + nums[i] > prev1 ? prev2 + nums[i] : prev1;
        prev2 = temp;
    }
    return prev1;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
    int rob1 = robSingle(nums, numsSize - 1);
    int rob2 = robSingle(nums + 1, numsSize - 1);
    return rob1 > rob2 ? rob1 : rob2;
}
