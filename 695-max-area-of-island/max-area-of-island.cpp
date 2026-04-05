class Solution {
public:
    int area;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int x, int y) {
        int dir[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        for (int i=0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= grid.size()) continue ;
            if (ny < 0 || ny >= grid[0].size()) continue ;
            if (!visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                area += 1;
                dfs(grid, visited, nx, ny);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    visited[i][j] = true;
                    area = 1;
                    dfs(grid, visited, i, j);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};