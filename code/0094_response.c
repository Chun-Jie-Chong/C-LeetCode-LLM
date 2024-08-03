#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* stack[100];
    int* result = (int*)malloc(100 * sizeof(int));
    int top = -1;
    int index = 0;
    struct TreeNode* current = root;
    
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        result[index++] = current->val;
        current = current->right;
    }
    
    *returnSize = index;
    return result;
}
