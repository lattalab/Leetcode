class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // calculate num frequency
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 1;
            }
            else {
                mp[nums[i]]++;
            }
        }
        // search for 1
        for (auto x: mp) {
            if (x.second == 1)
                return x.first;
        }
        return -1;
    }
};