#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

bool isPossibleDivide(int* hand, int handSize, int groupSize) {
    if (handSize % groupSize != 0) return false;
    
    qsort(hand, handSize, sizeof(int), cmpfunc);

    int *count = (int*)calloc(handSize, sizeof(int));
    
    for (int i = 0; i < handSize; i++) {
        count[hand[i] % handSize]++;
    }

    for (int i = 0; i < handSize; i++) {
        if (count[hand[i] % handSize] > 0) {
            int value = hand[i];
            for (int j = 0; j < groupSize; j++) {
                if (count[(value + j) % handSize] > 0) {
                    count[(value + j) % handSize]--;
                } else {
                    free(count);
                    return false;
                }
            }
        }
    }

    free(count);
    return true;
}
