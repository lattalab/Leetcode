class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26] = {0};
        int upper[26] = {0};
        for (int i=0; i<word.size(); i++) {
            if (isupper(word[i])) {
                upper[word[i] - 'A']++;
            }
            if (islower(word[i])) {
                lower[word[i] - 'a']++;
            }
        }

        // examine for the special
        int count = 0;
        for (int i=0; i<26; i++) {
            if (lower[i] && upper[i]) 
                count++;
        }
        return count;
    }
};