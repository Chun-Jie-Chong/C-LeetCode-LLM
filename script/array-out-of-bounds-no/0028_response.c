#include <string.h>

int strStr(char * haystack, char * needle) {
    int h_len = strlen(haystack);
    int n_len = strlen(needle);

    if (n_len == 0) {
        return 0;
    }

    for (int i = 0; i <= h_len - n_len; i++) {
        int j;
        for (j = 0; j < n_len; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == n_len) {
            return i;
        }
    }
    return -1;
}
