#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    if (!left) return right;
    if (!right) return left;
    
    if (left->val < right->val) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = NULL; // split the list into two halves
    return slow;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    
    struct ListNode* middle = findMiddle(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(middle);
    
    return merge(left, right);
}
