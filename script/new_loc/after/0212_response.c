#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 12
#define MAXW 30000
#define MAXL 10

typedef struct TrieNode {
    struct TrieNode* children[26];
    char* word;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)calloc(1, sizeof(TrieNode));
    return node;
}

void insertWord(TrieNode* root, char* word) {
    TrieNode* node = root;
    while (*word) {
        if (!node->children[*word - 'a']) node->children[*word - 'a'] = createNode();
        node = node->children[*word - 'a'];
        word++;
    }
    node->word = word;
}

void dfs(char** board, int m, int n, int x, int y, TrieNode* node, char** result, int* resultSize) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '#') return;
    char c = board[x][y];
    TrieNode* nextNode = node->children[c - 'a'];
    if (!nextNode) return;
    if (nextNode->word) {
        result[(*resultSize)++] = nextNode->word;
        nextNode->word = NULL;  
    }
    board[x][y] = '#';
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) dfs(board, m, n, x + dx[i], y + dy[i], nextNode, result, resultSize);
    board[x][y] = c;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) insertWord(root, words[i]);

    char** result = (char**)malloc(MAXW * sizeof(char*));
    *returnSize = 0;
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardColSize[i]; j++)
            dfs(board, boardSize, boardColSize[i], i, j, root, result, returnSize);

    return result;
}
