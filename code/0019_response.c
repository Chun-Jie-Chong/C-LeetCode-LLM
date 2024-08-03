#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    if (fast == NULL) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode *temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    return head;
}
