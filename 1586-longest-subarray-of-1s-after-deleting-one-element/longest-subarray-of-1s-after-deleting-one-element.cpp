class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countZeros = 0;
        int left = 0;
        int ans = 0;
        for (int right=0; right < nums.size(); right++) {
            if (nums[right] == 0) countZeros++;
            // window exceed 1 zero
            while (countZeros > 1) {
                if (nums[left] == 0) countZeros--;
                left++;
            }
            // when zeros exist: length = right-left+1-countZeros
            // when there is no zero, must delete one = right-left+1-1
            ans = max(ans, right-left);
        }
        return ans;
    }
};