#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
    int last[26] = {0};
    int len = 0;
    while(s[len] != '\0') {
        last[s[len] - 'a'] = len;
        len++;
    }
    
    int *result = (int*)malloc(len * sizeof(int));
    *returnSize = 0;
    int start = 0, end = 0;
    
    for(int i = 0; i < len; i++) {
        end = end > last[s[i] - 'a'] ? end : last[s[i] - 'a'];
        if(i == end) {
            result[(*returnSize)++] = end - start + 1;
            start = end + 1;
        }
    }
    
    return result;
}

// Example usage:
int main() {
    char s[] = "ababcbacadefegdehijhklij";
    int returnSize;
    int* parts = partitionLabels(s, &returnSize);
    
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", parts[i]);
    }
    printf("\n");
    
    free(parts);
    return 0;
}
