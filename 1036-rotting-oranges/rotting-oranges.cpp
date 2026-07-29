class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int minute = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dir[4][2] = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
        };

        // finding the rotten orange
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty() && fresh) {
            int size = q.size();
            // iterate current size
            for (int i=0; i<size; i++) {

                auto [row, col] = q.front();
                q.pop();
                // for each node, examint the valid direction
                for (int j=0; j<4; j++) {
                    int nr = row + dir[j][0];
                    int nc = col + dir[j][1];

                    if (nr >= m || nr < 0 || nc >= n || nc < 0)
                        continue;
                    
                    if (visited[nr][nc]) continue;

                    // spread rotten
                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }

            minute++;
        }

        return (fresh == 0) ? minute : -1;
    }
};