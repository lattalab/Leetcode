class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, curr = 1;
        for (int i=1; i<s.size(); i++) {
            if (s[i] == s[i-1]) {
                curr += 1;
            }
            else {
                prev = curr;
                curr = 1;
            }
            // update ans
            if (prev >= curr) ans += 1;
        }
        return ans;
    }
};