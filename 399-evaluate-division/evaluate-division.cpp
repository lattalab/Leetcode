class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &visited, string &current, string &target, double product) {

        // walk to target, store the result
        if (current == target) {
            return product;
        }

        // mark as visited
        visited.insert(current);

        for (auto &[next, w] : adj[current]) {
            if (!visited.count(next)) {
                product *= w;
                double result = dfs(adj, visited, next, target, product);
                product /= w;

                // find a valid path, return to last layer
                if (result != -1) return result;
            }
        }

        // no valid path in this layer
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // create graph 
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i=0; i<equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];
            adj[a].push_back({b, value});
            adj[b].push_back({a, 1.0 / value});
        }

        vector<double> result;
        // apply dfs to get queries answer
        for(int i=0; i<queries.size(); i++) {
            string source = queries[i][0];
            string target = queries[i][1];
            
            if (!adj.count(source) || !adj.count(target)) {
                result.push_back(-1);
                continue;
            }

            unordered_set<string> visited;
            double ans = dfs(adj, visited, source, target, 1.0);
            result.push_back(ans);
        }
        return result;
    }
};