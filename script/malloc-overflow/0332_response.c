#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 300
#define AIRPORT_CODE_LENGTH 4

typedef struct {
    char from[AIRPORT_CODE_LENGTH];
    char to[AIRPORT_CODE_LENGTH];
} Ticket;

typedef struct Node {
    char to[AIRPORT_CODE_LENGTH];
    struct Node* next;
} Node;

Node* nodes[MAX_TICKETS];
int ticket_count = 0;

int cmp(const void* a, const void* b) {
    return strcmp(((Node*)a)->to, ((Node*)b)->to);
}

void add_ticket(const char* from, const char* to) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->to, to);
    new_node->next = nodes[ticket_count];
    nodes[ticket_count++] = new_node;
}

void dfs(const char* airport, char** result, int* idx) {
    for (int i = 0; i < ticket_count; ++i) {
        for (Node* current = nodes[i]; current != NULL;) {
            if (strcmp(current->from, airport) == 0) {
                Node* next_node = current->next;
                dfs(current->to, result, idx);
                current->next = NULL;
                current = next_node;
            } else {
                break;
            }
        }
    }
    strcpy(result[(*idx)--], airport);
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    memset(nodes, 0, sizeof(nodes));
    ticket_count = 0;

    for (int i = 0; i < ticketsSize; ++i) {
        add_ticket(tickets[i][0], tickets[i][1]);
    }

    for (int i = 0; i < ticket_count; ++i) {
        int n = 0;
        Node* current = nodes[i];
        while (current) {
            n++;
            current = current->next;
        }

        Node* array = (Node*)malloc(n * sizeof(Node));
        current = nodes[i];
        for (int j = 0; j < n; ++j) {
            strcpy(array[j].to, current->to);
            current = current->next;
        }

        qsort(array, n, sizeof(Node), cmp);

        for (int j = n - 1; j >= 0; --j) {
            array[j].next = (j == n - 1) ? NULL : &array[j + 1];
        }

        nodes[i] = array;
    }

    char** result = (char**)malloc((ticketsSize + 1) * sizeof(char*));
    for (int i = 0; i <= ticketsSize; ++i) {
        result[i] = (char*)malloc(AIRPORT_CODE_LENGTH);
    }

    int idx = ticketsSize;
    dfs("JFK", result, &idx);
    *returnSize = ticketsSize + 1;

    return result;
}
