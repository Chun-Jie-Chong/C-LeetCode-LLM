#include <stdio.h>
#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int start = 0, end = 0, sum = 0, minLength = INT_MAX;

    while (end < numsSize) {
        sum += nums[end++];

        while (sum >= target) {
            if (end - start < minLength) {
                minLength = end - start;
            }
            sum -= nums[start++];
        }
    }

    return minLength == INT_MAX ? 0 : minLength;
}
