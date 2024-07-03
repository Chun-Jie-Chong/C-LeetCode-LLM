#include <string.h>

int minSwaps(char* s) {
    int balance = 0, maxUnbalance = 0;
    int n = strlen(s);
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') {
            balance++;
        } else {
            balance--;
        }
        
        if (balance < 0) {
            maxUnbalance = maxUnbalance > (-balance) ? maxUnbalance : (-balance);
        }
    }
    
    return (maxUnbalance + 1) / 2;
}
