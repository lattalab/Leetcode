class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26];      // calculate frequency
        int maxFreq = 0;    // finding maximum freq will release the effort to replace
        int ans = 0;        // record ans
        int start = 0;      // start point of silding window
        for (int end = 0; end<s.size(); end++) {
            freq[s[end]-'A']++;
            maxFreq = max(maxFreq, freq[s[end]-'A']);
            // current window length
            // int winLength = end - start + 1;
            // when exceed replace times, shrinking window
            while ((end - start + 1) - maxFreq > k) {
                freq[s[start]-'A']--;
                start++;
            }
            // update ans
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};