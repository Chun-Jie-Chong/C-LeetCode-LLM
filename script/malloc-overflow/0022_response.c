#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateParenthesisHelper(int n, int open, int close, char *current, int index, char **result, int *returnSize) {
    if (index == 2 * n) {
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[index] = '(';
        generateParenthesisHelper(n, open + 1, close, current, index + 1, result, returnSize);
    }
    if (close < open) {
        current[index] = ')';
        generateParenthesisHelper(n, open, close + 1, current, index + 1, result, returnSize);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    *returnSize = 0;
    int maxSize = 1;
    for (int i = 1; i <= n; ++i)
        maxSize *= 2 * i / (i + 1);  // To calculate Catalan number C_n
    
    char **result = (char **)malloc(maxSize * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    current[2 * n] = '\0';

    generateParenthesisHelper(n, 0, 0, current, 0, result, returnSize);

    free(current);
    return result;
}
