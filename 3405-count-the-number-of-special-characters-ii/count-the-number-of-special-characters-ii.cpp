class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);
        for (int i=0; i<word.size(); i++) {
            if (islower(word[i])) {
                // store last occurance
                lower[word[i] - 'a'] = i;
            }
            if (isupper(word[i]) && upper[word[i] - 'A'] == -1) {
                // store first occurance
                upper[word[i] - 'A'] = i;
            }
        }

        int ans = 0;
        for (int i=0; i<26; i++) {
            if (upper[i] != -1 && lower[i] != -1 && upper[i] > lower[i]) {
                ans++;
            }
        }
        return ans;
    }
};