#include <string.h>
#include <math.h>

int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int max_count = 0, max_length = 0;
    int start = 0, end = 0;
    int len = strlen(s);

    for (end = 0; end < len; end++) {
        max_count = fmax(max_count, ++count[s[end] - 'A']);
        while (end - start + 1 - max_count > k) {
            count[s[start] - 'A']--;
            start++;
        }
        max_length = fmax(max_length, end - start + 1);
    }
    
    return max_length;
}
