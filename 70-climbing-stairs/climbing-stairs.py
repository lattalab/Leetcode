class Solution:
    def climbStairs(self, n: int) -> int:
        # list extension
        dp = [0] * 46
        # initialize
        dp[1], dp[2] = 1, 2
        # formula: dp[n] = dp[n-1] + dp[n-2], n > 2
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        
        return dp[n]