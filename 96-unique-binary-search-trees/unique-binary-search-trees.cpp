class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            // root = j
            for (int j=1; j<=i; j++) {
                // left have j-1
                // right have i-j
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};