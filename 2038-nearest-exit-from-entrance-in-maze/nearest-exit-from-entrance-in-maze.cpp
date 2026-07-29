class Solution {
public:
    struct point {
        int x, y;
        point(vector<int> &v) : x(v[0]), y(v[1]) {}
        point(int x, int y) : x(x), y(y) {}
    };
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();

        int step = 0;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        queue<struct point> q;
        q.push(point(entrance));
        visited[entrance[0]][entrance[1]] = true;
        // mark entrance as special point
        maze[entrance[0]][entrance[1]] = 'e';

        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [row, col] = q.front();
                q.pop();

                // examine out
                // entrance is excluded automatically
                if(step > 0 && (row == 0 || row == m-1 || col == 0 || col == n-1)) {
                    return step;
                }

                for (int j=0; j<4; j++) {
                    int nr = row + dir[j].first;
                    int nc = col + dir[j].second;

                    if (nr >= m || nr < 0 || nc >= n || nc < 0) continue;

                    if (maze[nr][nc] != '.') continue;

                    if (visited[nr][nc]) continue;

                    q.push(point(nr, nc));
                    visited[nr][nc] = true;
                }
            }
            step++;
        }
        return -1;
    }
};