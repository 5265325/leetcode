bool isValidRow(char ** board, int row)
{
    int buf[9];
    for (int i = 0; i < 9; i++) {
        buf[i] = 0;
    }
    
    for (int i = 0; i < 9; i++) {
        if (board[row][i] != '.') {
            if (buf[board[row][i] - '1']++ > 0) {
                return false;
            }
        }
    }
    return true;
}

bool isValidLine(char ** board, int line)
{
    int buf[9];
    for (int i = 0; i < 9; i++) {
        buf[i] = 0;
    }
    
    for (int i = 0; i < 9; i++) {
        if (board[i][line] != '.') {
            if (buf[board[i][line] - '1']++ > 0) {
                return false;
            }
        }
    }
    return true;
}

bool isValidSubbox(char ** board, int x, int y)
{
    int buf[9];
    for (int i = 0; i < 9; i++) {
        buf[i] = 0;
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[y*3 + i][x*3 + j] != '.') {
                if (buf[board[y*3 + i][x*3 + j] - '1']++ > 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    for (int i = 0; i < 9; i++) {
        if (!isValidRow(board, i) || !isValidLine(board, i) || !isValidSubbox(board, i % 3, i / 3)) {
            return false;
        }
    }
    return true;
}