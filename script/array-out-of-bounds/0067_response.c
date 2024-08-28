#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLength = lenA > lenB ? lenA : lenB;
    char *result = (char *)malloc(maxLength + 2);
    int carry = 0, i = 0;

    result[maxLength + 1] = '\0';

    for (int k = 0; k < maxLength + 1; k++) result[k] = '0';

    lenA--;
    lenB--;

    while (lenA >= 0 || lenB >= 0 || carry) {
        int sum = carry;
        if (lenA >= 0) sum += a[lenA--] - '0';
        if (lenB >= 0) sum += b[lenB--] - '0';
        carry = sum >> 1;
        result[maxLength--] = (sum & 1) + '0';
    }

    if (result[0] == '0') return result + 1;
    return result;
}
