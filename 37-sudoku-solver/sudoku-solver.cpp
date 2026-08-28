class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char val) {
        // check row
        for (int j=0; j<board[row].size(); j++) {
            if (board[row][j] == val)
                return false;
        }
        // check col
        for (int i=0; i<board.size(); i++) {
            if (board[i][col] == val)
                return false;
        }
        // check for square
        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;
        for (int i = startRow; i < startRow+3; i++) {
            for (int j = startCol; j < startCol+3; j++) {
                if (board[i][j] == val)
                    return false;
            }
        }

        return true;
    }
    bool backtracking(vector<vector<char>>& board) {
        // find empty space
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == '.') {
                    // find valid digit
                    for (char digit = '1'; digit<='9'; digit++) {
                        // we can put this value
                        if (check(board, i, j, digit)) {
                            board[i][j] = digit;
                            if (backtracking(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};