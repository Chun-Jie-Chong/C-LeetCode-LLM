#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int maxScore(int* nums, int numsSize) {
    int dp[1 << numsSize];
    for (int i = 0; i < (1 << numsSize); i++) dp[i] = 0;
    int n = numsSize / 2;

    for (int mask = 1; mask < (1 << numsSize); mask++) {
        int bits = __builtin_popcount(mask);
        if (bits % 2 == 0) {
            for (int i = 0; i < numsSize; i++) {
                if (mask & (1 << i)) {
                    for (int j = i + 1; j < numsSize; j++) {
                        if (mask & (1 << j)) {
                            dp[mask] = fmax(dp[mask], dp[mask ^ (1 << i) ^ (1 << j)] + (bits / 2) * gcd(nums[i], nums[j]));
                        }
                    }
                }
            }
        }
    }
    return dp[(1 << numsSize) - 1];
}
