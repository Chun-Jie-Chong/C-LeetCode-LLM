#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int diameterHelper(struct TreeNode* root, int* diameter) {
    if (!root) return 0;
    int leftDepth = diameterHelper(root->left, diameter);
    int rightDepth = diameterHelper(root->right, diameter);
    *diameter = max(*diameter, leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    diameterHelper(root, &diameter);
    return diameter;
}
