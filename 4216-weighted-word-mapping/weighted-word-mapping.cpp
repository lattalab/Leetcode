class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (int i=0; i<words.size(); i++) {
            int sum = 0;
            for (char ch : words[i]) {
                sum = (sum + weights[(ch - 'a')]) % 26;
            }
            ans += ('a' + 25-sum);
        }
        return ans;
    }
};