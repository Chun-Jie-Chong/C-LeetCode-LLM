#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    int original = x, reversed = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (reversed > INT_MAX/10 || (reversed == INT_MAX / 10 && pop > 7)) return false;
        reversed = reversed * 10 + pop;
    }
    return original == reversed;
}
