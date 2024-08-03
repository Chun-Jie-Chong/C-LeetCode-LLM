#include <stdbool.h>
#include <string.h>

bool isAlienSorted(char ** words, int wordsSize, char * order) {
    int orderMap[26];
    for (int i = 0; i < 26; ++i) {
        orderMap[order[i] - 'a'] = i;
    }

    for (int i = 1; i < wordsSize; ++i) {
        char * word1 = words[i-1];
        char * word2 = words[i];
        int len1 = strlen(word1);
        int len2 = strlen(word2);
        int minLen = len1 < len2 ? len1 : len2;
        bool validOrder = false;

        for (int j = 0; j < minLen; ++j) {
            if (word1[j] != word2[j]) {
                if (orderMap[word1[j] - 'a'] > orderMap[word2[j] - 'a']) {
                    return false;
                }
                validOrder = true;
                break;
            }
        }

        if (!validOrder && len1 > len2) {
            return false;
        }
    }

    return true;
}
