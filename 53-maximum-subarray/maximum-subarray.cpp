class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;  // avoid always negative
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if (sum > ans) ans = sum;   // maximum continuouse sum
            if (sum < 0) sum = 0;   // reset
        }
        return ans;
    }
};