#include <string.h>

int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int maxCount = 0, maxLength = 0, start = 0;
    int length = strlen(s);
    
    for (int end = 0; end < length; end++) {
        maxCount = maxCount > ++count[s[end] - 'A'] ? maxCount : count[s[end] - 'A'];
        
        while (end - start + 1 - maxCount > k) {
            count[s[start++] - 'A']--;
        }
        
        maxLength = maxLength > (end - start + 1) ? maxLength : (end - start + 1);
    }
    
    return maxLength;
}
