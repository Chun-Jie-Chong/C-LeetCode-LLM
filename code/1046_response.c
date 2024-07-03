#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        qsort(stones, stonesSize, sizeof(int), compare);
        if (stones[0] == stones[1]) {
            stones[1] = stones[stonesSize - 1];
            stonesSize -= 2;
        } else {
            stones[1] = stones[0] - stones[1];
            stones[0] = stones[stonesSize - 1];
            stonesSize -= 1;
        }
    }
    return stonesSize == 0 ? 0 : stones[0];
}
