#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int map[256] = {0};
    int len = 0, max_len = 0;
    int left = 0, right = 0;

    while (right < n) {
        if (map[s[right]] == 0) {
            map[s[right]] = 1;
            len = right - left + 1;
            max_len = max_len > len ? max_len : len;
            right++;
        } else {
            map[s[left]] = 0;
            left++;
        }
    }

    return max_len;
}
