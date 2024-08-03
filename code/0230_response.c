#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode* root, int* k, int* result) {
    if (root == NULL) return;
    inorder(root->left, k, result);
    (*k)--;
    if (*k == 0) {
        *result = root->val;
        return;
    }
    inorder(root->right, k, result);
}

int kthSmallest(struct TreeNode* root, int k) {
    int result = -1;
    inorder(root, &k, &result);
    return result;
}
