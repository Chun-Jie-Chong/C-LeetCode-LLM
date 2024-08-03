#include <stdio.h>
#include <stdlib.h>

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int maxPile = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > maxPile) {
            maxPile = piles[i];
        }
    }

    int left = 1, right = maxPile;

    while (left < right) {
        int mid = left + (right - left) / 2;
        int hoursNeeded = 0;
        for (int i = 0; i < pilesSize; i++) {
            hoursNeeded += (piles[i] + mid - 1) / mid;
        }
        if (hoursNeeded > h) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
