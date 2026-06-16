class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (int i=0; i<s.size(); i++) {
            char ch = s[i];
            if (islower(ch)) {
                result += ch;
            }
            else if (ch == '*') {
                if (result.size())
                    result.pop_back();
            }
            else if (ch == '#') {
                result = result + result;
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};