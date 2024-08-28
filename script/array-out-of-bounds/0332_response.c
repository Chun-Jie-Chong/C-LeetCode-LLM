#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 300
#define AIRPORT_LEN 4

typedef struct Ticket {
    char from[AIRPORT_LEN];
    char to[AIRPORT_LEN];
} Ticket;

typedef struct Node {
    char airport[AIRPORT_LEN];
    struct Node *next;
} Node;

int compareTickets(const void *a, const void *b) {
    return strcmp(((Ticket *)a)->from, ((Ticket *)b)->from) ?: strcmp(((Ticket *)a)->to, ((Ticket *)b)->to);
}

void findItinerary(Ticket *tickets, int ticketsSize, Node **itinerary, char *current, int *used) {
    for (int i = 0; i < ticketsSize; i++) {
        if (!used[i] && strcmp(tickets[i].from, current) == 0) {
            used[i] = 1;
            findItinerary(tickets, ticketsSize, itinerary, tickets[i].to, used);
        }
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->airport, current);
    newNode->next = *itinerary;
    *itinerary = newNode;
}

char **reconstructItinerary(Ticket tickets[], int ticketsSize, int *returnSize) {
    qsort(tickets, ticketsSize, sizeof(Ticket), compareTickets);
    int used[ticketsSize];
    memset(used, 0, sizeof(used));
    Node *itinerary = NULL;
    findItinerary(tickets, ticketsSize, &itinerary, "JFK", used);

    char **result = (char **)malloc(sizeof(char *) * (ticketsSize + 1));
    *returnSize = ticketsSize + 1;
    for (int i = ticketsSize; i >= 0; i--) {
        result[i] = (char *)malloc(AIRPORT_LEN * sizeof(char));
        strcpy(result[i], itinerary->airport);
        Node *temp = itinerary;
        itinerary = itinerary->next;
        free(temp);
    }
    return result;
}
