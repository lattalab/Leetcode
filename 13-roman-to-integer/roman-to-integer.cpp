class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int num = 0;
        for (int i=0; i<s.size(); i++){
            int curr = table[s[i]];

            // before access next character, check if it is valid index
            int next;
            if (i+1 < s.size()) next = table[s[i+1]];
            else next = -1;

            if (next > curr) {
                num += (next-curr);
                i++;    // move to next character
            } else {
                num += curr;
            }
        }   // end for

        return num;
    }
};