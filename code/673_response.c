#include <stdio.h>
#include <stdlib.h>

int findNumberOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int* lengths = (int*)malloc(numsSize * sizeof(int));
    int* counts = (int*)malloc(numsSize * sizeof(int));
    int maxLen = 0, result = 0;

    for (int i = 0; i < numsSize; ++i) {
        lengths[i] = 1;
        counts[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                } else if (lengths[j] + 1 == lengths[i]) {
                    counts[i] += counts[j];
                }
            }
        }
        if (lengths[i] > maxLen) {
            maxLen = lengths[i];
            result = counts[i];
        } else if (lengths[i] == maxLen) {
            result += counts[i];
        }
    }

    free(lengths);
    free(counts);
    return result;
}
