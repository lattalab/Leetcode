class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int x, int y) {
        // make non-island into ocean
        grid[x][y] = 0;
        for (int i=0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= grid.size()) continue;
            if (ny < 0 || ny >= grid[0].size()) continue;
            // when encounter land, make it into ocean
            if (grid[nx][ny] == 1)
                dfs(grid, nx, ny);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // examine left and right column
        for (int i=0; i<m; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][n-1] == 1) dfs(grid, i, n-1);
        }    
        // examine upper and bottom row
        for (int j=0; j<n; j++) {
            if (grid[0][j] == 1) dfs(grid, 0, j);
            if (grid[m-1][j] == 1) dfs(grid, m-1, j);
        } 
        // calculating remain area
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) 
                    ans++;
            }
        }
        return ans;
    }
};