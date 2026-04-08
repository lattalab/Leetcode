class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>> &board, int x, int y) {
        board[x][y] = 'P';
        for (int i=0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
                continue;
            if (board[nx][ny] == 'O') 
                dfs(board, nx, ny);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // find left and right corner
        for (int i=0; i<m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        // find upper and lower corner
        for (int j=0; j<n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }

        // make graph match to desired result
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                // revert valid region into `O`
                if (board[i][j] == 'P') board[i][j] = 'O';
                // make `surround` into X
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};