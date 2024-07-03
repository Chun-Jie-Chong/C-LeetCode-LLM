#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

long long maxMinProduct(int* nums, int numsSize) {
    int* left = (int*)malloc(numsSize * sizeof(int));
    int* right = (int*)malloc(numsSize * sizeof(int));
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefix[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    left[0] = -1;
    for (int i = 1; i < numsSize; i++) {
        int l = i - 1;
        while (l >= 0 && nums[l] >= nums[i]) l = left[l];
        left[i] = l;
    }

    right[numsSize - 1] = numsSize;
    for (int i = numsSize - 2; i >= 0; i--) {
        int r = i + 1;
        while (r < numsSize && nums[r] >= nums[i]) r = right[r];
        right[i] = r;
    }

    long long maxProduct = 0;
    for (int i = 0; i < numsSize; i++) {
        long long sum = prefix[right[i]] - prefix[left[i] + 1];
        long long product = sum * nums[i];
        if (product > maxProduct) maxProduct = product;
    }

    free(left);
    free(right);
    free(prefix);
    return maxProduct % MOD;
}
