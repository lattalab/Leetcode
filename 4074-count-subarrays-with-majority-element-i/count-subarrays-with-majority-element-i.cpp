class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int cnt = 0;
            for (int j=i; j<nums.size(); j++) {
                cnt += (nums[j] == target) ? 1: -1;
                if (cnt > 0) ans++;
            }
        }
        return ans;
    }
};