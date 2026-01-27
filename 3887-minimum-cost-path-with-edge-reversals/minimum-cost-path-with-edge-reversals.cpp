class Solution {
public:

    int dijkstra (int n, vector< vector< pair<int, int> > > &adj) {
        vector<int> dist(n, INT_MAX);
        vector<bool> visit(n, false);
        // store cur->next 's weight and current node (MIN HEAP)
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        // main logic
        dist[0] = 0;
        pq.push({0, 0});
        while ( !pq.empty() ) {
            int cur = pq.top().second;
            pq.pop();
            
            // pruning -> each node visit once
            if (visit[cur]) continue;
            visit[cur] = true;
            
            for (int i=0; i<adj[cur].size(); i++) {
                int next = adj[cur][i].first;
                int w = adj[cur][i].second;

                if (dist[cur] + w < dist[next]) {
                    dist[next] = dist[cur] + w;
                    pq.push({dist[next], next});
                }
            }
        }

        if (dist[n-1] == INT_MAX) return -1;
        return dist[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        // modify into adjacent list
        vector<vector<pair<int, int>>> adj(n);
        // O(edges)
        for (int i=0; i<edges.size(); i++) {
            int cur = edges[i][0];
            int next = edges[i][1];
            int weight = edges[i][2];
            // normal way
            adj[cur].push_back({next, weight});
            // reverse
            adj[next].push_back({cur, 2*weight});
        }
        return dijkstra(n, adj);
    }
};