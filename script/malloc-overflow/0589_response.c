#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void preorder(struct Node* root, int* returnSize, int* result) {
    if (root == NULL) return;
    result[(*returnSize)++] = root->val;
    for (int i = 0; i < root->numChildren; i++) {
        preorder(root->children[i], returnSize, result);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct Node* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(10000 * sizeof(int));
    if (!result) return NULL;
    preorder(root, returnSize, result);
    return result;
}
