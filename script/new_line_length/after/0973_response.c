#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    int *pointA = *(int **)a;
    int *pointB = *(int **)b;
    return (pointA[0]*pointA[0] + pointA[1]*pointA[1]) - 
           (pointB[0]*pointB[0] + pointB[1]*pointB[1]);
}

int** kClosest(int** points, int pointsSize, 
               int* pointsColSize, int k, 
               int* returnSize, int** returnColumnSizes) 
{
    qsort(points, pointsSize, sizeof(int*), compare);
    
    int **result = (int **)malloc(sizeof(int *) * k);
    *returnColumnSizes = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++) {
        result[i] = (int *)malloc(2 * sizeof(int));
        result[i][0] = points[i][0];
        result[i][1] = points[i][1];
        (*returnColumnSizes)[i] = 2;
    }
    
    *returnSize = k;
    return result;
}
