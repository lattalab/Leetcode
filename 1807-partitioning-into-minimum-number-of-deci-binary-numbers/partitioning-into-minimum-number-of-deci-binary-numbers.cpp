class Solution {
public:
    int minPartitions(string n) {
        // each digit at least need such many 1
        int ans = 0;
        for (int i=0; i<n.size(); i++) {
            ans = max(ans, n[i] - '0');
        }
        return ans;
    }
};