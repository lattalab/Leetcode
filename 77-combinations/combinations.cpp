class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(vector<int> &result, int cur, int n, int k) {
        if (result.size() == k) {
            ans.push_back(result);
            return ;
        }
        
        for (int i=cur; i<=n; i++) {
            result.push_back(i);
            backtracking(result, i+1, n, k);
            result.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtracking(temp, 1, n, k);
        return ans;
    }
};