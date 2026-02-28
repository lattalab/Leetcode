class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // special case
        // - 起點終點出現障礙，不可抵達
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) 
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        // make obstacle to be zero (can't reach)
        for (int i=0; i<m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j=0; j<n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }
        // recursive
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};