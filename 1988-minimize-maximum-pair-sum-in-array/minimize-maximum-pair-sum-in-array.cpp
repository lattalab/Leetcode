class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // greedy -> pair the largest number with smallest number
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() -1;
        int ans = 0;
        while (end > start) {
            int PairSum = nums[start] + nums[end];
            ans = max(ans, PairSum);
            start++;
            end--;
        }
        return ans;
    }
};