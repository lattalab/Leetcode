class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& candidates, int target, int startIndex, vector<bool> &used) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        // pruning
        if (target < 0) {
            return ;
        }
        for (int i=startIndex; i<candidates.size(); i++) {
            if (i > 0 && (candidates[i] == candidates[i-1]) && (used[i-1] == false))
                continue;
            
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target-candidates[i], i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return result;
    }
};