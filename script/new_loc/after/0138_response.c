#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;
    
    struct Node* iter = head;
    struct Node* next;

    // First round: make copy of each node, and link them together side-by-side in a single list.
    while (iter) {
        next = iter->next;

        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = iter->val;
        copy->next = next;
        iter->next = copy;

        iter = next;
    }

    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter) {
        if (iter->random) {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    // Third round: restore the original list, and extract the copy list.
    iter = head;
    struct Node* pseudoHead = (struct Node*)malloc(sizeof(struct Node));
    struct Node* copy = pseudoHead;
    while (iter) {
        next = iter->next->next;

        // extract the copy
        copy->next = iter->next;

        // restore the original list
        iter->next = next;

        copy = copy->next;
        iter = next;
    }
    
    return pseudoHead->next;
}
