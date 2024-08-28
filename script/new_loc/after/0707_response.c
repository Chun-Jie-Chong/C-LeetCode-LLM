#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    Node* curr = obj->head;
    while (curr && index--) {
        curr = curr->next;
    }
    return curr ? curr->val : -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if (!obj->head) {
        obj->head = newNode;
    } else {
        Node* curr = obj->head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node* curr = obj->head;
    while (curr && --index) {
        curr = curr->next;
    }
    if (curr) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index == 0 && obj->head) {
        Node* toDelete = obj->head;
        obj->head = obj->head->next;
        free(toDelete);
        return;
    }
    Node* curr = obj->head;
    while (curr && --index) {
        curr = curr->next;
    }
    if (curr && curr->next) {
        Node* toDelete = curr->next;
        curr->next = curr->next->next;
        free(toDelete);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* toDelete = curr;
        curr = curr->next;
        free(toDelete);
    }
    free(obj);
}
