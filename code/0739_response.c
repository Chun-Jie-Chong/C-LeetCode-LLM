#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * temperaturesSize);
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize); // Stack to hold indices
    int top = -1; // Stack pointer
    
    for (int i = 0; i < temperaturesSize; i++) {
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            answer[idx] = i - idx;
        }
        stack[++top] = i;
    }
    
    while (top != -1) {
        answer[stack[top--]] = 0;
    }
    
    *returnSize = temperaturesSize;
    free(stack);
    return answer;
}
