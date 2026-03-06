class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        // store total sum
        int total = 0;
        for (int i=0; i<n; i++) {
            total += nums[i];
        }
        // find pivot index
        int curr = 0;
        for (int i=0; i<n; i++) {
            int left = curr;
            int right = total - left - nums[i];
            if (left == right) {
                return i;
            }
            curr += nums[i];
        }
        return -1;
    }
};