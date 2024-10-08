#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // Index for nums1
    int i = m - 1;
    // Index for nums2
    int j = n - 1;
    // Index for the merged array (starting from the end)
    int k = m + n - 1;
    
    // Merge nums1 and nums2 from the end to the beginning
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    
    // If there are remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

