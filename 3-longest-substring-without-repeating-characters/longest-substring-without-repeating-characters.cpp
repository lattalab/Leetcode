class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right =0;
        int maxLength = 0;
        unordered_map<char, int> table;
        for ( right = 0; right<s.size(); right++) {
            
            // see if reappear again by checking hash
            while (table[ s[right] ] > 0) {
                table[ s[left] ]--;
                left += 1;
            }

            table[ s[right] ]++;
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};