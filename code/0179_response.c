#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char ab[20], ba[20];
    sprintf(ab, "%s%s", *(const char**)a, *(const char**)b);
    sprintf(ba, "%s%s", *(const char**)b, *(const char**)a);
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    if (numsSize == 0) return "";

    char** strNums = (char**)malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; ++i) {
        strNums[i] = (char*)malloc(12 * sizeof(char));
        sprintf(strNums[i], "%d", nums[i]);
    }

    qsort(strNums, numsSize, sizeof(char*), compare);

    if (strcmp(strNums[0], "0") == 0) return "0";

    size_t length = 1;
    for (int i = 0; i < numsSize; ++i) {
        length += strlen(strNums[i]);
    }

    char* result = (char*)malloc(length * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numsSize; ++i) {
        strcat(result, strNums[i]);
        free(strNums[i]);
    }
    free(strNums);

    return result;
}
