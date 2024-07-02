#include <stdlib.h>

#define MOD 1000000007

int countGoodStrings(int low, int high, int zero, int one) {
    long *dp = (long *)calloc(high + 1, sizeof(long));
    dp[0] = 1;

    for (int i = 1; i <= high; i++) {
        if (i >= zero) {
            dp[i] = (dp[i] + dp[i - zero]) % MOD;
        }
        if (i >= one) {
            dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
    }

    long result = 0;
    for (int i = low; i <= high; i++) {
        result = (result + dp[i]) % MOD;
    }

    free(dp);
    return (int)result;
}
