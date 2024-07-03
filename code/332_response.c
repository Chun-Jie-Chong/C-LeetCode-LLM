#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **items;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (char **)malloc(capacity * sizeof(char *));
    return stack;
}

void push(Stack *stack, char *item) {
    stack->items[++stack->top] = item;
}

char *pop(Stack *stack) {
    return stack->items[stack->top--];
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void dfs(char **itinerary, int *itinerarySize, Stack *stack, char ***adj, int *adjSize, int *usedTickets, int ticketsSize) {
    while (adjSize[stack->top + 1] > 0) {
        char *next = adj[stack->top + 1][--adjSize[stack->top + 1]];
        push(stack, next);
        dfs(itinerary, itinerarySize, stack, adj, adjSize, usedTickets, ticketsSize);
    }
    itinerary[(*itinerarySize)++] = pop(stack);
}

char **findItinerary(char ***tickets, int ticketsSize, int *ticketsColSize, int *returnSize) {
    char **itinerary = (char **)malloc((ticketsSize + 1) * sizeof(char *));
    int itinerarySize = 0;
    
    Stack *stack = createStack(ticketsSize + 1);
    
    qsort(tickets, ticketsSize, sizeof(char **), (int (*)(const void *, const void *))compare);
    
    char ***adj = (char ***)malloc((ticketsSize * 2) * sizeof(char **));
    int *adjSize = (int *)calloc(ticketsSize * 2, sizeof(int));
    
    for (int i = 0; i < ticketsSize * 2; i++) {
        adj[i] = (char **)malloc(ticketsSize * sizeof(char *));
    }

    for (int i = 0; i < ticketsSize; i++) {
        int fromIndex = tickets[i][0][0] * 100 + tickets[i][0][1] * 10 + tickets[i][0][2];
        adj[fromIndex][adjSize[fromIndex]++] = tickets[i][1];
    }

    push(stack, "JFK");
    dfs(itinerary, &itinerarySize, stack, adj, adjSize, NULL, ticketsSize);
    
    *returnSize = itinerarySize;
    for (int l = 0, r = itinerarySize - 1; l < r; l++, r--) {
        char *temp = itinerary[l];
        itinerary[l] = itinerary[r];
        itinerary[r] = temp;
    }
    
    for (int i = 0; i < ticketsSize * 2; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    free(stack->items);
    free(stack);
    
    return itinerary;
}
