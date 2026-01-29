class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Floyd-Warshall
        long long dist[26][26];
        long long INF = 1e7;

        // 1. create distance matrix
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                if (i==j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        // 2: transfer cost into weight and modify character into index
        for (int i=0; i<original.size(); i++) {
            int row = original[i] - 'a';
            int col = changed[i] - 'a';
            dist[row][col] = min(dist[row][col], (long long)cost[i]);
        }

        // 3. O(n^3) approach
        for (int k=0; k<26; k++) {
            for (int i=0; i<26; i++) {
                for (int j=0; j<26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // 4. get result
        long long ans = 0;
        for (int i=0; i<source.size(); i++) {
            int row = source[i] - 'a';
            int col = target[i] - 'a';
            if (dist[row][col] == INF) return -1;
            ans += dist[row][col];
        }
        return ans;

    }
};