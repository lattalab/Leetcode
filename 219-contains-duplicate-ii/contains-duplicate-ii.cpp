class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i=0; i<nums.size(); i++) {
            if (mp.count(nums[i])) {
                int diff = abs(i-mp[nums[i]]);
                if (diff <= k) return true;
            }
            // update current index
            mp[nums[i]] = i;
        }
        return false;
    }
};