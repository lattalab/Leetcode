class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        set<int> ans1;
        for (int i=0; i<nums1.size(); i++) {
            if (st2.count(nums1[i])) continue;
            ans1.insert(nums1[i]);
        }
        set<int> ans2;
        for (int i=0; i<nums2.size(); i++) {
            if (!st1.count(nums2[i])) {
                ans2.insert(nums2[i]);
            }
        }

        vector<vector<int>> ans(2);
        ans[0] = vector<int>(ans1.begin(), ans1.end());
        ans[1] = vector<int>(ans2.begin(), ans2.end());

        return ans;
    }
};