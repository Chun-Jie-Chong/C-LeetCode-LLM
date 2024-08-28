#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

int* preorder(struct Node* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 10000; // initial capacity for result array
    int* result = (int*)malloc(sizeof(int) * capacity);
    int* stack = (int*)malloc(sizeof(int) * capacity);
    struct Node** nodeStack = (struct Node**)malloc(sizeof(struct Node*) * capacity);
    int top = 0;
    int size = 0;

    nodeStack[top++] = root;
    while (top > 0) {
        struct Node* node = nodeStack[--top];
        result[size++] = node->val;
        for (int i = node->numChildren - 1; i >= 0; --i) {
            nodeStack[top++] = node->children[i];
        }
    }

    *returnSize = size;
    free(stack);
    free(nodeStack);
    return result;
}
