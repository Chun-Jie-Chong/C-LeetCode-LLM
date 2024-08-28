#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Utility function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Encodes a tree to a single string.
char* serialize(struct TreeNode* root) {
    if (!root) return strdup("[]");

    char* result = malloc(5000 * sizeof(char));
    strcpy(result, "[");

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = queue[front++];
        if (node) {
            char buffer[50];
            sprintf(buffer, "%d", node->val);
            strcat(result, buffer);
            strcat(result, ",");

            queue[rear++] = node->left;
            queue[rear++] = node->right;
        } else {
            strcat(result, "null,");
        }
    }

    // Remove the last comma
    if (result[strlen(result)-1] == ',') {
        result[strlen(result)-1] = '\0';
    }

    strcat(result, "]");
    return result;
}

// Utility function to split a string by delimiter
char** splitString(const char* str, const char* delim, int* length) {
    int count = 0;
    char* token;
    char* strCopy = strdup(str);
    char** result = malloc(5000 * sizeof(char*));

    token = strtok(strCopy, delim);
    while (token != NULL) {
        result[count++] = strdup(token);
        token = strtok(NULL, delim);
    }

    *length = count;
    free(strCopy);
    return result;
}

// Decodes your encoded data to tree.
struct TreeNode* deserialize(char* data) {
    if (strcmp(data, "[]") == 0) return NULL;

    int length;
    char** tokens = splitString(data + 1, ",]", &length);

    struct TreeNode* root = newNode(atoi(tokens[0]));
    struct TreeNode* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    for (int i = 1; i < length; i++) {
        struct TreeNode* parent = queue[front++];
        if (strcmp(tokens[i], "null") != 0) {
            struct TreeNode* leftChild = newNode(atoi(tokens[i]));
            parent->left = leftChild;
            queue[rear++] = leftChild;
        }

        if (++i < length && strcmp(tokens[i], "null") != 0) {
            struct TreeNode* rightChild = newNode(atoi(tokens[i]));
            parent->right = rightChild;
            queue[rear++] = rightChild;
        }
    }

    for (int i = 0; i < length; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return root;
}
