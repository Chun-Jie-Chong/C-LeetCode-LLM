#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;

    struct Node *curr = head, *newNode;

    // 1. Creating new nodes and inserting them in between original nodes
    while (curr) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = curr->val;
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // 2. Setting random pointers for the new nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // 3. Separating the new nodes to form the new list
    struct Node *newHead = head->next;
    curr = head;
    while (curr) {
        newNode = curr->next;
        curr->next = newNode->next;
        if (newNode->next) {
            newNode->next = newNode->next->next;
        }
        curr = curr->next;
    }

    return newHead;
}
