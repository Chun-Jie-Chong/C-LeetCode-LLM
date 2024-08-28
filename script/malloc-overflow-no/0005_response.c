#include <string.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int maxLen = 1, start = 0;
    int dp[1000][1000] = {0};
    
    for (int i = 0; i < len; ++i) {
        dp[i][i] = 1;
    }
    
    for (int i = len - 2; i >= 0; --i) {
        for (int j = i + 1; j < len; ++j) {
            if (s[i] == s[j]) {
                if (j - i == 1 || dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
    }
    
    char *res = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';
    return res;
}
