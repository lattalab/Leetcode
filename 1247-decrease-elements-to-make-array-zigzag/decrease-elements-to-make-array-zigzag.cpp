class Solution {
public:
    int zigzag (vector<int> &nums, int start_index) {
        int ans = 0;
        for (int i=start_index; i<nums.size(); i+=2) {
            int left = (i-1 >= 0) ? nums[i-1] : 1e4;
            int right = (i+1 < nums.size()) ? nums[i+1] : 1e4;
            
            // make target index smaller
            int dec = min(left, right);
            ans += max(0, nums[i] - dec + 1);
        }
        return ans;
    } 
    int movesToMakeZigzag(vector<int>& nums) {
        return min( zigzag(nums, 0), zigzag(nums, 1) );
    }
};