#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int k = 1; // since the array is sorted, the first element is always unique

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k-1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
