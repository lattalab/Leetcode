class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char, char> mp;
        for (int i=0; i<s.length(); i++) {
            // connect each two characters
            if (mp.find(s[i]) == mp.end()) {
                // remove repetive connected in t
                for (auto dest: mp) {
                    if (dest.second == t[i]) {
                        return false;
                    }
                }
                mp[s[i]] = t[i];
            }
            // s encounter same character in map
            char mapped = mp[s[i]];
            if (mapped != t[i]) return false; 
        } 
        return true;
    }
};