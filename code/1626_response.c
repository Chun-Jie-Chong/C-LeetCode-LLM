#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    int ageA = ((int *)a)[1];
    int ageB = ((int *)b)[1];
    int scoreA = ((int *)a)[0];
    int scoreB = ((int *)b)[0];
    
    if (ageA == ageB)
        return scoreA - scoreB;
    return ageA - ageB;
}

int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize) {
    int players[scoresSize][2];
    
    for (int i = 0; i < scoresSize; i++) {
        players[i][0] = scores[i];
        players[i][1] = ages[i];
    }
    
    qsort(players, scoresSize, sizeof(players[0]), compare);
    
    int dp[scoresSize];
    int maxScore = 0;
    
    for (int i = 0; i < scoresSize; i++) {
        dp[i] = players[i][0];
        for (int j = 0; j < i; j++) {
            if (players[j][0] <= players[i][0]) {
                dp[i] = (dp[i] > dp[j] + players[i][0]) ? dp[i] : dp[j] + players[i][0];
            }
        }
        maxScore = (maxScore > dp[i]) ? maxScore : dp[i];
    }
    
    return maxScore;
}
