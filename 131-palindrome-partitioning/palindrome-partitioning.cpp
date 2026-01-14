class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool palindrome (string &s, int start, int end) {
        while (start >= 0 && end < s.size() && start <= end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void backtracking (string &s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return ;
        }
        for (int i=startIndex; i<s.size(); i++) {
            // check if valid palindrome
            if (palindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {
                continue;
            }
            
            backtracking(s, i+1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        backtracking(s, 0);
        return result;
    }
};