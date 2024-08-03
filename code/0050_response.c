#include <stdio.h>

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (n < 0) {
        x = 1 / x;
        if (n == -2147483648) { // handle edge case for minimum integer value
            n = 2147483647;
            x = x * x;
        } else {
            n = -n;
        }
    }
    double result = 1;
    while (n > 0) {
        if (n % 2 == 1) result *= x;
        x *= x;
        n /= 2;
    }
    return result;
}
