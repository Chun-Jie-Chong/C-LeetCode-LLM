#include <stddef.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a = headA;
    struct ListNode *b = headB;

    while (a != b) {
        a = (a != NULL) ? a->next : headB;
        b = (b != NULL) ? b->next : headA;
    }

    return a;
}
