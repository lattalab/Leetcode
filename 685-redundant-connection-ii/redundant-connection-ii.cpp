class Solution {
    class DSU {
        vector<int> parent;
        vector<int> rank;
        int n;
        public:
            void init(int n) {
                this->n = n;
                parent.resize(n+1);
                rank.assign(n+1, 1);

                for (int i=1; i<=n; i++) {
                    parent[i] = i;
                }
            }
            int find(int x) {
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
            }
            void add(int x, int y) {
                x = find(x);
                y = find(y);
                if (x == y) return ;

                if (rank[x] > rank[y]) {
                    parent[y] = x;
                }
                else if (rank[x] < rank[y]) {
                    parent[x] = y;
                }
                else {
                    parent[x] = y;
                    rank[y]++;
                }
            }
            bool isSame(int x, int y) {
                x = find(x);
                y = find(y);
                return x == y;
            }
    };

public:
    bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int deleteEdge) {
        int n = edges.size();
        DSU dsu;
        dsu.init(n);
        for (int i=0; i<n; i++) {
            if (i == deleteEdge) continue;
            if (dsu.isSame(edges[i][0], edges[i][1])) {
                // still compose cycle
                return false;
            }
            dsu.add(edges[i][0], edges[i][1]);
        }
        return true;
    }

    int getRemoveEdge(const vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu;
        dsu.init(n);
        for (int i = 0; i < n; i++) { 
            if (dsu.isSame(edges[i][0], edges[i][1])) { 
                return i;
            } else {
                dsu.add(edges[i][0], edges[i][1]);
            }
        }
        return -1;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1, 0);
        // find the indegree is 2
        for(int i=0; i<edges.size(); i++) {
            indegree[edges[i][1]]++;
        }
        // find the edge
        vector<int> possible;
        // non-decreasing order for the last edge to be deleted
        for (int i=n-1; i>=0; i--) {
            if (indegree[edges[i][1]] == 2) {
                possible.push_back(i);
            }
        }
        // condition 2 and 3
        if (possible.size() > 0) {
            // due to non-decreasing order, 0-index first
            if (isTreeAfterRemoveEdge(edges, possible[0])) {
                return edges[possible[0]];
            }
            else {
                return edges[possible[1]];
            }
        }

        // condition 3
        int idx = getRemoveEdge(edges);
        return edges[idx];
    }
};