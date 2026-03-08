class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, 0);
        // initialize
        dp[0] = 0;
        // if n=0, won't execute
        if (n>=1)
            dp[1] = 1;
         // if n=1, won't execute
        if (n>=2)
            dp[2] = 1;
        // dp loop
        for (int i=3; i<=n; i++) {
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};