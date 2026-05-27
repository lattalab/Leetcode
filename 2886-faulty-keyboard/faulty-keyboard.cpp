class Solution {
public:
    void reverse(string &s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string finalString(string s) {
        string ans;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'i') {
                reverse(ans);
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};