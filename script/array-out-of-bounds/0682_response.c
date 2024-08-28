#include <stdlib.h>
#include <string.h>

int calPoints(char ** ops, int opsSize){
    int *stack = (int*) malloc(opsSize * sizeof(int));
    int top = -1;
    int sum = 0;
    
    for (int i = 0; i < opsSize; ++i) {
        if (strcmp(ops[i], "+") == 0) {
            int newScore = stack[top] + stack[top - 1];
            stack[++top] = newScore;
        } else if (strcmp(ops[i], "D") == 0) {
            int newScore = 2 * stack[top];
            stack[++top] = newScore;
        } else if (strcmp(ops[i], "C") == 0) {
            --top;
        } else {
            int newScore = atoi(ops[i]);
            stack[++top] = newScore;
        }
    }
    
    for (int i = 0; i <= top; ++i) {
        sum += stack[i];
    }
    
    free(stack);
    return sum;
}
