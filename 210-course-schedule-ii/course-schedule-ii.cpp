class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> dep;

        for (int i=0; i<prerequisites.size(); i++) {
            int s = prerequisites[i][1];
            int t = prerequisites[i][0];
            indegree[t]++;
            dep[s].push_back(t);
        }

        // 1. finding indegree = 0
        queue<int> q;
        for (int i=0; i<indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
                n--;
            }
        }

        // 2. bfs
        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                int target = q.front();
                q.pop();
                result.push_back(target);

                // simulate the deletion
                vector<int> nodes = dep[target];
                for (int j=0; j<nodes.size(); j++) {
                    indegree[nodes[j]]--;
                    if (indegree[nodes[j]] == 0) {
                        q.push(nodes[j]);
                        n--;
                    }
                }
            }
        }

        return (n == 0) ? result : vector<int>();
    }
};