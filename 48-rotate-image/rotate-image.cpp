class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // (i, j) -> (j, n-1-i)

        // transpose
        for (int i=0; i<matrix.size(); i++) {
            // j+1 due to symmertic swap, otherwise revert again
            for (int j=i+1; j<matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse by row
        for (int i=0; i<matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};