#include <stdio.h>
#include <string.h>

int maxNumberOfBalloons(char *text) {
    int count[26] = {0};
    while (*text) count[*text++ - 'a']++;
    int min = count['b' - 'a'];
    min = (min < count['a' - 'a']) ? min : count['a' - 'a'];
    min = (min < count['l' - 'a'] / 2) ? min : count['l' - 'a'] / 2;
    min = (min < count['o' - 'a'] / 2) ? min : count['o' - 'a'] / 2;
    min = (min < count['n' - 'a']) ? min : count['n' - 'a'];
    return min;
}
