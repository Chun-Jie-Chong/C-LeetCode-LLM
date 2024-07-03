#include <stdlib.h>
#include <stddef.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;
    
    *returnSize = 2;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return NULL; // Because the problem guarantees one solution, this line is actually never reached
}
