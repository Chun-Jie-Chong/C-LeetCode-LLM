#include <string.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int start = 0, maxLen = 1;
    for(int i = 1; i < len; i++) {
        // Even length palindromes
        int low = i - 1, high = i;
        while(low >= 0 && high < len && s[low] == s[high]) {
            if(high - low + 1 > maxLen) {
                start = low;
                maxLen = high - low + 1;
            }
            low--; high++;
        }
        // Odd length palindromes
        low = i - 1; high = i + 1;
        while(low >= 0 && high < len && s[low] == s[high]) {
            if(high - low + 1 > maxLen) {
                start = low;
                maxLen = high - low + 1;
            }
            low--; high++;
        }
    }
    s[start + maxLen] = '\0';
    return s + start;
}
