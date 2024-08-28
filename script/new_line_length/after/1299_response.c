#include <stdlib.h>

int* replaceElements(int* arr, int arrSize, int* returnSize) {
    if (arrSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = arrSize;
    int* result = (int*)malloc(sizeof(int) * arrSize);
    
    int maxRight = -1;
    for (int i = arrSize - 1; i >= 0; i--) {
        result[i] = maxRight;
        if (arr[i] > maxRight) {
            maxRight = arr[i];
        }
    }

    return result;
}
