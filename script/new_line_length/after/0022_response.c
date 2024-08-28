#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char** result, int* returnSize, 
            char* current, int open, int close, 
            int max) {
    if (strlen(current) == max * 2) {
        result[*returnSize] = (char*) malloc(
                              sizeof(char) * (max * 2 + 1));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    if (open < max) {
        current[strlen(current)] = '(';
        backtrack(result, returnSize, current, 
                open + 1, close, max);
        current[strlen(current) - 1] = '\0';
    }
    if (close < open) {
        current[strlen(current)] = ')';
        backtrack(result, returnSize, current, 
                open, close + 1, max);
        current[strlen(current) - 1] = '\0';
    }
}

char **generateParenthesis(int n, int *returnSize) {
    char** result = (char**)malloc(sizeof(char*) * 5000);
    char* current = (char*)malloc(sizeof(char) * (n * 2 + 1));
    current[0] = '\0';
    *returnSize = 0;
    backtrack(result, returnSize, current, 0, 0, n);
    free(current);
    return result;
}
