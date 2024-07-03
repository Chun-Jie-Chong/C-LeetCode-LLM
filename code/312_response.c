#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int maxCoins(int* nums, int numsSize) {
    int n = numsSize + 2;
    int newNums[n];
    newNums[0] = newNums[n-1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        newNums[i] = nums[i-1];
    }
    
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    for (int length = 2; length < n; ++length) {
        for (int left = 0; left < n - length; ++left) {
            int right = left + length;
            for (int i = left + 1; i < right; ++i) {
                dp[left][right] = fmax(dp[left][right],
                                    newNums[left] * newNums[i] * newNums[right] +
                                    dp[left][i] + dp[i][right]);
            }
        }
    }
    return dp[0][n-1];
}
