#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate(char *current, int open, int close, int max, char **result, int *returnSize) {
    if (strlen(current) == 2 * max) {
        result[*returnSize] = (char *)malloc((2 * max + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < max) {
        current[strlen(current)] = '(';
        current[strlen(current) + 1] = '\0';
        generate(current, open + 1, close, max, result, returnSize);
        current[strlen(current) - 1] = '\0';
    }

    if (close < open) {
        current[strlen(current)] = ')';
        current[strlen(current) + 1] = '\0';
        generate(current, open, close + 1, max, result, returnSize);
        current[strlen(current) - 1] = '\0';
    }
}

char **generateParenthesis(int n, int *returnSize) {
    char **result = (char **)malloc(5000 * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    current[0] = '\0';
    *returnSize = 0;
    generate(current, 0, 0, n, result, returnSize);
    free(current);
    return result;
}
