#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    int *order = (int*)malloc(positionSize * sizeof(int));
    for (int i = 0; i < positionSize; i++) {
        order[i] = position[i];
    }
    
    qsort(order, positionSize, sizeof(int), compare);
    
    double *arrivalTime = (double*)malloc(positionSize * sizeof(double));
    for (int i = 0; i < positionSize; i++) {
        int pos = order[i];
        for (int j = 0; j < positionSize; j++) {
            if (position[j] == pos) {
                arrivalTime[i] = (double)(target - position[j]) / speed[j];
                break;
            }
        }
    }
    
    int fleets = 0;
    double lastTime = -1.0;
    
    for (int i = 0; i < positionSize; i++) {
        if (arrivalTime[i] > lastTime) {
            fleets++;
            lastTime = arrivalTime[i];
        }
    }
    
    free(order);
    free(arrivalTime);
    
    return fleets;
}
