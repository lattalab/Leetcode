class Solution {
    struct cmp {
        bool operator() (const pair<int, double> &pa, const pair<int, double> &pb) {
            return pa.second < pb.second;
        }
    };
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // convert adjacency list
        vector<vector<pair<int, double>>> adj(n);
        for (int i=0; i<edges.size(); i++) {
            int s = edges[i][0], t = edges[i][1];
            // undirected graph
            adj[s].push_back({t, succProb[i]});
            adj[t].push_back({s, succProb[i]});
        }

        vector<bool> visited(n, false);
        vector<double> prob(n, 0);
        // maxheap: finding maximum prob
        priority_queue<pair<int, double>, vector<pair<int, double>>, cmp> pq;

        // initialize: start point
        prob[start] = 1.0;
        pq.push({start, 1.0});

        while (!pq.empty()) {
            auto [node, value] = pq.top();
            pq.pop();

            if (visited[node]) continue;

            // marked as visited
            visited[node] = true;

            // update edges
            for (auto [next, weight] : adj[node]) {
                double newProb = value * weight;
                if (!visited[next] && newProb > prob[next]) {
                    prob[next] = newProb;
                    pq.push({next, prob[next]});
                }
            }
        }

        return prob[end];
    }
};