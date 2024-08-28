#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int candidatesSize, int target, int** results, int* resultSize, int* columnSizes, int* currentCombination, int currentSize, int start) {
    if (target == 0) {
        results[*resultSize] = (int*)malloc(currentSize * sizeof(int));
        for (int i = 0; i < currentSize; i++) {
            results[*resultSize][i] = currentCombination[i];
        }
        columnSizes[*resultSize] = currentSize;
        (*resultSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }

        if (candidates[i] > target) {
            break;
        }

        currentCombination[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], results, resultSize, columnSizes, currentCombination, currentSize + 1, i + 1);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int** results = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    int resultSize = 0;
    int currentCombination[100];
    
    backtrack(candidates, candidatesSize, target, results, &resultSize, *returnColumnSizes, currentCombination, 0, 0);
    
    *returnSize = resultSize;
    return results;
}
