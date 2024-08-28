#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool dfs(char** board, int boardRowSize, int boardColSize, int i, int j, char* word, int index, bool** visited) {
    if (index == strlen(word)) return true;
    if (i < 0 || i >= boardRowSize || j < 0 || j >= boardColSize || visited[i][j] || board[i][j] != word[index]) return false;
    
    visited[i][j] = true;
    bool found = dfs(board, boardRowSize, boardColSize, i + 1, j, word, index + 1, visited) ||
                 dfs(board, boardRowSize, boardColSize, i - 1, j, word, index + 1, visited) ||
                 dfs(board, boardRowSize, boardColSize, i, j + 1, word, index + 1, visited) ||
                 dfs(board, boardRowSize, boardColSize, i, j - 1, word, index + 1, visited);
    visited[i][j] = false;
    
    return found;
}

bool exist(char** board, int boardRowSize, int* boardColSizes, char* word) {
    bool** visited = (bool**)malloc(boardRowSize * sizeof(bool*));
    for (int i = 0; i < boardRowSize; i++) {
        visited[i] = (bool*)malloc(boardColSizes[i] * sizeof(bool));
        for (int j = 0; j < boardColSizes[i]; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSizes[i]; j++) {
            if (dfs(board, boardRowSize, boardColSizes[i], i, j, word, 0, visited)) {
                for (int i = 0; i < boardRowSize; i++) free(visited[i]);
                free(visited);
                return true;
            }
        }
    }

    for (int i = 0; i < boardRowSize; i++) free(visited[i]);
    free(visited);

    return false;
}
