class Solution {
public:
    const int MOD = 1000000007;
    int numberOfSets(int n, int k) {
        // dp[i][j], i for ith segments, j for [0, j]
        // initialize
        // dp[0][j] = 1
        // dp[i][0] = 0 for i > 0
        // transition: dp[i][j] = dp[i][j-1] + sigma(0, j-1) dp[i-1][p]
        
        vector<vector<int>> dp(k+1, vector<int>(n));
        // Initialized
        for (int i=1; i<k+1; i++) dp[i][0] = 0;
        for (int j=0; j<n; j++) dp[0][j] = 1;

        for (int i=1; i<k+1; i++) {
            // prefix sum to accumulate last part
            int sum = dp[i-1][0];

            for (int j=1; j<n; j++) {
                // Case 1: no new segment ends at j
                // Case 2: choose p < j as the start of [p, j]
                dp[i][j] = (dp[i][j-1] + sum) % MOD;
                // Prepare prefix sum for the next j
                sum = (sum + dp[i-1][j]) % MOD;
            }
        }

        return dp[k][n-1];
    }
};