#include <string.h>
#include <limits.h>

int lengthOfLongestSubstring(char * s) {
    int n = strlen(s);
    int maxLen = 0;
    int lastIndex[128]; // Assuming ASCII 128 characters

    for (int i = 0; i < 128; i++) {
        lastIndex[i] = -1;
    }

    int start = 0;
    for (int end = 0; end < n; end++) {
        if (lastIndex[s[end]] >= start) {
            start = lastIndex[s[end]] + 1;
        }
        lastIndex[s[end]] = end;
        maxLen = (maxLen > (end - start + 1)) ? maxLen : (end - start + 1);
    }

    return maxLen;
}
