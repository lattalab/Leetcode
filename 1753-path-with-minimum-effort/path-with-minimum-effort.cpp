class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // convert to adjacentcy list
        int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<pair<int, int>>> adj(m*n);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int source = i*n + j;
                for (int k=0; k<4; k++) {
                    int nx = i+dir[k][0];
                    int ny = j+dir[k][1];

                    if (nx >= m || nx < 0 || ny < 0 || ny >= n) continue;

                    int target = nx * n + ny;
                    int weight = abs(heights[i][j] - heights[nx][ny]);
                    adj[source].push_back({target, weight});
                }
            }
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        
        vector<int> dist(m*n, INT_MAX);
        vector<int> visited(m*n, false);

        // initial start
        dist[0] = 0;
        pq.push({0, 0});

        // 1. select the nearest node
        while (!pq.empty()) {
            auto [effort,node] = pq.top();
            pq.pop();

            if(node==m*n-1)
                return effort;

            if(effort>dist[node])
                continue;

            // 3. update the edges
            for (auto [next, weight] : adj[node]) {
                int newEffort=max(effort,weight);

                if (newEffort < dist[next])
                {
                    dist[next]=newEffort;
                    pq.push({newEffort,next});
                }
            }
        }

        return 0;
    }
};