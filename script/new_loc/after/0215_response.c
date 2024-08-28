#include <stdio.h>
#include <stdlib.h>

int partition(int* nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (nums[j] >= pivot) {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    int temp = nums[i + 1];
    nums[i + 1] = nums[right];
    nums[right] = temp;
    return i + 1;
}

int quickSelect(int* nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }
    int partitionIndex = partition(nums, left, right);
    if (partitionIndex == k) {
        return nums[partitionIndex];
    } else if (partitionIndex > k) {
        return quickSelect(nums, left, partitionIndex - 1, k);
    } else {
        return quickSelect(nums, partitionIndex + 1, right, k);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, k - 1);
}
