#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int* dp = (int*)malloc(triangleColSize[triangleSize-1] * sizeof(int));
    memcpy(dp, triangle[triangleSize-1], triangleColSize[triangleSize-1] * sizeof(int));

    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j < triangleColSize[i]; j++) {
            dp[j] = triangle[i][j] + (dp[j] < dp[j + 1] ? dp[j] : dp[j + 1]);
        }
    }

    int result = dp[0];
    free(dp);
    return result;
}
