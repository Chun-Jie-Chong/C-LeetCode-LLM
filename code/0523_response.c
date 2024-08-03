#include <stdbool.h>

bool checkSubarraySum(int* nums, int numsSize, int k) {
    if (numsSize < 2) return false;

    int sum = 0;
    int remainder;
    int remainder_map[numsSize];

    for (int i = 0; i < numsSize; i++) {
        remainder_map[i] = -1;
    }

    remainder_map[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        remainder = sum % k;

        if (remainder < 0) remainder += k;

        if (remainder_map[remainder] < 0) {
            remainder_map[remainder] = i + 1;
        } else if (i - remainder_map[remainder] > 0) {
            return true;
        }
    }
    
    return false;
}
