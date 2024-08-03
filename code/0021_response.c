#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode *mergedHead = NULL, **pointer = &mergedHead;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            *pointer = list1;
            list1 = list1->next;
        } else {
            *pointer = list2;
            list2 = list2->next;
        }
        pointer = &((*pointer)->next);
    }

    if (list1 != NULL) {
        *pointer = list1;
    } else {
        *pointer = list2;
    }

    return mergedHead;
}
