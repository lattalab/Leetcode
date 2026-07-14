class Solution {
public:
    void dfs(int cur, vector<vector<int>> &adj, vector<bool> &visited) {
        if (visited[cur])
            return ;

        visited[cur] = true;

        for (auto node : adj[cur]) {
            dfs(node, adj, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // create adjacency list
        int n = rooms.size();
        vector<vector<int>> adj(n);
        for (int i=0; i<rooms.size(); i++) {
            for (auto v : rooms[i]) {
                adj[i].push_back(v);
            }
        }

        vector<bool> visited(n, false);
        dfs(0, adj, visited);

        // examine
        for (int i=0; i<n; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};