class Solution {
public:
    int integerBreak(int n) {
        int dp[60] = {0};
        dp[2] = 1;
        for (int i=3; i<=n; i++) {
            // main logic
            for (int j=1; j<i; j++) {
                // try to find larger value
                int temp = max(j*(i-j), j*dp[i-j]);
                // test if larger than current
                dp[i] = max(dp[i], temp);
            }
        }
        return dp[n];
    }
};