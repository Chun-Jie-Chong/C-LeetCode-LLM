#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    int dp[366] = {0};
    int dayIndex = 0;
    
    for(int i = 1; i <= 365; i++) {
        if (dayIndex < daysSize && i == days[dayIndex]) {
            int cost1 = dp[i-1] + costs[0];
            int cost7 = dp[i-7 > 0 ? i-7 : 0] + costs[1];
            int cost30 = dp[i-30 > 0 ? i-30 : 0] + costs[2];
            dp[i] = (cost1 < cost7 ? cost1 : cost7);
            dp[i] = (dp[i] < cost30 ? dp[i] : cost30);
            dayIndex++;
        } else {
            dp[i] = dp[i-1];
        }
    }
    
    return dp[365];
}
