class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<pair<int, int>>>& graph, int node, int parent) {

        for (auto &[neighbor, sign] : graph[node]) {
            if (neighbor != parent) {
                ans += sign;
                dfs(graph, neighbor, node);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i=0; i<connections.size(); i++) {
            int s = connections[i][0];
            int t = connections[i][1];
            adj[s].push_back({t, 1});
            adj[t].push_back({s, 0});   // false path
        }

        dfs(adj, 0, -1);

        return ans;
    }
};