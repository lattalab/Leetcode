class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int vowel = 0;
        int left = 0;
        for (int right=0; right<s.size(); right++) {
            // expand
            vowel += (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u');

            // shrink
            if (right - left + 1 > k) {
                // exceed the length
                vowel -= (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u');
                left++;
            }
            
            // update ans
            ans = max(ans, vowel);
        }
        return ans;
    }
};