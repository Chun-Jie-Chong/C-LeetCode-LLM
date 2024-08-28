#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int m, int n, int i, int j, char* word, int k) {
    if (k == strlen(word)) return true;
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k]) return false;
    char tmp = board[i][j];
    board[i][j] = '*';
    bool found = dfs(board, m, n, i + 1, j, word, k + 1) ||
                 dfs(board, m, n, i - 1, j, word, k + 1) ||
                 dfs(board, m, n, i, j + 1, word, k + 1) ||
                 dfs(board, m, n, i, j - 1, word, k + 1);
    board[i][j] = tmp;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (dfs(board, boardSize, boardColSize[i], i, j, word, 0)) return true;
        }
    }
    return false;
}
