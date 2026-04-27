class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // deparse the string
        vector<string> words;
        string word;
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
            word.clear();
        }
        
        // size mismatch
        if (words.size() != pattern.length())
            return false;
        
        map<char, string> ps;
        map<string, char> sp;
        
        int idx = 0;
        for (int i=0; i<pattern.size(); i++) {
            char ch = pattern[i];
            string cur = words[i];

            if (ps.count(ch)) {
                if (ps[ch] != cur) return false;
            } else {
                ps[ch] = cur;
            }

            if (sp.count(cur)) {
                if (sp[cur] != ch) return false;
            } else {
                sp[cur] = ch;
            }
        }
        return true;
    }
};