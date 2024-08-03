#include <stdio.h>

int getSum(int a, int b) {
    while (b != 0) {
        unsigned int carry = (unsigned int)(a & b);
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
