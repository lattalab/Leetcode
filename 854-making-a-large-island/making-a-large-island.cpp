class Solution {
public:
    int count = 0;
    int dir[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark) {
        if (grid[x][y] != 1 || visited[x][y] == true) return ;
        
        visited[x][y] = true;
        grid[x][y] = mark;  // mark the island
        count++;            // calculate island

        for(int i=0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
            dfs(grid, visited, nx, ny, mark);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        int mark = 2;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        map<int, int> mp;   // store number of island to area
        bool isAllLand = true;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                
                if (grid[i][j] == 0) isAllLand = false;

                if (grid[i][j] == 1 && visited[i][j] == false) {
                    count = 0;
                    dfs(grid, visited, i, j, mark);
                    mp[mark] = count;   // save the information
                    mark++;
                } 
            }
        }

        // edge case: all 1
        if (isAllLand) return grid.size() * grid[0].size();

        int result = 0;
        set<int> st;    // avoid counting repeative area
        // try to change the 0 to 1 and test for each cell
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                int total = 1;  // calculate the area
                st.clear();     // every time should reset
                if (grid[i][j] == 0) {
                    // test the nearset 4 region
                    for (int k=0; k<4; k++) {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        // index out of bound
                        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
                        
                        // same area shouldn't be counted twice
                        int mark = grid[nx][ny];
                        if (st.count(mark)) continue;

                        int area = mp[mark];
                        total += area;
                        st.insert(mark);
                    }
                }
                result = max (result, total);
            }
        }

        return result;
    }
};