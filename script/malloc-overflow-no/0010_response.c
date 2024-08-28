#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    bool dp[s_len + 1][p_len + 1];
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for (int j = 2; j <= p_len; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= p_len; j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] |= dp[i - 1][j];
                }
            }
        }
    }

    return dp[s_len][p_len];
}
