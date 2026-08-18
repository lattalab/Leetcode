class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        // calculate the frequency
        unordered_map<int, int> mp;
        for (auto n : nums) mp[n]++;
        
        int ans = -1;   // no almost missing
        if (k == 1) {
            // return largest number that actually appear once
            for (auto &p : mp) {
                if (p.second == 1 && p.first > ans)
                    ans = p.first;
            }
        }
        else if (k == n) {
            // return largest number
            ans = *max_element(nums.begin(), nums.end());
        }
        else {
            // 1 < k < n
            // depending on nums[0] and nums[n-1]
            if (mp[nums[0]] == 1 && nums[0] > ans)
                ans = nums[0];
            if (mp[nums[n-1]] == 1 && nums[n-1] > ans)
                ans = nums[n-1];
        }

        return ans;
    }
};