class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        // 1. reocrd farest index among the character
        map<int, int> mp;
        for (int i=0; i<s.size(); i++) {
            mp[s[i]] = i;
        }
        // 2. find interval
        int start = 0;
        int end = 0;
        for (int i=0; i<s.size(); i++) {
            end = max(end, mp[s[i]]);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};