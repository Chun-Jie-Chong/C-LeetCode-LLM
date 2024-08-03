#include <stdlib.h>
#include <string.h>

int calPoints(char **ops, int opsSize) {
    int *stack = (int *)malloc(sizeof(int) * opsSize);
    int top = -1;
    int sum = 0;
    
    for (int i = 0; i < opsSize; i++) {
        if (strcmp(ops[i], "C") == 0) {
            sum -= stack[top--];
        } else if (strcmp(ops[i], "D") == 0) {
            stack[++top] = 2 * stack[top];
            sum += stack[top];
        } else if (strcmp(ops[i], "+") == 0) {
            stack[++top] = stack[top] + stack[top - 1];
            sum += stack[top];
        } else {
            int num = atoi(ops[i]);
            stack[++top] = num;
            sum += num;
        }
    }
    
    free(stack);
    return sum;
}
