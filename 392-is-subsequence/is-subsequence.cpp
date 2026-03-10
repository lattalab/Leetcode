class Solution {
public:
    bool isSubsequence(string s, string t) {
        int origin = 0;
        int target = 0;
        for (int i=0; i<t.size(); i++) {
            if (t[i] == s[origin]) {
                origin++;
                target++;
            }
        }
        return target == s.size();
    }
};