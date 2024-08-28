#include <stdio.h>
#include <string.h>

int numDistinct(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    if (n > m) return 0;

    unsigned int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}
