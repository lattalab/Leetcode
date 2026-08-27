class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;
    bool check(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++; right--;
        }
        return true;
    }
    void backtracking(string &s, int startIndex) {
        if (startIndex == s.size()) {
            ans.push_back(cur);
            return ;
        }

        for (int i=startIndex; i<s.size(); i++) {
            if (check(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                cur.push_back(str);
                backtracking(s, i+1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
};