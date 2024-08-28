#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *value;
    int timestamp;
} Entry;

typedef struct {
    char *key;
    Entry *entries;
    int size, capacity;
} KeyEntry;

typedef struct {
    KeyEntry *data;
    int size, capacity;
} TimeMap;

TimeMap* timeMapCreate() {
    TimeMap* obj = (TimeMap*)malloc(sizeof(TimeMap));
    obj->size = 0;
    obj->capacity = 100;
    obj->data = (KeyEntry*)malloc(obj->capacity * sizeof(KeyEntry));
    return obj;
}

void set(TimeMap* obj, char* key, char* value, int timestamp) {
    int i;
    for (i = 0; i < obj->size; i++) {
        if (strcmp(obj->data[i].key, key) == 0) break;
    }
    if (i == obj->size) {
        if (obj->size == obj->capacity) {
            obj->capacity *= 2;
            obj->data = (KeyEntry*)realloc(obj->data, obj->capacity * sizeof(KeyEntry));
        }
        obj->data[i].key = strdup(key);
        obj->data[i].size = 0;
        obj->data[i].capacity = 100;
        obj->data[i].entries = (Entry*)malloc(obj->data[i].capacity * sizeof(Entry));
        obj->size++;
    }
    if (obj->data[i].size == obj->data[i].capacity) {
        obj->data[i].capacity *= 2;
        obj->data[i].entries = (Entry*)realloc(obj->data[i].entries, obj->data[i].capacity * sizeof(Entry));
    }
    obj->data[i].entries[obj->data[i].size].value = strdup(value);
    obj->data[i].entries[obj->data[i].size].timestamp = timestamp;
    obj->data[i].size++;
}

char* get(TimeMap* obj, char* key, int timestamp) {
    for (int i = 0; i < obj->size; i++) {
        if (strcmp(obj->data[i].key, key) == 0) {
            int l = 0, r = obj->data[i].size - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (obj->data[i].entries[m].timestamp <= timestamp) l = m + 1;
                else r = m - 1;
            }
            if (r >= 0) return obj->data[i].entries[r].value;
        }
    }
    return "";
}

void timeMapFree(TimeMap* obj) {
    for (int i = 0; i < obj->size; i++) {
        free(obj->data[i].key);
        for (int j = 0; j < obj->data[i].size; j++) {
            free(obj->data[i].entries[j].value);
        }
        free(obj->data[i].entries);
    }
    free(obj->data);
    free(obj);
}
