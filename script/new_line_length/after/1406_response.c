#include <stdio.h>
#include <string.h>
#include <math.h>

char* stoneGameIII(int* stoneValue, int stoneValueSize){
    static char results[3][5] = {"Bob", "Alice", "Tie"};
    int dp[stoneValueSize + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = stoneValueSize - 1; i >= 0; i--) {
        dp[i] = stoneValue[i] - dp[i + 1];
        if (i + 1 < stoneValueSize) 
            dp[i] = fmax(dp[i], 
                         stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
        if (i + 2 < stoneValueSize)
            dp[i] = fmax(dp[i], 
                         stoneValue[i] + stoneValue[i + 1] + 
                         stoneValue[i + 2] - dp[i + 3]);
    }
    return dp[0] == 0 ? results[2] : dp[0] > 0 ? results[1] : results[0];
}
