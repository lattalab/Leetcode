class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> grid(n+1, vector<int>(n+1, INT_MAX));
        for (int i=0; i<times.size(); i++) {
            int s = times[i][0], t = times[i][1], w = times[i][2];
            grid[s][t] = w;
        }

        vector<bool> visited(n+1, false);
        vector<int> dist(n+1, INT_MAX);

        // start from k
        dist[k] = 0;

        // 1. each time select 1 node
        for (int i=1; i<=n; i++) {  // traverse each node
            int minDist = INT_MAX;
            int cur = k;
            for (int j=1; j<=n; j++) {
                // select non-visited node
                if (!visited[j] && dist[j] < minDist) {
                    minDist = dist[j];
                    cur = j;
                }
            }
            // 2. mark as visited
            visited[cur] = true;

            // 3. update the dist array
            for (int w=1; w<=n; w++) {
                if (!visited[w] && grid[cur][w] != INT_MAX && dist[cur] + grid[cur][w] < dist[w]) {
                    dist[w] = dist[cur] + grid[cur][w];
                }
            }
        }

        // real answer: finding maximum
        int ans = -1;
        for (int i=1; i<=n; i++) {
            ans = max(ans, dist[i]);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};