#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Helper function to create a new node
struct Node* createNode(int val, int numNeighbors) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = numNeighbors;
    node->neighbors = (struct Node**)malloc(numNeighbors * sizeof(struct Node*));
    return node;
}

struct Node* dfs(struct Node* node, struct Node** visited) {
    if (node == NULL) return NULL;

    if (visited[node->val]) return visited[node->val];

    struct Node* cloneNode = createNode(node->val, node->numNeighbors);
    visited[node->val] = cloneNode;

    for (int i = 0; i < node->numNeighbors; i++) {
        cloneNode->neighbors[i] = dfs(node->neighbors[i], visited);
    }

    return cloneNode;
}

struct Node* cloneGraph(struct Node* s) {
    if (s == NULL) return NULL;

    struct Node* visited[101] = {0};

    return dfs(s, visited);
}
