class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // put into hash
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        // find majority
        int maxVal;
        int times = 0;
        for (auto p : mp) {
            if (p.second > times) {
                times = p.second;
                maxVal = p.first;
            }
        }
        return maxVal;
    }
};