class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // convert to adjacency list
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int s = edge[0];
            int v = edge[1];
            // bi-directional
            adj[s].push_back(v);
            adj[v].push_back(s);
        }
        // apply bfs
        queue<int> q;
        q.push(source);
        // visited array
        vector<int> visited(n, false);
        visited[source] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                int node = q.front();
                q.pop();
                // check if reach the destination
                if (node == destination) return true;

                for (auto neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        return false;
    }
};