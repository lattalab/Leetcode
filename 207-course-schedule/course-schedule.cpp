class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> dep;
        int n = numCourses;
        vector<int> indegree(n, 0);
        for (int i=0; i<prerequisites.size(); i++) {
            int s = prerequisites[i][1], t = prerequisites[i][0];
            dep[s].push_back(t);
            indegree[t]++;
        }

        // 1. finding indegree=0
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                numCourses--;
            }
        }

        // 2. bfs
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                int target = q.front();
                q.pop();
                // delete the related edge
                for (int j=0; j<dep[target].size(); j++) {
                    indegree[ dep[target][j] ]--;
                    if (indegree[ dep[target][j] ] == 0) {
                        q.push(dep[target][j]);
                        numCourses--;
                    }
                }
            }
        }

        return (numCourses == 0);
    }
};