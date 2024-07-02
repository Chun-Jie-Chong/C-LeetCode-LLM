#include <string.h>

int longestPalindrome(char * s){
    int count[128] = {0};
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (count[i] % 2 == 0) {
            length += count[i];
        } else {
            if (count[i] > 1) {
                length += count[i] - 1;
            }
        }
    }
    if (length < strlen(s)) {
        length++;
    }
    return length;
}
