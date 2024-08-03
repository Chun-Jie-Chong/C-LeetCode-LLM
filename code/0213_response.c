#include <stdio.h>

int robLinear(int* nums, int start, int end) {
    int prev1 = 0, prev2 = 0, current = 0;
    for (int i = start; i <= end; ++i) {
        current = (prev1 > (prev2 + nums[i])) ? prev1 : (prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    return (robLinear(nums, 0, numsSize - 2) > robLinear(nums, 1, numsSize - 1)) 
           ? robLinear(nums, 0, numsSize - 2) 
           : robLinear(nums, 1, numsSize - 1);
}
