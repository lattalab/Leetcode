class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // odd cannot be divide two parts
        if (sum % 2 != 0) return false;

        // maximum should be 200 * 100 / 2
        vector<int> dp(10001, 0);
        // package capacity
        int target = sum / 2;
        for (int i=0; i<nums.size(); i++) {
            for (int j=target; j>=nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        // find if values equals
        if (dp[target] == target) return true;
        return false;
    }
};