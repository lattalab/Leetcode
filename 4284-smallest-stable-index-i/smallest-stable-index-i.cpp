class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        // precalculate small value
        vector<int> small(n);
        int min_val = nums[n-1];
        for (int i=n-1; i>=0; i--) {
            min_val = min(min_val, nums[i]);
            small[i] = min_val;
        }

        // calculate the stable
        int max_val = nums[0];
        for (int i=0; i<n; i++) {
            max_val = max(max_val, nums[i]);
            int stable = max_val - small[i];
            if (stable <= k) {
                return i;
            }
        }
        return -1;
    }
};