class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (int k, int targetSum, int startIndex, int sum) {
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return;
        }
        
        // pruning
        if (sum > targetSum) {
            return;
        }

        for (int i=startIndex; i<=9; i++) {
            path.push_back(i);
            backtracking(k, targetSum, i+1, sum + i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(k, n, 1, 0);
        return result;
    }
};