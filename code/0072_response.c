#include <string.h>
#include <stdlib.h>
#include <math.h>

int minDistance(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for(int i = 0; i <= len1; i++) {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + fmin(fmin(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
    }
    
    int result = dp[len1][len2];
    
    for(int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
