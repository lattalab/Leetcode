class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -INT_MAX;
        if (nums[0] < 0) {
            ans = max(ans, nums[n-1] * nums[n-2] * nums[n-3]);
            ans = max(ans, nums[0] * nums[1] * nums[n-1]);
        } 
        else {
            ans = nums[n-1] * nums[n-2] * nums[n-3];
        }
        return ans;
    }
};