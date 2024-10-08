#include <string.h>

int numDistinct(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    if (n > m) return 0;
    
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int j = 0; j <= m; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[n][m];
}
