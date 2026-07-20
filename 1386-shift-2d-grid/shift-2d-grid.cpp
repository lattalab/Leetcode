class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                // row_index * col_num + col_index
                int idx = i*n + j;
                int target = (idx + k) % (m * n);
                int row = target / n;
                int col = target % n;
                ans[row][col] = grid[i][j];
            }
        }
        return ans;
    }
};