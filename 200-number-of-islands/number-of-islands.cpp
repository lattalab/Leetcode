class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &visited, int x, int y) {
        int direction[4][2] = {
            {0, 1},
            {0, -1},
            {-1, 0},
            {1, 0}
        };
        if ((grid[x][y] == '0') || (visited[x][y] == 1))
            return ;
        
        visited[x][y] = 1;
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<4; i++) {
            // trace direction
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (nx < 0 || nx >= m)  continue;
            if (ny < 0 || ny >= n)  continue;

            if ((grid[nx][ny] == '1') && (visited[nx][ny] == 0)) {
                dfs(grid, visited, nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int result = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if ((grid[i][j] == '1') && (visited[i][j] == 0)) {
                    result++;
                    // find maximum land
                    dfs(grid, visited, i, j);
                }
            }
        }
        return result;
    }
};