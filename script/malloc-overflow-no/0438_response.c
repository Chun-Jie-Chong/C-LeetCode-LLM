#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 26

int* findAnagrams(char* s, char* p, int* returnSize) {
    int s_len = strlen(s), p_len = strlen(p);
    int *result = (int*)malloc(s_len * sizeof(int));
    *returnSize = 0;
    
    if (s_len < p_len) return result;
    
    int p_count[MAX_CHAR] = {0}, s_count[MAX_CHAR] = {0};
    
    for (int i = 0; i < p_len; i++) {
        p_count[p[i] - 'a']++;
        s_count[s[i] - 'a']++;
    }
    
    if (memcmp(p_count, s_count, MAX_CHAR * sizeof(int)) == 0) {
        result[(*returnSize)++] = 0;
    }
    
    for (int i = p_len; i < s_len; i++) {
        s_count[s[i] - 'a']++;
        s_count[s[i - p_len] - 'a']--;
        
        if (memcmp(p_count, s_count, MAX_CHAR * sizeof(int)) == 0) {
            result[(*returnSize)++] = i - p_len + 1;
        }
    }
    
    result = realloc(result, *returnSize * sizeof(int));
    return result;
}
