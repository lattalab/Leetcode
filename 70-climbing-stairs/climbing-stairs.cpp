class Solution {
public:
    int climbStairs(int n) {
        // 1. define 1D dp array, and its index refer to case n
        int dp[50];
        // 2. formula = dp[n] = dp[n-1] + dp[n-2], n>=2
        // 3. initialized dp[1] = 1, dp[2] = 2;
        dp[0] = 0;  // don't care
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};