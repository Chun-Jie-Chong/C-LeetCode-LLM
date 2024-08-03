#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int count;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)b)->count - ((Element *)a)->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;

    // Create a hashmap (key-value pair)
    int hash[20001] = {0};
    Element elements[20001];

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i] + 10000]++;
    }

    int index = 0;
    for (int i = 0; i < 20001; i++) {
        if (hash[i] > 0) {
            elements[index].key = i - 10000;
            elements[index].count = hash[i];
            index++;
        }
    }

    qsort(elements, index, sizeof(Element), compare);

    int* result = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        result[i] = elements[i].key;
    }

    return result;
}

