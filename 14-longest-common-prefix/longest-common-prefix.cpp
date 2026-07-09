class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pattern = strs[0];
        for (int i=1; i<strs.size(); i++) {
            string temp = "";
            for (int j=0; j<min(pattern.size(), strs[i].length()); j++) {
                if (pattern[j] == strs[i][j]) {
                    temp += pattern[j];
                }
                else {
                    break;
                }
            }
            pattern = temp;
        }
        return pattern;
    }
};