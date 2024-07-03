#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char* str, int len) {
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int maxProduct(char* s) {
    int n = strlen(s);
    int maxProduct = 0;
    // Trying each possible subset of s
    for (int mask1 = 0; mask1 < (1 << n); mask1++) {
        char subseq1[n+1];
        int len1 = 0;
        for (int i = 0; i < n; i++) {
            if (mask1 & (1 << i)) {
                subseq1[len1++] = s[i];
            }
        }
        subseq1[len1] = '\0';
        if (!isPalindrome(subseq1, len1)) continue;
        
        for (int mask2 = 0; mask2 < (1 << n); mask2++) {
            if (mask1 & mask2) continue; // Ensure disjoint
            char subseq2[n+1];
            int len2 = 0;
            for (int i = 0; i < n; i++) {
                if (mask2 & (1 << i)) {
                    subseq2[len2++] = s[i];
                }
            }
            subseq2[len2] = '\0';
            if (isPalindrome(subseq2, len2)) {
                int product = len1 * len2;
                if (product > maxProduct) {
                    maxProduct = product;
                }
            }
        }
    }
    return maxProduct;
}
