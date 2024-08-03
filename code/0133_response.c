#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definition for a Node.
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* copyNode(struct Node* node, struct Node** visited) {
    if (!node) {
        return NULL;
    }

    if (visited[node->val]) {
        return visited[node->val];
    }

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));
    visited[node->val] = clone;
    
    for (int i = 0; i < node->numNeighbors; ++i) {
        clone->neighbors[i] = copyNode(node->neighbors[i], visited);
    }
    
    return clone;
}

struct Node* cloneGraph(struct Node* sNode) {
    if (!sNode) {
        return NULL;
    }

    struct Node* visited[101] = { 0 };
    return copyNode(sNode, visited);
}
