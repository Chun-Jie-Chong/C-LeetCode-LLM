#include <stdbool.h>
#include <stdlib.h>

bool checkSubarraySum(int* nums, int numsSize, int k) {
    int *remToIndex = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        remToIndex[i] = -1;
    }

    remToIndex[0] = 0;
    int cumulativeSum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        cumulativeSum += nums[i];
        int remainder = cumulativeSum % k;
        if (remainder < 0) remainder += k;

        if (remToIndex[remainder] != -1) {
            if (i + 1 - remToIndex[remainder] >= 2) {
                free(remToIndex);
                return true;
            }
        } else {
            remToIndex[remainder] = i + 1;
        }
    }

    free(remToIndex);
    return false;
}
