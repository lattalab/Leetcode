class Solution {
public:
    void init(vector<int> &p) {
        for (int i=0; i<p.size(); i++) {
            // parent = self
            p[i] = i;
        }
    }
    void join(vector<int> &parent, vector<int> &rank, int x, int y) {
        int u = find(parent, x);
        int v = find(parent, y);

        if (u==v) return ;

        if (rank[u] > rank[v]) {
            parent[v] = u;
        } 
        else if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else {
            parent[u] = v;
            rank[v]++;
        }
    }
    int find(vector<int> &p, int u) {
        if (p[u] == u) return u;
        p[u] = find(p, p[u]);
        return p[u];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);
        init(parent);

        // traverse the connected matrix to do Union-Find
        int group = n;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (isConnected[i][j] && find(parent, i) != find(parent, j)) {
                    group--;
                    join(parent, rank, i, j);
                }
            }
        }
        return group;
    }
};