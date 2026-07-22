class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // 1. calculate initial 1s
        int ones = 0;
        for (auto ch: s) ones += (ch == '1');

        // Run length encoding
        vector<pair<char, int>> blocks;
        for (char ch : s) {
            if (blocks.empty() || blocks.back().first != ch) {
                blocks.push_back({ch, 1});
            }
            else {
                blocks.back().second++;
            }
        }

        // flip
        int ans = ones;
        for (int i=1; i+1<blocks.size(); i++) {
            if (blocks[i-1].first == '0' && blocks[i].first == '1' && blocks[i+1].first == '0') {
                ans = max(ans, ones + blocks[i-1].second + blocks[i+1].second);
            }
        }

        return ans;
    }
};