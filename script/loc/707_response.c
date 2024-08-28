#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    ListNode* curr = obj->head;
    for (int i = 0; i < index; ++i) curr = curr->next;
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = obj->head;
    obj->head = new_node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = NULL;
    if (obj->size == 0) {
        obj->head = new_node;
    } else {
        ListNode* curr = obj->head;
        while (curr->next) curr = curr->next;
        curr->next = new_node;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
    } else {
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->val = val;
        ListNode* curr = obj->head;
        for (int i = 0; i < index - 1; ++i) curr = curr->next;
        new_node->next = curr->next;
        curr->next = new_node;
        obj->size++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    ListNode* curr = obj->head;
    if (index == 0) {
        obj->head = curr->next;
    } else {
        for (int i = 0; i < index - 1; ++i) curr = curr->next;
        ListNode* to_delete = curr->next;
        curr->next = to_delete->next;
        free(to_delete);
    }
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    ListNode* curr = obj->head;
    while (curr) {
        ListNode* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}