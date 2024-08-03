#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    while (current) {
        struct ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

void reorderList(struct ListNode* head) {
    if (!head || !head->next) return;
    
    struct ListNode* mid = findMiddle(head);
    struct ListNode* l1 = head;
    struct ListNode* l2 = mid->next;
    mid->next = NULL;
    
    l2 = reverseList(l2);
    
    while (l1 && l2) {
        struct ListNode* l1_next = l1->next;
        struct ListNode* l2_next = l2->next;
        
        l1->next = l2;
        if (l1_next) {
            l2->next = l1_next;
        }
        
        l1 = l1_next;
        l2 = l2_next;
    }
}
