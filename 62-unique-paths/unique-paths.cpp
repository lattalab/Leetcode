class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1. how to walk form dp[0][0] to dp[i][j]
        int dp[m][n];
        // 2. initialized
        for (int j=0; j<n; j++) dp[0][j] = 1;
        for (int i=0; i<m; i++) dp[i][0] = 1;
        // 3. formula: dp[i][j] = dp[i-1][j] + dp[i][j-1]
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};