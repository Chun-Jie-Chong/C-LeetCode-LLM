#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100000
#define VALUE_LEN 12

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create new tree nodes
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to serialize the tree
void serializeHelper(struct TreeNode* root, char* str) {
    if (root == NULL) {
        strcat(str, "null,");
    } else {
        char buf[VALUE_LEN];
        sprintf(buf, "%d,", root->val);
        strcat(str, buf);
        serializeHelper(root->left, str);
        serializeHelper(root->right, str);
    }
}

char* serialize(struct TreeNode* root) {
    char* str = (char*)malloc(MAX_STR_LEN * sizeof(char));
    strcpy(str, "");
    serializeHelper(root, str);
    return str;
}

// Helper function to deserialize the tree
struct TreeNode* deserializeHelper(char** data) {
    if (strncmp(*data, "null,", 5) == 0) {
        *data += 5;
        return NULL;
    }

    int val = strtol(*data, data, 10);
    (*data)++; // To skip the comma
    struct TreeNode* node = newNode(val);
    node->left = deserializeHelper(data);
    node->right = deserializeHelper(data);
    return node;
}

struct TreeNode* deserialize(char* data) {
    return deserializeHelper(&data);
}
