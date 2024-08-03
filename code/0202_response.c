#include <stdbool.h>

int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        sum += digit * digit;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    while (fast != 1 && fast != slow) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}
