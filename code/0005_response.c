#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) return "";
    
    int start = 0, maxLength = 1;
    int table[1000][1000] = {0};
    
    for (int i = 0; i < len; i++)
        table[i][i] = 1;
        
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }
    
    for (int k = 3; k <= len; k++) {
        for (int i = 0; i < len - k + 1; i++) {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && s[i] == s[j]) {
                table[i][j] = 1;
                
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    
    char* result = (char*)malloc(sizeof(char) * (maxLength + 1));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';
    return result;
}
