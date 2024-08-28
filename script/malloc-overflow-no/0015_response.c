#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find unique triplets that sum to zero
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result = NULL;
    int capacity = 128;
    int size = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    // Allocate memory for result and returnColumnSizes
    result = (int **)malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(capacity * sizeof(int));
    
    for (int i = 0; i < numsSize - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates
        
        int left = i + 1, right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                if (size == capacity) {
                    capacity = capacity * 2;
                    result = (int **)realloc(result, capacity * sizeof(int *));
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                
                int *triplet = (int *)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                
                result[size] = triplet;
                (*returnColumnSizes)[size] = 3;
                ++size;
                
                while (left < right && nums[left] == nums[left + 1]) ++left;   // Skip duplicates
                while (left < right && nums[right] == nums[right - 1]) --right; // Skip duplicates
                ++left;
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    
    *returnSize = size;
    return result;
}

