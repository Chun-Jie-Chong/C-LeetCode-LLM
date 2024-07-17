#include <stdio.h>
#include <stdlib.h>

int* replaceElements(int* arr, int arrSize, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(arrSize * sizeof(int));
    
    // Initialize the greatest element to the right as -1 for the last element
    int greatest = -1;
    
    // Traverse the array from the end to the beginning
    for (int i = arrSize - 1; i >= 0; i--) {
        // Store the current element before replacing it
        int current = arr[i];
        // Replace the current element with the greatest element to its right
        result[i] = greatest;
        // Update the greatest element
        if (current > greatest) {
            greatest = current;
        }
    }
    
    // Set the return size
    *returnSize = arrSize;
    return result;
}
