class Solution {
public:
    string makeLargestSpecial(string s) {        
        // step 1. find balanced
        // - the problem description has made string will always more 1s than 0s
        int balanced = 0;
        int start = 0;          // finding substring start pos
        vector<string> blocks;  // store same level special blocks
        for (int i=0; i<s.size(); i++) {
            balanced += (s[i] == '1') ? 1: -1;
            if (balanced == 0) {
                // step 2. recusively divide and conquer
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                blocks.push_back("1" + inner + "0");
                start = i + 1;  // next starting pos
            }
        }
        // step 3. sort to make local greedily
        sort(blocks.begin(), blocks.end(), greater<string>());
        // step 4. combine
        string results;
        for (auto str : blocks) {
            results += str;
        }
        return results;
    }
};