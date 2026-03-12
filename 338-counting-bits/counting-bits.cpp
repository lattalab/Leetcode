class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        if (n >= 0)
            dp[0] = 0;
        if (n >= 1)
            dp[1] = 1;

        int len = 1;
        for (int i=2; i<=n; i++) {
            // find power of 2
            if (i == (1 << len)) {
                len++;
            }
            // it will repeat last round of 'power of 2'
            int rep = (1 << (len-1));
            dp[i] = 1 + dp[i-rep];
        }
        return dp;
    }
};
