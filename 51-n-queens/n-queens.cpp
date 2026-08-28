class Solution {
public:
    vector<vector<string>> ans;
    bool check(vector<string> &board, int row, int col) {
        int n = board.size();
        // check for row
        for (int i=0; i<n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // check for col
        for (int j=0; j<n; j++) {
            if (board[row][j] == 'Q')
                return false;
        }
        // check for diag
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        };

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void backtracking(vector<string> &board, int row) {        
        int n = board.size();

        if (row == n) {
            ans.push_back(board);
            return ;
        }

        for (int i=0; i<n; i++) {
            if (check(board, row, i)) {
                board[row][i] = 'Q';
                backtracking(board, row+1);
                board[row][i] = '.'; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, std::string(n, '.'));
        backtracking(board, 0);
        return ans;
    }
};