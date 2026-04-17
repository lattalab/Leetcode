class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dir[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        int ans = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    for (int k=0; k<4; k++) {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[i].size() || grid[nx][ny] == 0) {
                            ans ++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};