#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

char* serialize(struct TreeNode* root) {
    char *res = malloc(MAX_SIZE * sizeof(char));
    if (!res) return NULL;
    char buffer[20];
    memset(res, 0, MAX_SIZE);
    struct TreeNode* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        if (node) {
            sprintf(buffer, "%d,", node->val);
            strcat(res, buffer);
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        } else {
            strcat(res, "null,");
        }
    }
    return res;
}

struct TreeNode* deserialize(char* data) {
    if (!data || strcmp(data, "null,") == 0) return NULL;
    char *token = strtok(data, ",");
    if (!token) return NULL;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    if (!root) return NULL;
    root->val = atoi(token);
    root->left = root->right = NULL;
    struct TreeNode* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        if ((token = strtok(NULL, ","))) {
            if (strcmp(token, "null") != 0) {
                struct TreeNode *left = malloc(sizeof(struct TreeNode));
                left->val = atoi(token);
                left->left = left->right = NULL;
                node->left = left;
                queue[rear++] = left;
            }
        }
        if ((token = strtok(NULL, ","))) {
            if (strcmp(token, "null") != 0) {
                struct TreeNode *right = malloc(sizeof(struct TreeNode));
                right->val = atoi(token);
                right->left = right->right = NULL;
                node->right = right;
                queue[rear++] = right;
            }
        }
    }
    return root;
}
