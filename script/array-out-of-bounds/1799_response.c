#include <stdio.h>
#include <stdlib.h>

// Function to compute Greatest Common Divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to compute maximum score
int maxScore(int* nums, int numsSize) {
    int n = numsSize / 2;
    int max = 0;

    int possibleScores[1 << (2 * n)];
    for (int i = 0; i < (1 << (2 * n)); ++i) {
        possibleScores[i] = -1;
    }

    possibleScores[0] = 0;

    for (int i = 0; i < (1 << (2 * n)); ++i) {
        int cnt = 0;
        for (int j = 0; j < (2 * n); ++j) {
            if (i & (1 << j)) {
                cnt++;
            }
        }

        if (cnt % 2 != 0) {
            continue;
        }

        for (int p = 0; p < 2 * n; ++p) {
            if (i & (1 << p)) {
                continue;
            }

            for (int q = p + 1; q < 2 * n; ++q) {
                if (i & (1 << q)) {
                    continue;
                }

                int newMask = i | (1 << p) | (1 << q);
                int currentScore = cnt / 2 + 1;
                int score = possibleScores[i] + currentScore * gcd(nums[p], nums[q]);
                if (score > possibleScores[newMask]) {
                    possibleScores[newMask] = score;
                    if (score > max) {
                        max = score;
                    }
                }
            }
        }
    }

    return max;
}
