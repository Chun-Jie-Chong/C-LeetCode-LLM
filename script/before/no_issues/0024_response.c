#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct ListNode* next = curr->next;
        curr->next = next->next;
        next->next = curr;
        prev->next = next;

        prev = curr;
        curr = curr->next;
    }

    head = dummy->next;
    free(dummy);
    
    return head;
}
