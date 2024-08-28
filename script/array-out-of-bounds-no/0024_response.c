#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;

    while (head != NULL && head->next != NULL) {
        struct ListNode* first = head;
        struct ListNode* second = head->next;

        first->next = second->next;
        second->next = first;
        
        if (prev != NULL) {
            prev->next = second;
        }
        
        prev = first;
        head = first->next;
    }

    return newHead;
}
