class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        // 1. create adjacent list
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto road : roads) {
            int s = road[0];
            int v = road[1];
            int w = road[2];
            adj[s].push_back({v, w});
            adj[v].push_back({s, w});
        }
        // 2. bfs
        queue<int> q;
        q.push(1);

        // add visit array to avoid repetition
        vector<bool> visited(n+1, false);
        visited[1] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                ans = min(ans, it.second);

                if (!visited[it.first]) {
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
};