#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *pointA = *(int **)a;
    int *pointB = *(int **)b;
    int distA = pointA[0] * pointA[0] + pointA[1] * pointA[1];
    int distB = pointB[0] * pointB[0] + pointB[1] * pointB[1];
    return distA - distB;
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    qsort(points, pointsSize, sizeof(int *), compare);
    
    int** result = (int **)malloc(K * sizeof(int *));
    *returnColumnSizes = (int *)malloc(K * sizeof(int));
    
    for (int i = 0; i < K; i++) {
        result[i] = points[i];
        (*returnColumnSizes)[i] = 2;
    }
    
    *returnSize = K;
    return result;
}
