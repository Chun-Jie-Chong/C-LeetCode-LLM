#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 30500 // Max words space | given 3 * 10^4 + some buffer

typedef struct TrieNode {
    bool isEnd;
    struct TrieNode* children[26];
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = false;
    for (int i = 0; i < 26; ++i)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* node = root;
    for (int i = 0; word[i]; ++i) {
        int index = word[i] - 'a';
        if (!node->children[index])
            node->children[index] = createNode();
        node = node->children[index];
    }
    node->isEnd = true;
}

bool dfs(char** board, int i, int j, TrieNode* node, char* buffer, int pos, char** res, int* resIdx, int rowSize, int colSize) {
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize || board[i][j] == '#' || !node->children[board[i][j] - 'a'])
        return false;

    char temp = board[i][j];
    node = node->children[temp - 'a'];
    buffer[pos++] = temp;

    if (node->isEnd) {
        buffer[pos] = '\0';
        res[*resIdx] = strdup(buffer);
        (*resIdx)++;
        node->isEnd = false; // prevent duplicate result
    }

    board[i][j] = '#';
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int d = 0; d < 4; ++d)
        dfs(board, i + directions[d][0], j + directions[d][1], node, buffer, pos, res, resIdx, rowSize, colSize);

    board[i][j] = temp;
    return true;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    char** res = (char**)malloc(MAX_WORDS * sizeof(char*));
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; ++i)
        insert(root, words[i]);

    int resIdx = 0;
    char buffer[15];
    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardColSize[i]; ++j)
            dfs(board, i, j, root, buffer, 0, res, &resIdx, boardSize, boardColSize[i]);

    *returnSize = resIdx;
    return res;
}