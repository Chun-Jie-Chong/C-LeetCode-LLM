#include <stdio.h>
#include <limits.h>

int maxProduct(int* nums, int numsSize) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < 0) {
            int temp = maxProd;
            maxProd = minProd;
            minProd = temp;
        }
        
        maxProd = (nums[i] > maxProd * nums[i]) ? nums[i] : maxProd * nums[i];
        minProd = (nums[i] < minProd * nums[i]) ? nums[i] : minProd * nums[i];
        
        if (maxProd > result) {
            result = maxProd;
        }
    }
    
    return result;
}
