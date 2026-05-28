class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(numRows);
        int curRow = 0;
        int dist = 0;
        for (int i=0; i<s.size(); i++) {
            char ch = s[i];
            rows[curRow] += ch;

            if (curRow == 0) {
                // each time, going down plus 1
                dist = 1;
            }
            else if (curRow == numRows-1) {
                // each time, going up minus -1
                dist = -1;
            }
            // increment
            curRow += dist;
        }

        string ans;
        for (auto row : rows) {
            ans += row;
        }
        return ans;
    }
};