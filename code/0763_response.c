#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* partitionLabels(char* s, int* returnSize) {
    int last[26];
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        last[s[i] - 'a'] = i;
    }

    int* result = (int*)malloc(length * sizeof(int));
    int size = 0;
    int j = 0, anchor = 0;

    for (int i = 0; i < length; i++) {
        j = (j > last[s[i] - 'a']) ? j : last[s[i] - 'a'];
        if (i == j) {
            result[size++] = i - anchor + 1;
            anchor = i + 1;
        }
    }

    *returnSize = size;
    return result;
}
