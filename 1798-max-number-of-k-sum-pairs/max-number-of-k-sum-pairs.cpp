class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // increasing
        sort(nums.begin(), nums.end());
        int ans = 0;
        // 2-pointer
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int num = nums[left] + nums[right];
            if (num > k) {
                right--;
            }
            else if (num < k) {
                left++;
            }
            else {
                ans++;
                left++;
                right--;
            }
        }
        return ans;
    }
};