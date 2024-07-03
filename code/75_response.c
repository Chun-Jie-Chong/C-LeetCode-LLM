#include <stdio.h>

void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;
    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                // Swap nums[low] and nums[mid], increment low and mid
                {
                    int temp = nums[low];
                    nums[low] = nums[mid];
                    nums[mid] = temp;
                    low++;
                    mid++;
                }
                break;
            case 1:
                mid++;
                break;
            case 2:
                // Swap nums[mid] and nums[high], decrement high
                {
                    int temp = nums[mid];
                    nums[mid] = nums[high];
                    nums[high] = temp;
                    high--;
                }
                break;
        }
    }
}
