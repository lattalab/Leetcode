class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        
        int len = s.size();
        int left = 0, right = 0;
        int freq[3] = {0};
        while (right < len) {
            // increment current characters
            freq[s[right] - 'a']++;
            // contain occurrence
            while (freq[0] && freq[1] && freq[2]) {
                ans += len - right;
                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return ans;
    }
};