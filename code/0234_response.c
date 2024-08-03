#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    // Find the middle of the linked list
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    struct ListNode *prev = NULL, *curr = slow, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Check palindrome
    struct ListNode *firstHalf = head, *secondHalf = prev;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    return true;
}
