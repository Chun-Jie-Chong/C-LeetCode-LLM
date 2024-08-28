#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* rightSideView(struct TreeNode* root, int* returnSize) {
    struct TreeNode* queue[200];
    int front = 0, rear = 0, level = 0, *result = NULL;

    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    queue[rear++] = root;
    while (front < rear) {
        int count = rear - front;
        result = realloc(result, (level + 1) * sizeof(int));
        result[level++] = queue[front + count - 1]->val;
        while (count--) {
            struct TreeNode* node = queue[front++];
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }
    *returnSize = level;
    return result;
}
