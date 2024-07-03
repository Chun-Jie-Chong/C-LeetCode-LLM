#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *linkedList = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    linkedList->head = NULL;
    linkedList->size = 0;
    return linkedList;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1;
    }
    ListNode *current = obj->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        ListNode *current = obj->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) {
        return;
    }
    if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
    } else if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
    } else {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = val;
        ListNode *current = obj->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        obj->size++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return;
    }
    ListNode *current = obj->head;
    if (index == 0) {
        obj->head = current->next;
        free(current);
    } else {
        ListNode *prev = NULL;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
    }
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    ListNode *current = obj->head;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}
