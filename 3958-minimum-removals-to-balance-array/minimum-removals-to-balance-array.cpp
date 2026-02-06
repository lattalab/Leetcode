class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int MaxSubLen = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while ((long long)nums[right] > (long long)k*nums[left]) {
                left++;
            }
            MaxSubLen = max(MaxSubLen, right-left+1);
        }
        return nums.size() - MaxSubLen;
    }
};