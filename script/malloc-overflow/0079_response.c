#include <stdbool.h>
#include <string.h>

#define MAX_M 6
#define MAX_N 6

bool existHelper(char board[MAX_M][MAX_N], int boardSize, int* boardColSize, char* word, int x, int y, int wordIndex, bool visited[MAX_M][MAX_N]) {
    if (wordIndex == strlen(word)) {
        return true;
    }
    if (x < 0 || x >= boardSize || y < 0 || y >= *boardColSize || visited[x][y] || board[x][y] != word[wordIndex]) {
        return false;
    }
    
    visited[x][y] = true;
    bool result = existHelper(board, boardSize, boardColSize, word, x + 1, y, wordIndex + 1, visited) ||
                  existHelper(board, boardSize, boardColSize, word, x - 1, y, wordIndex + 1, visited) ||
                  existHelper(board, boardSize, boardColSize, word, x, y + 1, wordIndex + 1, visited) ||
                  existHelper(board, boardSize, boardColSize, word, x, y - 1, wordIndex + 1, visited);
    visited[x][y] = false;
    return result;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    char boardMatrix[MAX_M][MAX_N];
    bool visited[MAX_M][MAX_N] = { false };
    
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            boardMatrix[i][j] = board[i][j];
        }
    }
    
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (existHelper(boardMatrix, boardSize, boardColSize, word, i, j, 0, visited)) {
                return true;
            }
        }
    }
    return false;
}
