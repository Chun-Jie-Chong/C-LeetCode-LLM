#include <stdio.h>

void replaceElements(int* arr, int arrSize){
    int max = -1, temp;
    for (int i = arrSize - 1; i >= 0; --i) {
        temp = arr[i];
        arr[i] = max;
        if (temp > max) {
            max = temp;
        }
    }
}
