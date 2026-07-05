class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int left = i;
            int right = i;
            int temp = 1;
            while (right < nums.size()) {
                temp *= nums[right];
                if (temp >= k) {
                    break;
                }
                ans += 1;
                right++;
            }
        }
        return ans;
    }
};