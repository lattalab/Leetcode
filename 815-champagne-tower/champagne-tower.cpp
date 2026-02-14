class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double pyramid[110][110] = {0};
        // pour into first layer
        pyramid[0][0] = poured;

        for (int r=0; r<100; r++) {
            for (int c=0; c<100; c++) {
                if (pyramid[r][c] > 1.0) {
                    double excess = (pyramid[r][c] - 1) / 2.0;
                    pyramid[r][c] = 1.0;
                    // excess to next row
                    pyramid[r+1][c] += excess;
                    pyramid[r+1][c+1] += excess;
                }
            }
        }
        return pyramid[query_row][query_glass];
    }
};