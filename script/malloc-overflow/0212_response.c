#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 30000
#define MAX_WORD_LEN 12

typedef struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
} TrieNode;

TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode *)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->isEndOfWord = false;
    return node;
}

void insertTrie(TrieNode *root, const char *word) {
    TrieNode *pCrawl = root;
    while (*word) {
        int index = *word - 'a';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = createTrieNode();
        }
        pCrawl = pCrawl->children[index];
        word++;
    }
    pCrawl->isEndOfWord = true;
}

bool isSafe(int x, int y, int m, int n) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

void dfs(char** board, int m, int n, int x, int y, bool** visited, TrieNode* node, char* buffer, int buffIndex, char** results, int* resultCount) {
    if (node->isEndOfWord) {
        buffer[buffIndex] = '\0';
        for (int i = 0; i < *resultCount; i++) {
            if (strcmp(results[i], buffer) == 0) {
                return;
            }
        }
        results[*resultCount] = (char*)malloc((buffIndex + 1) * sizeof(char));
        strcpy(results[(*resultCount)++], buffer);
        node->isEndOfWord = false;
    }

    if (!isSafe(x, y, m, n) || visited[x][y] || !node->children[board[x][y] - 'a']) {
        return;
    }

    visited[x][y] = true;
    buffer[buffIndex++] = board[x][y];

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        dfs(board, m, n, x + dx[i], y + dy[i], visited, node->children[board[x][y] - 'a'], buffer, buffIndex, results, resultCount);
    }

    visited[x][y] = false;
    buffIndex--;
}

char **findWords(char **board, int boardSize, int *boardColSize, char **words, int wordsSize, int *returnSize) {
    TrieNode *root = createTrieNode();
    for (int i = 0; i < wordsSize; i++) {
        insertTrie(root, words[i]);
    }

    int m = boardSize;
    int n = boardColSize[0];
    bool **visited = (bool **)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        visited[i] = (bool *)malloc(n * sizeof(bool));
        memset(visited[i], false, n * sizeof(bool));
    }

    char **results = (char **)malloc(MAX_WORDS * sizeof(char *));
    char buffer[MAX_WORD_LEN + 1];
    int resultCount = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dfs(board, m, n, i, j, visited, root, buffer, 0, results, &resultCount);
        }
    }

    *returnSize = resultCount;
    
    for (int i = 0; i < m; i++) {
        free(visited[i]);
    }
    free(visited);
    return results;
}
