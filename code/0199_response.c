#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int* result = (int*)malloc(100 * sizeof(int));
    int front = 0, rear = 0, level = 0, count;
    
    queue[rear++] = root;

    while (front < rear) {
        count = rear - front;
        for (int i = 0; i < count; i++) {
            struct TreeNode* node = queue[front++];
            if (i == count - 1) {
                result[level++] = node->val;
            }
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
    }
    
    free(queue);
    *returnSize = level;
    return result;
}
