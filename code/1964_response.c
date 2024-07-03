#include <stdio.h>
#include <stdlib.h>

int* longestObstacleCourseAtEachPosition(int* obstacles, int obstaclesSize, int* returnSize) {
    int *lis = (int*)malloc(sizeof(int) * obstaclesSize);
    int *ans = (int*)malloc(sizeof(int) * obstaclesSize);
    int length = 0;

    for (int i = 0; i < obstaclesSize; i++) {
        int left = 0, right = length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (lis[mid] <= obstacles[i]) 
                left = mid + 1;
            else 
                right = mid;
        }
        if (left >= length) {
            lis[length++] = obstacles[i];
        } else {
            lis[left] = obstacles[i];
        }
        ans[i] = left + 1;
    }
    
    free(lis);
    *returnSize = obstaclesSize;
    
    return ans;
}
