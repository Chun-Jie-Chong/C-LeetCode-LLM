#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* copyNode(struct Node* node, struct Node** visited) {
    if (!node) return NULL;
    if (visited[node->val]) return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(clone->numNeighbors * sizeof(struct Node*));
    visited[node->val] = clone;

    for (int i = 0; i < clone->numNeighbors; i++)
        clone->neighbors[i] = copyNode(node->neighbors[i], visited);
    
    return clone;
}

struct Node* cloneGraph(struct Node* node) {
    struct Node* visited[101] = {0};
    return copyNode(node, visited);
}
