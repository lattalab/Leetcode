class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void backtracking(vector<int> &nums, int startIndex) {
        ans.push_back(cur);

        for (int i=startIndex; i<nums.size(); i++) {
            cur.push_back(nums[i]);
            backtracking(nums, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return ans;
    }
};