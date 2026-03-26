class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // put from back to front
        vector<int> ans(nums.size(), 0);
        int idx = nums.size() - 1;

        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int l = nums[left] * nums[left];
            int r = nums[right] * nums[right];
            if (l >= r) {
                ans[idx--] = l;
                left++;
            }
            else {
                ans[idx--] = r;
                right--;
            }
        }
        return ans;
    }
};