#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s, int mask, int len) {
    char subseq[len + 1];
    subseq[len] = '\0';
    int k = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (mask & (1 << i)) {
            subseq[k++] = s[i];
        }
    }
    for (int i = 0; i < k / 2; i++) {
        if (subseq[i] != subseq[k - i - 1]) return false;
    }
    return true;
}

int maxProduct(char *s){
    int n = strlen(s);
    int maxProduct = 0;
    for (int mask1 = 1; mask1 < (1 << n); mask1++) {
        for (int mask2 = 1; mask2 < (1 << n); mask2++) {
            if ((mask1 & mask2) == 0) {
                int len1 = __builtin_popcount(mask1);
                int len2 = __builtin_popcount(mask2);
                if (isPalindrome(s, mask1, len1) && isPalindrome(s, mask2, len2)) {
                    int product = len1 * len2;
                    if (product > maxProduct) {
                        maxProduct = product;
                    }
                }
            }
        }
    }
    return maxProduct;
}
