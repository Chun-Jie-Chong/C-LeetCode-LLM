#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

static struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* current = head;
    struct ListNode* previous = NULL;
    struct ListNode* next = NULL;
    struct ListNode* check = head;
    int count = 0;
    int canProceed = 0;

    // Check if there are at least k nodes left in the linked list
    while (check != NULL && count < k) {
        check = check->next;
        count++;
    }
    
    if (count == k) {
        count = 0;
        while (current != NULL && count < k) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            count++;
        }
        
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }
        
        return previous;
    } else {
        return head;
    }
}
