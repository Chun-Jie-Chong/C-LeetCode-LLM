#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHILDREN 26

typedef struct TrieNode {
    struct TrieNode *children[MAX_CHILDREN];
    bool isEndOfWord;
    char *word;
} TrieNode;

typedef struct {
    TrieNode *root;
} Trie;

TrieNode* createTrieNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    node->word = NULL;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        node->children[i] = NULL;
    }
    return node;
}

Trie* createTrie() {
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    trie->root = createTrieNode();
    return trie;
}

void insertTrie(Trie *trie, const char *word) {
    TrieNode *current = trie->root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = true;
    current->word = strdup(word);
}

void dfs(char **board, int boardSize, int *boardColSize, int i, int j, TrieNode *current, bool **visited, char ***result, int *returnSize) {
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i] || visited[i][j] || !current->children[board[i][j] - 'a']) {
        return;
    }
    
    current = current->children[board[i][j] - 'a'];
    if (current->isEndOfWord) {
        (*result)[*returnSize] = strdup(current->word);
        (*returnSize)++;
        current->isEndOfWord = false;  // To avoid duplicates
    }

    visited[i][j] = true;

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++) {
        dfs(board, boardSize, boardColSize, i + di[k], j + dj[k], current, visited, result, returnSize);
    }

    visited[i][j] = false;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    Trie *trie = createTrie();
    for (int i = 0; i < wordsSize; i++) {
        insertTrie(trie, words[i]);
    }
    
    *returnSize = 0;
    int maxWords = wordsSize;
    char **result = (char **)malloc(maxWords * sizeof(char *));
    
    bool **visited = (bool **)malloc(boardSize * sizeof(bool *));
    for (int i = 0; i < boardSize; i++) {
        visited[i] = (bool *)malloc(boardColSize[i] * sizeof(bool));
        memset(visited[i], false, boardColSize[i] * sizeof(bool));
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            dfs(board, boardSize, boardColSize, i, j, trie->root, visited, &result, returnSize);
        }
    }

    for (int i = 0; i < boardSize; i++) {
        free(visited[i]);
    }
    free(visited);

    return result;
}
