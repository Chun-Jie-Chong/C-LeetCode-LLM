#include <limits.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int maxPathSumHelper(struct TreeNode* root, int* globalMax) {
    if (root == NULL) return 0;
    
    int leftMax = max(0, maxPathSumHelper(root->left, globalMax));
    int rightMax = max(0, maxPathSumHelper(root->right, globalMax));
    
    int localMax = root->val + leftMax + rightMax;
    *globalMax = max(*globalMax, localMax);
    
    return root->val + max(leftMax, rightMax);
}

int maxPathSum(struct TreeNode* root) {
    int globalMax = INT_MIN;
    maxPathSumHelper(root, &globalMax);
    return globalMax;
}
