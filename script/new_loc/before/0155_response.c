#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *data;
    int *minData;
    int top;
    int minTop;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 10000;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    stack->minData = (int*)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    stack->minTop = -1;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top == obj->capacity - 1) return;
    obj->data[++(obj->top)] = val;
    if (obj->minTop == -1 || val <= obj->minData[obj->minTop]) {
        obj->minData[++(obj->minTop)] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;
    if (obj->data[obj->top] == obj->minData[obj->minTop]) {
        --(obj->minTop);
    }
    --(obj->top);
}

int minStackTop(MinStack* obj) {
    if (obj->top == -1) return INT_MIN;
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (obj->minTop == -1) return INT_MIN;
    return obj->minData[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->minData);
    free(obj);
}
