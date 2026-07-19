class Solution {
public:
    string smallestSubsequence(string s) {
        // record the last occurence
        int last[26];
        for (int i=0; i<s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        // examine whether in stack
        vector<bool> visited(26, false);    
        string st;

        for (int i=0; i<s.size(); i++) {
            // examine for already visited
            if (visited[s[i] - 'a'])
                continue;
            
            // Remove larger characters if they appear later
            while (!st.empty() && st.back() > s[i] && last[st.back() - 'a'] > i) {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }
        return st;
    }
};