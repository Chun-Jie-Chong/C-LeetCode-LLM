#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int *candidates, int candidatesSize, int target, int start, 
               int *currentCombo, int currLen, int **results, int *returnSize, 
               int **columnSizes) {
    if (target == 0) {
        results[*returnSize] = malloc(currLen * sizeof(int));
        for (int i = 0; i < currLen; i++) {
            results[*returnSize][i] = currentCombo[i];
        }
        columnSizes[0][*returnSize] = currLen;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        currentCombo[currLen] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], 
                  i + 1, currentCombo, currLen + 1, results, returnSize, 
                  columnSizes);
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target, 
                      int *returnSize, int **returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), (int (*)(const void *, 
              const void *))strcmp);
    int **results = malloc(1000 * sizeof(int *));
    int *currentCombo = malloc(candidatesSize * sizeof(int));
    *returnSize = 0;
    *returnColumnSizes = malloc(1000 * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, currentCombo, 0, 
              results, returnSize, returnColumnSizes);
    free(currentCombo);
    return results;
}
