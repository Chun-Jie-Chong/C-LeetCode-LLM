#include <stdio.h>
#include <stdlib.h>

void dfs(int* candidates, int candidatesSize, int target, int start, int* current, int index, int** results, int* columnSizes, int* returnSize) {
    if (target == 0) {
        results[*returnSize] = (int*)malloc(sizeof(int) * index);
        for (int i = 0; i < index; i++) {
            results[*returnSize][i] = current[i];
        }
        columnSizes[*returnSize] = index;
        (*returnSize)++;
        return;
    }
    
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
        if (candidates[i] > target) break;
        
        current[index] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], i + 1, current, index + 1, results, columnSizes, returnSize); 
    }
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* columnSizes, int* returnSize) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    
    int** results = (int**)malloc(sizeof(int*) * 150);
    columnSizes = (int*)malloc(sizeof(int) * 150);
    *returnSize = 0;
    
    int* current = (int*)malloc(sizeof(int) * candidatesSize);
    dfs(candidates, candidatesSize, target, 0, current, 0, results, columnSizes, returnSize);
    
    return results;
}
