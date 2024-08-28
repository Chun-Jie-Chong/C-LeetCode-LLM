#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXN 15
#define MAXM 50

int minStickers(char **stickers, int stickersSize, char *target) {
    int targetLen = strlen(target);
    int dp[1 << MAXN];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int state = 0; state < (1 << targetLen); ++state) {
        if (dp[state] == -1) continue;

        for (int i = 0; i < stickersSize; ++i) {
            int newState = state;

            int charCount[26] = {0};
            for (int j = 0; stickers[i][j] != '\0'; ++j) {
                charCount[stickers[i][j] - 'a']++;
            }

            for (int j = 0; j < targetLen; ++j) {
                if ((newState & (1 << j)) == 0 && charCount[target[j] - 'a'] > 0) {
                    newState |= (1 << j);
                    charCount[target[j] - 'a']--;
                }
            }

            if (dp[newState] == -1 || dp[newState] > dp[state] + 1) {
                dp[newState] = dp[state] + 1;
            }
        }
    }

    return dp[(1 << targetLen) - 1];
}
