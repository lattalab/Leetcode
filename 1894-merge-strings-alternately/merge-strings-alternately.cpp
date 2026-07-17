class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i = 0;
        for (i ; i<min(word1.size(), word2.size()); i++) {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if (i < word1.size()) {
            ans += word1.substr(i);
        }
        if (i < word2.size()) {
            ans += word2.substr(i);
        }
        return ans;
    }
};