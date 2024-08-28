#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    Car* cars = (Car*)malloc(positionSize * sizeof(Car));
    for (int i = 0; i < positionSize; ++i) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars based on their starting positions in descending order
    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double timeToReachTarget = 0.0;

    // Traverse through each car and determine the number of fleets
    for (int i = 0; i < positionSize; ++i) {
        double currentCarTimeToTarget = (double)(target - cars[i].position) / cars[i].speed;
        if (currentCarTimeToTarget > timeToReachTarget) {
            timeToReachTarget = currentCarTimeToTarget;
            fleets++;
        }
    }

    free(cars);
    return fleets;
}
