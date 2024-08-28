#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int maxScore(int* nums, int numsSize){
    int n = numsSize / 2;
    int dp[1 << (2 * n)];
    for (int i = 0; i < (1 << (2 * n)); ++i)
        dp[i] = 0;

    for (int mask = 0; mask < (1 << (2 * n)); mask++) {
        int bits = __builtin_popcount(mask);
        if (bits % 2 != 0) continue;
        int step = bits / 2 + 1;
        for (int i = 0; i < 2 * n; i++) {
            if (mask & (1 << i)) continue;
            for (int j = i + 1; j < 2 * n; j++) {
                if (mask & (1 << j)) continue;
                int newMask = mask | (1 << i) | (1 << j);
                dp[newMask] = fmax(dp[newMask], dp[mask] + step * gcd(nums[i], nums[j]));
            }
        }
    }

    return dp[(1 << (2 * n)) - 1];
}
