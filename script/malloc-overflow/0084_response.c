#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize + 1];
    int top = -1;
    int maxArea = 0;
    
    for (int i = 0; i <= heightsSize; i++) {
        while (top >= 0 && (i == heightsSize || heights[stack[top]] > heights[i])) {
            int height = heights[stack[top--]];
            int width = top == -1 ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea) maxArea = area;
        }
        stack[++top] = i;
    }
    
    return maxArea;
}
