class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs (vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
        if (visited[x][y])  return ;
        visited[x][y] = true;

        for (int i=0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) {
                continue;
            }
            if (grid[nx][ny] >= grid[x][y]) {
                dfs(grid, visited, nx, ny);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> first_visited(m, vector<bool>(n, false));
        vector<vector<bool>> second_visited(m, vector<bool>(n, false));

        // flow from edge to center (lower to high)

        // who can reach pacific ocean
        for (int i=0; i<m; i++) dfs(heights, first_visited, i, 0);
        for (int j=0; j<n; j++) dfs(heights, first_visited, 0, j);

        // who can reach altantic ocean
        for (int i=0; i<m; i++) dfs(heights, second_visited, i, n-1);
        for (int j=0; j<n; j++) dfs(heights, second_visited, m-1, j);

        // find the answers
        vector<vector<int>> ans;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (first_visited[i][j] && second_visited[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};