#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrangeArray(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comp);
    
    for (int i = 1; i < numsSize - 1; i += 2) {
        swap(&nums[i], &nums[i + 1]);
    }
}
