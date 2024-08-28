#include <limits.h>
#include <string.h>
#include <stdlib.h>

char* minWindow(char* s, char* t) {
    int s_len = strlen(s), t_len = strlen(t);
    if (s_len < t_len) return "";
    
    int t_freq[128] = {0}, window_freq[128] = {0};
    for (int i = 0; i < t_len; i++) t_freq[t[i]]++;
    
    int left = 0, min_left = 0, min_len = INT_MAX, count = 0;
    for (int right = 0; right < s_len; right++) {
        if (t_freq[s[right]] > 0) {
            window_freq[s[right]]++;
            if (window_freq[s[right]] <= t_freq[s[right]]) count++;
        }
        while (count == t_len) {
            if (right - left + 1 < min_len) {
                min_left = left;
                min_len = right - left + 1;
            }
            if (t_freq[s[left]] > 0) {
                window_freq[s[left]]--;
                if (window_freq[s[left]] < t_freq[s[left]]) count--;
            }
            left++;
        }
    }
    
    if (min_len == INT_MAX) return "";
    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    strncpy(result, s + min_left, min_len);
    result[min_len] = '\0';
    return result;
}
