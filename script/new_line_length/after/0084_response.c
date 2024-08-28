#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int* heights, int heightsSize){
    int *stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1, maxArea = 0;
    for (int i = 0; i <= heightsSize; i++) {
        int h = (i == heightsSize ? 0 : heights[i]);
        while (top >= 0 && h < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1 ? i : i - stack[top] - 1);
            maxArea = (height * width > maxArea) ? 
                    height * width : maxArea;
        }
        stack[++top] = i;
    }
    free(stack);
    return maxArea;
}
