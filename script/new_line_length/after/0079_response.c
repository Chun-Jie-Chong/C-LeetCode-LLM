#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool dfs(char** board, int boardSize, int* boardColSize, 
         char* word, int idx, int row, int col, bool** visited) {
    int len = strlen(word);
    if (idx == len) return true;
    if (row < 0 || col < 0 || row >= boardSize || col >= *boardColSize 
        || visited[row][col] || board[row][col] != word[idx]) return false;
    
    visited[row][col] = true;
    bool found = dfs(board, boardSize, boardColSize, word, idx+1, row+1, col, visited) ||
                 dfs(board, boardSize, boardColSize, word, idx+1, row-1, col, visited) ||
                 dfs(board, boardSize, boardColSize, word, idx+1, row, col+1, visited) ||
                 dfs(board, boardSize, boardColSize, word, idx+1, row, col-1, visited);
    visited[row][col] = false;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize, cols = *boardColSize;
    bool** visited = (bool**)malloc(rows * sizeof(bool*));
    for (int i = 0; i < rows; ++i) {
        visited[i] = (bool*)calloc(cols, sizeof(bool));
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (dfs(board, boardSize, boardColSize, word, 0, i, j, visited)) {
                for (int k = 0; k < rows; ++k) free(visited[k]);
                free(visited);
                return true;
            }
        }
    }
    
    for (int i = 0; i < rows; ++i) free(visited[i]);
    free(visited);
    return false;
}
