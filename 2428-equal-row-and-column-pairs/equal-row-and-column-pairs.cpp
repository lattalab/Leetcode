class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> hashmap;
        int row = grid.size();
        int col = grid[0].size();
        // record the row
        for (int i=0; i<row; i++) hashmap[grid[i]]++;

        int ans = 0;
        for (int j=0; j<col; j++) {
            vector<int> column;
            for (int i=0; i<row; i++) {
                column.push_back(grid[i][j]);
            }
            if (hashmap.count(column)) {
                ans += hashmap[column];
            }
        }
        return ans;
    }
};