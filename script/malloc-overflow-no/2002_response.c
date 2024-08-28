#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s, int mask, int len) {
    char temp[13];
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (mask & (1 << i)) {
            temp[k++] = s[i];
        }
    }
    temp[k] = '\0';
    for (int i = 0, j = k - 1; i < j; i++, j--) {
        if (temp[i] != temp[j]) {
            return false;
        }
    }
    return true;
}

int maxProduct(char *s) {
    int n = strlen(s);
    int maxProd = 0;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j < (1 << n); j++) {
            if (i & j) continue;
            if (isPalindrome(s, i, n) && isPalindrome(s, j, n)) {
                int length1 = __builtin_popcount(i);
                int length2 = __builtin_popcount(j);
                maxProd = (length1 * length2 > maxProd) ? length1 * length2 : maxProd;
            }
        }
    }
    return maxProd;
}
