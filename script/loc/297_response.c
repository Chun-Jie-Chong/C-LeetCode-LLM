#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Encodes a tree to a single string.
void serializeHelper(struct TreeNode* root, char* str) {
    if (root == NULL) {
        strcat(str, "null,");
        return;
    }
    char buffer[12];
    snprintf(buffer, sizeof(buffer), "%d,", root->val);
    strcat(str, buffer);
    serializeHelper(root->left, str);
    serializeHelper(root->right, str);
}

char* serialize(struct TreeNode* root) {
    char* str = (char*)malloc(10000 * sizeof(char));
    str[0] = '\0';
    serializeHelper(root, str);
    return str;
}

// Decodes your encoded data to tree.
struct TreeNode* deserializeHelper(char** data) {
    if (strncmp(*data, "null,", 5) == 0) {
        *data += 5;
        return NULL;
    }
    int val = atoi(*data);
    while (**data != ',') (*data)++;
    (*data)++;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = deserializeHelper(data);
    node->right = deserializeHelper(data);
    return node;
}

struct TreeNode* deserialize(char* data) {
    return deserializeHelper(&data);
}