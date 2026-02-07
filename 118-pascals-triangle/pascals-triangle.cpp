class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        results.push_back({1});
        if (numRows == 1) return results;
        results.push_back({1, 1});
        if (numRows == 2) return results;
        for (int row=2; row<numRows; row++) {
            results.push_back({1});
            for (int i=0; i<results[row-1].size()-1; i++) {
                results[row].push_back( results[row-1][i] + results[row-1][i+1] );
            }
            results[row].push_back(1);
        }
        return results;
    }
};