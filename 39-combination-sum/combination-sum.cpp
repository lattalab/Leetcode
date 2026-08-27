class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void backtracking(vector<int> &candidates, int startIndex, int sum, int target) {
        if (sum == target) {
            ans.push_back(cur);
            return ;
        }

        // pruning
        if (sum > target) return ;

        for (int i=startIndex; i<candidates.size(); i++) {
            cur.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, i, sum, target);
            cur.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, 0, 0, target);
        return ans;
    }
};