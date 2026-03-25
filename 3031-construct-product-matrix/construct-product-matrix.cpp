class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        // initialize
        vector<vector<int>> ans( grid.size(), vector<int>(grid[0].size(), 1) );

        int mod = 12345;

        int prefix = 1;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                ans[i][j] = prefix;
                prefix = ((prefix % mod) * (grid[i][j] % mod) % mod);
            }
        }

        int postfix = 1;
        for (int i=grid.size()-1; i>=0; i--) {
            for (int j=grid[i].size()-1; j>=0; j--) {
                ans[i][j] = ((ans[i][j] % mod) * postfix % mod);
                postfix = ((postfix % mod) * (grid[i][j] % mod) % mod);
            }
        }

        return ans;
    }
};