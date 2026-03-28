class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;
    int destination;
    void dfs(vector<vector<int>> &edges, int node) {
        if (node == destination) {
            // reach destination
            results.push_back(path);
            return;
        }
        for (int i=0; i<edges[node].size(); i++) {
            // trace current edge that can reach from current node
            path.push_back(edges[node][i]);
            dfs(edges, edges[node][i]);
            path.pop_back();    // backtracking
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        destination = graph.size() - 1;    // index from 0
        path.push_back(0);
        dfs(graph, 0);
        return results;
    }
};