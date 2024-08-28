#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *first = &dummy;
    struct ListNode *second = &dummy;
    
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    struct ListNode* nodeToDelete = second->next;
    second->next = second->next->next;
    free(nodeToDelete);
    
    return dummy.next;
}
