#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char order1[22], order2[22];
    sprintf(order1, "%d%d", *(int*)a, *(int*)b);
    sprintf(order2, "%d%d", *(int*)b, *(int*)a);
    return strcmp(order2, order1);
}

char* largestNumber(int* nums, int numsSize) {
    char** numStrs = (char**)malloc(numsSize * sizeof(char*));
    int totalLen = 0;

    for (int i = 0; i < numsSize; i++) {
        numStrs[i] = (char*)malloc(12 * sizeof(char));
        sprintf(numStrs[i], "%d", nums[i]);
        totalLen += strlen(numStrs[i]);
    }

    qsort(nums, numsSize, sizeof(int), compare);

    char* result = (char*)malloc((totalLen + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numsSize; i++) {
        strcat(result, numStrs[i]);
        free(numStrs[i]);
    }

    free(numStrs);

    if (result[0] == '0') {
        result[1] = '\0';
    }
    return result;
}
