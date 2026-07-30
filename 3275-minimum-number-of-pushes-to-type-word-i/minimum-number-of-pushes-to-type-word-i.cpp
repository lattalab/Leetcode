class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        // only use 2~9
        unordered_map<int, vector<char>> keyboard;
        int start = 2;
        for (int i=0; i<word.size(); i++) {
            char c = word[i];
            if (!keyboard.count(c)) {
                keyboard[start].push_back(c);
                ans += keyboard[start].size();
                start++;
            }

            // reset
            if (start == 10) start = 2;
        }
        return ans;
    }
};