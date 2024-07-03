#include <stdio.h>
#include <string.h>

int maxNumberOfBalloons(char * text) {
    int count[26] = {0};
    while (*text) {
        count[*text - 'a']++;
        text++;
    }
    int minCount = count['b' - 'a'];
    minCount = count['a' - 'a'] < minCount ? count['a' - 'a'] : minCount;
    minCount = count['l' - 'a'] / 2 < minCount ? count['l' - 'a'] / 2 : minCount;
    minCount = count['o' - 'a'] / 2 < minCount ? count['o' - 'a'] / 2 : minCount;
    minCount = count['n' - 'a'] < minCount ? count['n' - 'a'] : minCount;
    return minCount;
}
