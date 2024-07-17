#include <stdio.h>
#include <string.h>

long long mostPoints(int **questions, int questionsSize, int *questionsColSize){
    long long dp[100000 + 5];
    memset(dp, 0, sizeof(dp));
    
    for (int i = questionsSize - 1; i >= 0; --i) {
        long long solve = questions[i][0] + ((i + questions[i][1] + 1 < questionsSize) ? dp[i + questions[i][1] + 1] : 0);
        long long skip = dp[i + 1];
        dp[i] = (solve > skip) ? solve : skip;
    }
    
    return dp[0];
}
