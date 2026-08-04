class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create 3D dp for d_ij^k
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // init -> d_ij^0, there is no intermediate point
        for (int i=0; i<n; i++) {
            dist[i][i] = 0;
        }
        for (auto &edge : edges) {
            int s = edge[0], t = edge[1], w = edge[2];
            dist[s][t] = w;
            dist[t][s] = w;
        }

        // floyd
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // calculate all neightbors from specific city
        vector<int> cities(n, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i!=j && dist[i][j] <= distanceThreshold) {
                    cities[i]++;
                }
            }
        }

        // we should return the maximum city number
        int ans;
        int count = INT_MAX;
        for (int i=0; i<cities.size(); i++) {
            if (cities[i] <= count) {
                count = cities[i];
                ans = i;
            }
        }
        return ans;
    }
};