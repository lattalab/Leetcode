class Solution {
    class DSU {
        private:
            int n;
            vector<int> parent;
            vector<int> rank;
        public:
            DSU (int n) {
                this->n = n;

                for (int i=0; i<n; i++) {
                    // point to itself as parent
                    parent.push_back(i);
                    rank.push_back(1);
                }
            }

            int find(int x) {
                if (parent[x] == x) return x;
                // path compression
                parent[x] = find(parent[x]);
                return parent[x];
            }

            bool add (int x, int y) {
                x = find(x);
                y = find(y);

                // if the same set, bypass
                if (x == y) return false;

                if (rank[x] > rank[y]) {
                    parent[y] = x;
                }
                else if (rank[x] < rank[y]) {
                    parent[x] = y;
                }
                else {
                    parent[x] = y;
                    rank[x]++;
                }
                return true;
            }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // create disjoint set
        DSU dsu(n);

        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (!dsu.add(u-1, v-1)) {
                return edges[i];
            }
        }
        return {};
    }
};