#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;

    // Step 1: Create a copy of each node, and place it after each original node
    struct Node* current = head;
    while (current) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = current->val;
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }

    // Step 2: Assign random pointers for the copy nodes
    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        } else {
            current->next->random = NULL;
        }
        current = current->next->next;
    }

    // Step 3: Separate the copied linked list from the original linked list
    current = head;
    struct Node* copiedHead = head->next;
    struct Node* copyCurrent;
    while (current) {
        copyCurrent = current->next;
        current->next = copyCurrent->next;
        if (copyCurrent->next) {
            copyCurrent->next = copyCurrent->next->next;
        }
        current = current->next;
    }
    
    return copiedHead;
}
