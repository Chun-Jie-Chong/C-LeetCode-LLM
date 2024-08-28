#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool dfs(char** board, int boardSize, int* boardColSize, 
         char* word, int i, int j, int pos) {
    if (pos == strlen(word)) return true;
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i] || 
        board[i][j] != word[pos]) return false;

    char temp = board[i][j];
    board[i][j] = '*'; // mark as visited

    bool found = dfs(board, boardSize, boardColSize, word, i + 1, j, pos + 1) ||
                 dfs(board, boardSize, boardColSize, word, i - 1, j, pos + 1) ||
                 dfs(board, boardSize, boardColSize, word, i, j + 1, pos + 1) ||
                 dfs(board, boardSize, boardColSize, word, i, j - 1, pos + 1);

    board[i][j] = temp; // unmark
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == word[0] && 
                dfs(board, boardSize, boardColSize, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}