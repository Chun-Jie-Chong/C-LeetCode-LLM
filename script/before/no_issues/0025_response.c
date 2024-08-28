#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *groupPrev = dummy;
    
    while (1) {
        struct ListNode *kth = groupPrev;
        for (int i = 0; i < k && kth != NULL; i++) {
            kth = kth->next;
        }
        if (kth == NULL) break;
    
        struct ListNode *groupNext = kth->next;
        struct ListNode *prev = groupPrev->next;
        struct ListNode *cur = prev->next;

        for (int i = 1; i < k; i++) {
            prev->next = cur->next;
            cur->next = groupPrev->next;
            groupPrev->next = cur;
            cur = prev->next;
        }

        prev->next = groupNext;
        groupPrev = prev;
    }
    
    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}
