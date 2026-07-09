class Solution {
public:
    int lengthOfLastWord(string s) {
        // remove backward space
        int idx = s.length() - 1;
        while (idx > 0 && s[idx] == ' ') idx--;
        s.resize(idx);

        int ans = 0;
        for (int i=0; i<=idx; i++) {
            if (s[i] == ' ') {
                ans = 0;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};