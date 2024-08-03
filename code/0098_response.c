#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isValidBSTUtil(struct TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTUtil(root->left, minVal, root->val) && isValidBSTUtil(root->right, root->val, maxVal);
}

bool isValidBST(struct TreeNode* root) {
    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}
