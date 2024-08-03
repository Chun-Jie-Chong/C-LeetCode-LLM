#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int numDecodings(char * s){
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;
    
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        int oneDigit = s[i-1] - '0';
        int twoDigits = (s[i-2] - '0') * 10 + (s[i-1] - '0');
        
        if (oneDigit >= 1) dp[i] += dp[i-1];
        if (twoDigits >= 10 && twoDigits <= 26) dp[i] += dp[i-2];
    }
    
    return dp[n];
}
