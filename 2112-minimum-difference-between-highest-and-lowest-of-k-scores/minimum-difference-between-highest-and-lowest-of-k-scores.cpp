class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // 1. if the two number are closer, the more likely to get minimum difference
        sort(nums.begin(), nums.end());
        // 2. sliding window to pick `k` numbers
        int ans = INT_MAX;
        for (int i=0; (i+k-1) < nums.size(); i++) {
            int largest = nums[i+k-1];
            int smallest = nums[i];
            ans = min(ans, (largest-smallest));
        }
        return ans;
    }
};