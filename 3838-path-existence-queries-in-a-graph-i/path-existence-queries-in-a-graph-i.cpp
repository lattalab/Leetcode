class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> g(n, 0);
        for (int i=1; i<nums.size(); i++) {
            g[i] = g[i-1] + ((nums[i] - nums[i-1] <= maxDiff) ? 0 : 1);
        }
        
        vector<bool> results(queries.size(), false);
        for (int i=0; i<queries.size(); i++) {
            int s = queries[i][0];
            int v = queries[i][1];
            if (g[s] == g[v]) {
                results[i] = true; 
            }
        }
        return results;
    }
};