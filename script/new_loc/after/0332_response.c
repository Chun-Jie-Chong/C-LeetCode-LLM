#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 300
#define AIRPORT_LEN 4
#define DEST_NUM 100

typedef struct {
    char **dest;
    int size;
} DestList;

DestList graph[MAX_TICKETS];
char *itinerary[MAX_TICKETS + 1];
int used[MAX_TICKETS], count;

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void dfs(int u) {
    while (graph[u].size) {
        char *v = graph[u].dest[--graph[u].size];
        int idx = -1;
        for (int i = 0; i < count; i++) {
            if (!used[i] && strcmp(itinerary[i], v) == 0 && strlen(itinerary[i]) == 3) {
                idx = i;
                break;
            }
        }
        used[idx] = 1;
        dfs(idx);
    }
    itinerary[count++] = graph[u].dest[graph[u].size];
}

char **findItinerary(char ***tickets, int ticketsSize, int *ticketsColSize, int *returnSize) {
    for (int i = 0; i < MAX_TICKETS; ++i) {
        graph[i].dest = malloc(DEST_NUM * sizeof(char *));
        graph[i].size = 0;
    }
    for (int i = 0; i < ticketsSize; ++i) {
        graph[strtol(tickets[i][0], NULL, 36)].dest[graph[strtol(tickets[i][0], NULL, 36)].size++] = tickets[i][1];
    }
    for (int i = 0; i < MAX_TICKETS; ++i) {
        qsort(graph[i].dest, graph[i].size, sizeof(char *), cmp);
    }
    count = 0;
    memset(used, 0, sizeof(used));
    dfs(strtol("JFK", NULL, 36));
    *returnSize = count;
    return itinerary;
}
