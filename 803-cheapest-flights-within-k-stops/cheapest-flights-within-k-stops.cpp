class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // bellman-ford: relax the edge for k+1 times
        for (int i=0; i<=k; i++) {
            vector<int> temp = dist;
            // iterate the adjacency list, and update the edges
            for (vector<int> &v : flights) {
                int s = v[0];
                int t = v[1];
                int val = v[2];
                if (dist[s] != INT_MAX && dist[s] + val < temp[t]) {
                    temp[t] = dist[s] + val;
                }
            }
            dist = temp;
        }

        if (dist[dst] == INT_MAX) return -1;
        else return dist[dst];

    }
};