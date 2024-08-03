#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

char* minWindow(char* s, char* t) {
    int sLen = strlen(s), tLen = strlen(t);
    if (sLen < tLen) return "";

    int tFreq[128] = {0}, winFreq[128] = {0};
    
    for (int i = 0; i < tLen; i++) {
        tFreq[t[i]]++;
    }

    int left = 0, right = 0, minLen = INT_MAX, minLeft = -1, required = tLen, formed = 0;
    
    while (right < sLen) {
        char c = s[right];
        winFreq[c]++;
        
        if (tFreq[c] > 0 && winFreq[c] <= tFreq[c]) {
            formed++;
        }
        
        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }
            
            winFreq[s[left]]--;
            if (tFreq[s[left]] > 0 && winFreq[s[left]] < tFreq[s[left]]) {
                formed--;
            }
            left++;
        }
        right++;
    }
    
    if (minLeft == -1) return "";
    
    char* result = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(result, s + minLeft, minLen);
    result[minLen] = '\0';
    
    return result;
}
