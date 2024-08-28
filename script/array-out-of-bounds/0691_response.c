#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_STICKERS 50
#define MAX_LEN 15
#define CHAR_COUNT 26

int minStickers(char** stickers, int stickersSize, char* target) {
    int stickerCounts[MAX_STICKERS][CHAR_COUNT] = {0};
    int targetLen = strlen(target);
    int dp[1 << MAX_LEN];

    for (int i = 0; i < stickersSize; i++) {
        for (int j = 0; stickers[i][j]; j++) {
            stickerCounts[i][stickers[i][j] - 'a']++;
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    int maxState = (1 << targetLen) - 1;
    
    for (int state = 0; state < (1 << targetLen); state++) {
        if (dp[state] == -1) continue;

        for (int i = 0; i < stickersSize; i++) {
            int nextState = state;
            int stickerCount[CHAR_COUNT];
            memcpy(stickerCount, stickerCounts[i], sizeof(stickerCount));
            
            for (int j = 0; j < targetLen; j++) {
                if (!(state & (1 << j)) && stickerCount[target[j] - 'a'] > 0) {
                    stickerCount[target[j] - 'a']--;
                    nextState |= (1 << j);
                }
            }
            dp[nextState] = dp[nextState] == -1 ? dp[state] + 1 : (dp[state] + 1 < dp[nextState] ? dp[state] + 1 : dp[nextState]);
        }
    }
    return dp[maxState];
}
