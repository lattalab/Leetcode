class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int hash[26];
        for (int i=0; i<text.size(); i++) {
            hash[text[i] - 'a']++;
        }
        int b = hash[1];
        int a = hash[0];
        int l = hash['l' - 'a'] / 2;
        int o = hash['o' - 'a'] / 2;
        int n = hash['n' - 'a'];
        return min({a, b, l, o, n});
    }
};