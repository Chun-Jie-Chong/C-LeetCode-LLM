#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* output = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;
    
    if (*returnSize == 0) {
      *returnSize = 0;
      return NULL;
    }

    int* deque = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;

    for (int i = 0; i < numsSize; ++i) {
        if (front <= rear && deque[front] < i - k + 1) {
            front++;
        }
        
        while (front <= rear && nums[deque[rear]] <= nums[i]) {
            rear--;
        }

        deque[++rear] = i;
        
        if (i >= k - 1) {
            output[i - k + 1] = nums[deque[front]];
        }
    }
    
    free(deque);
    return output;
}
