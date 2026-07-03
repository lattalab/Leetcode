class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        
        int left = 0;
        int right = 0;
        int zeros = 0;
        while (right < nums.size()) {
            if (nums[right] == 1) {
                ans = max(ans, right-left+1);
                right++;
            }
            else {  // nums[right] == 0;
                if (zeros < k) {
                    ans = max(ans, right-left+1);
                    right++;
                    zeros++;
                }
                else {
                    if (nums[left] == 0) {
                        zeros--;
                    }
                    left++;
                }
            }
        }
        return ans;
    }
};