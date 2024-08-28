#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int visit(char *cur, char ***tickets, int ticketsSize, int *visited, char **result, int idx) {
    result[idx] = cur;
    if (idx == ticketsSize) return 1;

    for (int i = 0; i < ticketsSize; i++) {
        if (!visited[i] && strcmp(tickets[i][0], cur) == 0) {
            visited[i] = 1;
            if (visit(tickets[i][1], tickets, ticketsSize, visited, result, idx + 1)) return 1;
            visited[i] = 0;
        }
    }
    return 0;
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    qsort(tickets, ticketsSize, sizeof(char**), cmp);
    int *visited = (int *)calloc(ticketsSize, sizeof(int));
    char **result = (char **)malloc((ticketsSize + 1) * sizeof(char *));
    visit("JFK", tickets, ticketsSize, visited, result, 0);
    *returnSize = ticketsSize + 1;
    free(visited);
    return result;
}