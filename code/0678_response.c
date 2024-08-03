#include <stdbool.h>

bool checkValidString(char *s) {
    int low = 0, high = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            low++;
            high++;
        } else if (s[i] == ')') {
            if (low > 0) low--;
            high--;
        } else {
            if (low > 0) low--;
            high++;
        }
        if (high < 0) return false;
    }
    return low == 0;
}
