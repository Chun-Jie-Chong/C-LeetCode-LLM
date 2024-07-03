#include <stdio.h>

int findRoot(int* parent, int i) {
    while (parent[i] != i) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    static int result[2];
    int parent[edgesSize + 1];

    for (int i = 0; i <= edgesSize; ++i)
        parent[i] = i;

    for (int i = 0; i < edgesSize; ++i) {
        int x = findRoot(parent, edges[i][0]);
        int y = findRoot(parent, edges[i][1]);
        
        if (x == y) {
            result[0] = edges[i][0];
            result[1] = edges[i][1];
        } else {
            parent[x] = y;
        }
    }

    *returnSize = 2;
    return result;
}
