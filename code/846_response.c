#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool isNStraightHand(int* hand, int handSize, int groupSize) {
    if (handSize % groupSize != 0) 
        return false;

    qsort(hand, handSize, sizeof(int), compare);

    int *count = (int *)calloc(hand[handSize-1] + 1, sizeof(int));
    for (int i = 0; i < handSize; i++)
        count[hand[i]]++;

    for (int i = 0; i < handSize; i++) {
        if (count[hand[i]] > 0) {
            for (int j = 0; j < groupSize; j++) {
                if (count[hand[i] + j]-- <= 0) {
                    free(count);  
                    return false;
                }
            }
        }
    }

    free(count);  
    return true;
}
