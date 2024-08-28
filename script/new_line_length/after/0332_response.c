#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 300
#define MAX_CITIES 128
#define A_CODE 'A'
#define NODES_PER_CITY 3

typedef struct Node {
    char destination[NODES_PER_CITY + 1];
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

AdjList adj[MAX_CITIES];
int num_tickets;
char** result;
int idx;

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

Node* createNode(char* destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->destination, destination);
    newNode->next = NULL;
    return newNode;
}

void addEdge(char* from, char* to) {
    int fromIdx = from[0] - A_CODE;
    Node* newNode = createNode(to);
    newNode->next = adj[fromIdx].head;
    adj[fromIdx].head = newNode;
}

void visit(char* airport) {
    int idx = airport[0] - A_CODE;
    Node* current = adj[idx].head;
    while (current) {
        Node* temp = current;
        adj[idx].head = current->next;
        visit(current->destination);
        free(temp);
        current = adj[idx].head;
    }
    result[idx--] = airport;
}

char** findItinerary(char*** tickets, int ticketsSize,
                     int* ticketsColSize, int* returnSize) {
    result = (char**)malloc((ticketsSize + 1) * sizeof(char*));
    for (int i = 0; i < MAX_CITIES; ++i)
        adj[i].head = NULL;

    for (int i = 0; i < ticketsSize; ++i)
        addEdge(tickets[i][0], tickets[i][1]);

    for (int i = 0; i < MAX_CITIES; ++i)
        if (adj[i].head) {
            // sort the adjacency list
            Node* sortedHead = NULL;
                Node* current = adj[i].head;
                while (current) {
                Node* temp = current;
                Node** pos = &sortedHead;
                while (*pos && compare(&temp->destination, &(*pos)->destination) >= 0)
                    pos = &(*pos)->next;
                current = current->next;
                temp->next = *pos;
                *pos = temp;
            }
            adj[i].head = sortedHead;
        }

    idx = ticketsSize;
    visit("JFK");

    *returnSize = ticketsSize + 1;
    return result;
}
