class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void backtracking(vector<int> &nums, vector<int> &visited) {
        
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return ;
        }

        for (int i=0; i<nums.size(); i++) {
            if (!visited[i]) {
                cur.push_back(nums[i]);
                visited[i] = true;
                backtracking(nums, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), false);
        backtracking(nums, visited);
        return ans;
    }
};