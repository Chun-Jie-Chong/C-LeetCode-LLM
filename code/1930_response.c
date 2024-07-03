#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countPalindromicSubsequence(char *s) {
    int count = 0;
    int n = strlen(s);
    bool found[26][26] = {{false}};

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 0; j < i; ++j) {
            if (s[j] == s[i + 1]) {
                found[s[j] - 'a'][s[i] - 'a'] = true;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (found[i][j]) {
                count++;
            }
        }
    }

    return count;
}
