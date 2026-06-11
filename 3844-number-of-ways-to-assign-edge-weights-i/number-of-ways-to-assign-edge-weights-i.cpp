class Solution {
public:
    int max_depth = 0;
    const int mod = 1e9+7;
    int qpow (long long a, long long b) {
        int ans = 1;
        while (b) {
            if (b & 1)
                ans = ans * a % mod;
            
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }
    int dfs(vector<vector<int>>& adj, int node, int prev) {
        int depth = 0;
        for (int next : adj[node]) {
            // finding next target
            if (next == prev) continue; // skip for parent
            depth = max(depth, 1 + dfs(adj, next, node));
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 2;
        vector<vector<int>> adj(n);
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int depth = dfs(adj, 1, 0);
        return qpow(2, depth - 1);
    }
};