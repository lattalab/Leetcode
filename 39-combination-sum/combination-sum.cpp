class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        // pruning
        if (sum > target) {
            return ;
        }
        for (int i=startIndex; i<candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum+candidates[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};