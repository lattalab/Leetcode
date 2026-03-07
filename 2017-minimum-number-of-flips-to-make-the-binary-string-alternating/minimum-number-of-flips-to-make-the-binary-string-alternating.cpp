class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int diff = 0;
        int diff2 = 0;

        int l = 0;
        int ans = n;

        for (int r=0; r<2*n; r++) {
            char ch = s[r%n];
            // difference for pattern 0101
            char p1 = (r%2 == 0) ? '0' : '1';
            diff += (ch != p1);
            // difference for pattern 1010
            char p2 = (r%2 == 0) ? '1' : '0';
            diff2 += (ch != p2);

            if (r - l + 1 > n) {
                char left = s[l%n];
                // exit difference for pattern 0101
                char lp1 = (l%2 == 0) ? '0' : '1';
                diff -= (left != lp1);
                // exit difference for pattern 1010
                char lp2 = (l%2 == 0) ? '1' : '0';
                diff2 -= (left != lp2);
                // update left pointer
                l++;
            }
            if (r - l + 1 == n) {
                ans = min(ans, min(diff, diff2));
            }
        }
        return ans;
    }
};