#include <stdio.h>
#include <stdlib.h>

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int carry = k;
    for (int i = numSize - 1; i >= 0; --i) {
        carry += num[i];
        num[i] = carry % 10;
        carry /= 10;
    }

    while (carry > 0) {
        numSize++;
        num = realloc(num, numSize * sizeof(int));
        for (int i = numSize - 1; i > 0; --i)
            num[i] = num[i - 1];
        num[0] = carry % 10;
        carry /= 10;
    }

    *returnSize = numSize;
    return num;
}
