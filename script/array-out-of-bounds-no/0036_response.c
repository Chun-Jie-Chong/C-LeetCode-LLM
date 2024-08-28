#include <stdbool.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1'; 
                int k = (i / 3) * 3 + (j / 3); 
                
                if (row[i][num]++ || col[j][num]++ || box[k][num]++) {
                    return false;
                }
            }
        }
    }

    return true;
}
