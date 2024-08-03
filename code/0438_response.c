#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 26

int* findAnagrams(char* s, char* p, int* returnSize) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    *returnSize = 0;

    if (sLen < pLen) {
        return NULL;
    }

    int* result = (int*)malloc(sLen * sizeof(int));
    int countP[MAX_CHAR] = {0};
    int countS[MAX_CHAR] = {0};

    // Initialize the count arrays
    for (int i = 0; i < pLen; i++) {
        countP[p[i] - 'a']++;
        countS[s[i] - 'a']++;
    }

    for (int i = 0; i <= sLen - pLen; i++) {
        if (memcmp(countP, countS, sizeof(countP)) == 0) {
            result[(*returnSize)++] = i;
        }

        // Slide the window
        if (i + pLen < sLen) {
            countS[s[i + pLen] - 'a']++;
            countS[s[i] - 'a']--;
        }
    }

    return result;
}
