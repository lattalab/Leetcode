class Solution {
public:
    int lengthOfLastWord(string s) {
        // remove backward space
        int idx = s.length() - 1;
        while (idx > 0 && s[idx] == ' ') idx--;

        // traverse from the end
        int ans = 0;
        while (idx >= 0 && s[idx] != ' ') {
            ans++;
            idx--;
        }
        return ans;
    }
};