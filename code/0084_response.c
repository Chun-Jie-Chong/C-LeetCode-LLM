#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int* heights, int heightsSize){
    int *stack = (int *)malloc(sizeof(int) * (heightsSize + 1));
    int top = -1, max_area = 0, index = 0, i;

    while (index < heightsSize) {
        if (top == -1 || heights[stack[top]] <= heights[index]) {
            stack[++top] = index++;
        } else {
            int height = heights[stack[top--]];
            int width = (top == -1) ? index : index - stack[top] - 1;
            max_area = (max_area > height * width) ? max_area : height * width;
        }
    }
    while (top != -1) {
        int height = heights[stack[top--]];
        int width = (top == -1) ? index : index - stack[top] - 1;
        max_area = (max_area > height * width) ? max_area : height * width;
    }
    free(stack);
    return max_area;
}
