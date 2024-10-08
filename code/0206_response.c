#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Iterative solution
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// // Recursive solution
// struct ListNode* reverseListRecursive(struct ListNode* head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }
//     struct ListNode* reversedList = reverseListRecursive(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return reversedList;
// }
