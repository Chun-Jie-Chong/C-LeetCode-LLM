#include <stdio.h>
#include <stdlib.h>

double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n >= k + maxPts) 
        return 1.0;
    
    double *dp = malloc((n + 1) * sizeof(double));
    double sum = 1.0, result = 0.0;

    dp[0] = 1.0;

    for (int i = 1; i <= n; i++) {
        dp[i] = sum / maxPts;
        if (i < k) sum += dp[i];
        else result += dp[i];
        if (i >= maxPts) sum -= dp[i - maxPts];
    }

    free(dp);
    return result;
}
