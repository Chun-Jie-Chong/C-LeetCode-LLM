#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int *result = (int*)calloc(len1 + len2, sizeof(int));
    char *finalResult = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + result[p2];
            result[p1] += sum / 10;
            result[p2] = sum % 10;
        }
    }

    int index = 0;
    while (index < len1 + len2 && result[index] == 0) {
        index++;
    }
    
    if (index == len1 + len2) return "0";

    int finalIndex = 0;
    while (index < len1 + len2) {
        finalResult[finalIndex++] = result[index++] + '0';
    }
    finalResult[finalIndex] = '\0';
    
    free(result);
    return finalResult;
}
