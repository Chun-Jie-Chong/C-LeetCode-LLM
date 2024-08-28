#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m);
    }
    
    int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = halfLen - i;
        
        if (i < imax && nums1[i] < nums2[j - 1]) {
            imin = i + 1;
        } else if (i > imin && nums1[i - 1] > nums2[j]) {
            imax = i - 1;
        } else {
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                maxLeft = nums1[i - 1];
            } else {
                maxLeft = (nums1[i - 1] > nums2[j - 1]) ? nums1[i - 1] : nums2[j - 1];
            }
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }
            int minRight = 0;
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
            }
            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
}
