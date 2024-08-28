#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int dp[stoneValueSize + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = stoneValueSize - 1; i >= 0; --i) {
        dp[i] = stoneValue[i] - dp[i + 1];
        if (i + 2 <= stoneValueSize) {
            dp[i] = (stoneValue[i] + stoneValue[i + 1] - dp[i + 2] > dp[i]) ?
                    stoneValue[i] + stoneValue[i + 1] - dp[i + 2] : dp[i];
        }
        if (i + 3 <= stoneValueSize) {
            dp[i] = (stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3] > dp[i]) ?
                    stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3] : dp[i];
        }
    }
    if (dp[0] > 0) return "Alice";
    if (dp[0] < 0) return "Bob";
    return "Tie";
}
