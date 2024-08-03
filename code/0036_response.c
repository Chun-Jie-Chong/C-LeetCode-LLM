#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool rows[9][9] = {0};
    bool cols[9][9] = {0};
    bool boxes[9][9] = {0};

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                int k = (i / 3) * 3 + (j / 3);
                
                if (rows[i][num] || cols[j][num] || boxes[k][num])
                    return false;
                
                rows[i][num] = cols[j][num] = boxes[k][num] = true;
            }
        }
    }

    return true;
}
