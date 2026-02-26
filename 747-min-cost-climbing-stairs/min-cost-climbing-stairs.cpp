class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1010];
        // start on whether 0 or 1
        dp[0] = 0;
        dp[1] = 0;
        // top: number of stair = cost.size()
        for (int i=2; i<=cost.size(); i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[cost.size()];
    }
};