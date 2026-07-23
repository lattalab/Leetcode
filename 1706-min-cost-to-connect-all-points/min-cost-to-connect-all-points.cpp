class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        
        // Prim's algorithm
        for (int i=1; i<n; i++) {
            int cur = 0;
            int minDist = INT_MAX;
            // 1. select the victim
            for (int j=0; j<n; j++) {
                if (!visited[j] && minDist > dist[j]) {
                    cur = j;
                    minDist = dist[j];
                }
            }
            // 2. add to minimum spanning tree
            visited[cur] = true;
            // 3. update weight
            for (int i=0; i<n; i++) {
                if (visited[i] == false) {
                    int cost = abs(points[i][0] - points[cur][0]) + abs(points[i][1] - points[cur][1]);
                    dist[i] = min(dist[i], cost);
                }
            }
        }

        // accumlate the weight
        int ans = 0;
        for (int i=1; i<n; i++) {
            ans += dist[i];
        }
        return ans;
    }
};