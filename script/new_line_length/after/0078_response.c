#include <stdio.h>
#include <stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, 
              int** returnColumnSizes) {
    int total = 1 << numsSize;
    *returnSize = total;
    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    
    for (int i = 0; i < total; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) count++;
        }
        result[i] = (int*)malloc(count * sizeof(int));
        (*returnColumnSizes)[i] = count;
        
        int index = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) result[i][index++] = nums[j];
        }
    }
    return result;
}
