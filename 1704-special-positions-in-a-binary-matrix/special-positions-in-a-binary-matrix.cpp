class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // examine row
        vector<int> rows(mat.size(), 0);
        for (int i=0; i<mat.size(); i++) {
            for (int j=0; j<mat[i].size(); j++) {
                rows[i] += (mat[i][j] == 1) ? 1: 0;
            }
        }
        // examine col
        vector<int> cols(mat[0].size(), 0);
        for (int j=0; j<mat[0].size(); j++) {
            for (int i=0; i<mat.size(); i++) {
                cols[j] += (mat[i][j] == 1) ? 1: 0;
            }
        }
        
        // count how manys
        int ans = 0;
        for (int i = 0; i<mat.size(); i++) {
            for (int j=0; j<mat[0].size(); j++) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};