#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    long long *dp = (long long *)malloc(sizeof(long long) * (questionsSize + 1));
    for (int i = 0; i <= questionsSize; i++) {
        dp[i] = 0;
    }

    for (int i = questionsSize - 1; i >= 0; i--) {
        int points = questions[i][0];
        int brainpower = questions[i][1];
        int nextIndex = i + brainpower + 1;

        dp[i] = max(dp[i + 1], points + (nextIndex < questionsSize ? dp[nextIndex] : 0));
    }

    long long result = dp[0];
    free(dp);
    return result;
}
