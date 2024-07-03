#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 200000
#define MAX_STRING_SIZE 101

typedef struct {
    int timestamp;
    char value[MAX_STRING_SIZE];
} Entry;

typedef struct {
    char key[MAX_STRING_SIZE];
    Entry entries[MAX_ENTRIES];
    int entry_count;
} TimeMapNode;

typedef struct {
    TimeMapNode nodes[MAX_ENTRIES];
    int node_count;
} TimeMap;

/** Initialize your data structure here. */
TimeMap* timeMapCreate() {
    TimeMap* obj = (TimeMap*) malloc(sizeof(TimeMap));
    obj->node_count = 0;
    return obj;
}

void timeMapSet(TimeMap* obj, char* key, char* value, int timestamp) {
    for (int i = 0; i < obj->node_count; i++) {
        if (strcmp(obj->nodes[i].key, key) == 0) {
            obj->nodes[i].entries[obj->nodes[i].entry_count].timestamp = timestamp;
            strcpy(obj->nodes[i].entries[obj->nodes[i].entry_count].value, value);
            obj->nodes[i].entry_count++;
            return;
        }
    }
    strcpy(obj->nodes[obj->node_count].key, key);
    obj->nodes[obj->node_count].entries[0].timestamp = timestamp;
    strcpy(obj->nodes[obj->node_count].entries[0].value, value);
    obj->nodes[obj->node_count].entry_count = 1;
    obj->node_count++;
}

char* timeMapGet(TimeMap* obj, char* key, int timestamp) {
    for (int i = 0; i < obj->node_count; i++) {
        if (strcmp(obj->nodes[i].key, key) == 0) {
            for (int j = obj->nodes[i].entry_count - 1; j >= 0; j--) {
                if (obj->nodes[i].entries[j].timestamp <= timestamp) {
                    return obj->nodes[i].entries[j].value;
                }
            }
        }
    }
    return "";
}

void timeMapFree(TimeMap* obj) {
    free(obj);
}
